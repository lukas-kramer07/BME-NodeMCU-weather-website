
/*********
   Hauptprogramm für den Neben-NodeMCU, der die Werte von BME2 hochlädt
*********/


//libraries
//---------------------------------------------------------------------------------------------
#include <ESP8266WiFi.h>  //WiFi Library
  
#include <ThingSpeak.h> //ThingSpeak Library
#include <Wire.h>    //BME Libraries 
#include <BME280I2C.h>
#include <Wire.h>
#include "Network_2.h"
WiFiClient client;
BME280I2C bme;

//---------------------------------------------------------------------------------------------
//ssid und Passwort für lokales Netwerk
String ssid = SSId;
String passwort = PASSWORT;      


//---------------------------------------------------------------------------------------------
//Apikey und channelId für ThingSpeak Upload
unsigned long channelID_neben = ;
const char*  writeAPIKey_neben = "";
unsigned long channelID_haupt = ;
const char*  writeAPIKey_haupt = "";





  
//---------------------------------------------------------------------------------------------
//variabeln für Millis Timer
const long Minute = 60000;
long Reset_neben = 0;
long Reset_haupt = 0;


void setup() {
  delay(100);
  Initialisierung();
}

//---------------------------------------------------------------------------------------------
void loop()
{
  //Alle 10 Minuten werden die Werte auf den Hauptchannel hochgeladen
  if(millis() > Minute*10 + Reset_haupt){
    Serial.println("Beginn");
    Reset_haupt = millis();
    Upload_BME("haupt"); 
  }
  //Alle 20 Sekunden werden die Werte auf einen Nebenchannel geladen, damit sie von der Webseite abgerufen werden können
  if(millis() > Minute*0.3 + Reset_neben){
    Serial.println("Beginn");
    Reset_neben = millis();
    Upload_BME("neben"); 
  }
}

  
//---------------------------------------------------------------------------------------------
//upload der Daten auf ThingSpeak
void Upload_BME(String Channel){
  float Druck, Temp, Feuchte;
  bme.read(Druck, Temp, Feuchte);
  long rssi = WiFi.RSSI();
  int x;
  //Nebenchannel
  if(Channel == "neben"){
    ThingSpeak.setField(1, rssi);
    ThingSpeak.setField(2,Temp);
    ThingSpeak.setField(4,Druck);
    ThingSpeak.setField(3,Feuchte);
    x = ThingSpeak.writeFields(channelID_neben, writeAPIKey_neben);
  }
  //Hauptchannel
  else if(Channel == "haupt"){
    ThingSpeak.setField(5, rssi);
    ThingSpeak.setField(6,Temp);
    ThingSpeak.setField(7,Druck);
    ThingSpeak.setField(8,Feuchte);
    x = ThingSpeak.writeFields(channelID_haupt, writeAPIKey_haupt);
  }
  if (x == 200) {
    Serial.println("Die Werte wurden erfolgreich uebertragen.");
  }
  else {
    Serial.println("Fehler bei der Uebertragung. Fehlercode " + String(x));
  }

}

//---------------------------------------------------------------------------------------------
//Initialisierung und Verbindungsherstellung 
void Initialisierung(){
  Serial.begin(9600);
  Wire.begin(D2,D1);
  ThingSpeak.begin(client);
  WiFi.begin(ssid, passwort);
  Serial.println("Initialisierung");
  Serial.print("Versuche eine WLAN-Verbindung herzustellen...");
  while (WiFi.status() != WL_CONNECTED) { //Der Programmablauf wartet, bis eine WiFi-Verbindung hergestelt wurde
    delay(500);
    Serial.print(".");
  };
  Serial.println("hergestellt.");
  delay(1000);
  while(!bme.begin())   // Der Programmablauf wartet, bis der bme gefunden wurde
  {
    Serial.println("BME280 nicht gefunden!");
    delay(1000);

  }
}
