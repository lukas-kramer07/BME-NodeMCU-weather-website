  /*********
  Code für den Haupt_NodeMCU, der die Webseite hostet
*********/

// Import der benötigten libraries und header Dateien
#include <ESP8266WiFi.h>  //WiFi Library
#include <ESPAsyncTCP.h>  //Libraries für den Asynchronen Webserver
#include <ESPAsyncWebServer.h>
#include <BME280I2C.h>    //BME Libraries 
#include <Wire.h>
#include <ThingSpeak.h>   //ThingSpeak Library
#include "index_1.h"        //html code
#include "Netzwerk_1.h"     //Netwerkpasswort und ssid
AsyncWebServer server(80);  //Webserver wird auf Port 80 (HTTP) gehostet
BME280I2C bme;            // Es wird das I2C Protokoll verwendet. 
WiFiClient client;

//ssid und Passwort für lokales Netwerk
String ssid = SSId;
String passwort = PASSWORT;

//ssid und Passwort für HotSpot
const char* ssid_HotSpot = "HotSpot Konrad Lukas";   // Enter SSID here
const char* password_HotSpot = "123456"; // Enter Password here

//Apikey und channelId für ThingSpeak Upload
unsigned long channelID = 1724531;
const char*  writeAPIKey = "JXI43S3GAKRCG9HY";


//variabeln für Millis Timer
const long Minute = 60000;
long Reset = 0;

//========================================================================================================================================================================================================

//Abfrage der BME-Werte für die Webseite
String Abfrage_BME(String Wert) {
    float Druck, Temp, Feuchte;
    bme.read(Druck, Temp, Feuchte);
    float RWert;
    if(Wert == "Temperatur_BME1"){
      RWert = Temp;
      }
    else if(Wert == "Druck_BME1"){
      RWert = Druck;
    }
    else if(Wert == "Feuchte_BME1"){
      RWert = Feuchte;
    }
    else if(Wert == "rssi_BME1"){
      RWert = WiFi.RSSI();
      Serial.println(WiFi.RSSI());
      Serial.println(String(RWert));
    }
  return String(RWert);
}

//BME-Werte beim Laden der Webseite
String werte_onload(const String& var){
  if(var == "Temperatur_BME1"){
    return Abfrage_BME("Temperatur_BME1");
  }
  else if(var == "Feuchte_BME1"){
    return Abfrage_BME("Feuchte_BME1");
  }
  else if(var == "Druck_BME1"){
    return Abfrage_BME("Druck_BME1");
  }
  else if(var == "rssi_BME1"){
    return String(WiFi.RSSI());
  }
  return String();
}
//========================================================================================================================================================================================================

//Upload der BME-Werte auf ThingSpeak 
void Upload_BME(){
  float Druck, Temp, Feuchte;
  bme.read(Druck, Temp, Feuchte);
  long rssi = WiFi.RSSI();
  ThingSpeak.setField(1,rssi);
  ThingSpeak.setField(2,Temp);
  ThingSpeak.setField(3,Druck);
  ThingSpeak.setField(4,Feuchte);
  int x = ThingSpeak.writeFields(channelID, writeAPIKey);
  if (x == 200) {
    Serial.println("Die Werte wurden erfolgreich uebertragen.");
  }
  else {
    Serial.println("Fehler bei der Uebertragung. Fehlercode " + String(x));
  }

}

//========================================================================================================================================================================================================
//Initialisierung und Verbindungsherstellung
void Initialisierung(){
  
  Serial.begin(115200);

  Wire.begin(D2,D1);    // I2C Protokoll wird mit SDA, SCL gestartet

  while(!bme.begin())   // Der Programmablauf wartet, bis der bme gefunden wurde
  {
    Serial.println("BME280 nicht gefunden!");
    delay(1000);
  }
  
  // Connect to Wi-Fi
  ThingSpeak.begin(client);
  WiFi.begin(ssid, passwort);                     
  while (WiFi.status() != WL_CONNECTED) { //Der Programmablauf wartet, bis eine WiFi-Verbindung hergestelt wurde
   delay(1000);
   Serial.println("...");
  }
  
   Serial.println("erstelle HotSpot");
   WiFi.softAP(ssid_HotSpot, password_HotSpot); // Startet den HotSpot mit der SSID und dem Passwort
   Serial.println(WiFi.localIP());
}


//========================================================================================================================================================================================================

void setup(){
  Initialisierung();
  
  //Route beim Laden der Webseite, BME-Werte und html-code werden zurückgegeben
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, werte_onload);
  });


  //Routen für die Get-Methoden für die BME-Werte, welche über Abfrage_BME()ermittelt werden
  server.on("/Temperatur_BME1", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", Abfrage_BME("Temperatur_BME1").c_str());
  });
  server.on("/Feuchte_BME1", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", Abfrage_BME("Feuchte_BME1").c_str());
  });
  server.on("/Druck_BME1", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", Abfrage_BME("Druck_BME1").c_str());
  });
  server.on("/rssi_BME1", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", Abfrage_BME("rssi_BME1").c_str());
  });

  //Webserver wird gestartet
  server.begin();
}



//========================================================================================================================================================================================================
void loop()
{
  //Alle 10 Minuten werden die Werte auf ThingSpeak hochgeladen
  if(millis() > Minute*10 + Reset){
    Serial.println("Beginn");
    Reset = millis();
    Upload_BME(); 
  }
}
