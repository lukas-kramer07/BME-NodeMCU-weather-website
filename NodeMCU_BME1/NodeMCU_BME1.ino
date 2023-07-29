  /*********
  Code for main_NodeMCU hosting the website
*********/

// Library and heaeder file import
#include <ESP8266WiFi.h>  //WiFi Library
#include <ESPAsyncTCP.h>  //Libraries for Async Webserver
#include <ESPAsyncWebSrv.h>
#include <BME280I2C.h>    //BME Libraries 
#include <Wire.h>
#include <ThingSpeak.h>   //ThingSpeak Library
#include "html_code_1.h"        //html code
#include "Network_1.h"     //network password and SSid
AsyncWebServer server(80);  //Webserver hosted on Port 80 (HTTP) 
BME280I2C bme;            // I2C protocoll 
WiFiClient client;

//network password and SSid for local Netwerk
String ssid = SSId;
String passwort = PASSWORD;

//network password and SSid for HotSpot
const char* ssid_HotSpot = "";   // Enter SSID here
const char* password_HotSpot = ""; // Enter Password here

//Apikey and channelId for ThingSpeak Upload
unsigned long channelID = _;
const char*  writeAPIKey = "";


//variables for Millis Timer
const long Minute = 60000;
long Reset = 0;

//========================================================================================================================================================================================================

//Website BME request
String Request_BME(String Wert) {
    float Pressure, Temp, Humidity;
    bme.read(Pressure, Temp, Humidity);
    float RWert;
    if(Wert == "Temperature_BME1"){
      RWert = Temp;
      }
    else if(Wert == "Pressure_BME1"){
      RWert = Pressure;
    }
    else if(Wert == "Humidity_BME1"){
      RWert = Humidity;
    }
    else if(Wert == "rssi_BME1"){
      RWert = WiFi.RSSI();
      Serial.println(WiFi.RSSI());
      Serial.println(String(RWert));
    }
  return String(RWert);
}

//BME-values onload
String values_onload(const String& var){
  if(var == "Temperature_BME1"){
    return Request_BME("Temperature_BME1");
  }
  else if(var == "Humidity_BME1"){
    return Request_BME("Humidity_BME1");
  }
  else if(var == "Pressure_BME1"){
    return Request_BME("Pressure_BME1");
  }
  else if(var == "rssi_BME1"){
    return String(WiFi.RSSI());
  }
  return String();
}
//========================================================================================================================================================================================================

//Thingspeak upload
void Upload_BME(){
  float Pressure, Temp, Humidity;
  bme.read(Pressure, Temp, Humidity);
  long rssi = WiFi.RSSI();
  ThingSpeak.setField(1,rssi);
  ThingSpeak.setField(2,Temp);
  ThingSpeak.setField(3,Pressure);
  ThingSpeak.setField(4,Humidity);
  int x = ThingSpeak.writeFields(channelID, writeAPIKey);
  if (x == 200) {
    Serial.println("Die values wurden erfolgreich uebertragen.");
  }
  else {
    Serial.println("Fehler bei der Uebertragung. Fehlercode " + String(x));
  }

}

//========================================================================================================================================================================================================
// Initialization and connection
void Initialization(){
  
  Serial.begin(115200);

  Wire.begin(D2,D1);    // I2C protocoll started with SDA, SCL 

  while(!bme.begin())   // waiting for BME connection
  {
    Serial.println("BME280 nicht gefunden!");
    delay(1000);
  }
  
  // Connect to Wi-Fi
  ThingSpeak.begin(client);
  WiFi.begin(ssid, passwort);                     
  while (WiFi.status() != WL_CONNECTED) { //waiting for WIFI connection
   delay(1000);
   Serial.println("...");
  }
  
   Serial.println("erstelle HotSpot");
   WiFi.softAP(ssid_HotSpot, password_HotSpot); // starting HotSpot with SSID and password
   Serial.println(WiFi.localIP());
}


//========================================================================================================================================================================================================

void setup(){
  Initialization();
  
  //Rwebsite load route, html code and BME values are sent
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, values_onload);
  });


  //Get method routes for BME value requests
  server.on("/Temperature_BME1", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", Request_BME("Temperature_BME1").c_str());
  });
  server.on("/Humidity_BME1", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", Request_BME("Humidity_BME1").c_str());
  });
  server.on("/Pressure_BME1", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", Request_BME("Pressure_BME1").c_str());
  });
  server.on("/rssi_BME1", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", Request_BME("rssi_BME1").c_str());
  });

  //starting the Webserver
  server.begin();
}



//========================================================================================================================================================================================================
void loop()
{
  //uploading to Thingspeak every 10 min
  if(millis() > Minute*10 + Reset){
    Serial.println("Beginn");
    Reset = millis();
    Upload_BME(); 
  }
}
