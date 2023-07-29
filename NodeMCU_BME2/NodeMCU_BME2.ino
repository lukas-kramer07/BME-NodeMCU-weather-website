
/*********
   Code for scondary_NodeMCU uploading the BME values
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
// password and SSid for local network
String ssid = SSId;
String passwort = PASSWORT;      


//---------------------------------------------------------------------------------------------
// Apikey and channelId for ThingSpeak Upload
unsigned long channelID_neben = ;
const char*  writeAPIKey_neben = "";
unsigned long channelID_haupt = ;
const char*  writeAPIKey_haupt = "";





  
//---------------------------------------------------------------------------------------------
// variables for Millis Timer
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
  // uploading to Thingspeak main channel every 10 min
  if(millis() > Minute*10 + Reset_haupt){
    Serial.println("Beginn");
    Reset_haupt = millis();
    Upload_BME("haupt"); 
  }
  // uploading to Thingspeak secondary channel every 20 sec. The website will request these values
  if(millis() > Minute*0.3 + Reset_neben){
    Serial.println("Beginn");
    Reset_neben = millis();
    Upload_BME("neben"); 
  }
}

  
//---------------------------------------------------------------------------------------------
// Thingspeak Upload
void Upload_BME(String Channel){
  float Druck, Temp, Feuchte;
  bme.read(Druck, Temp, Feuchte);
  long rssi = WiFi.RSSI();
  int x;
  // Secondary channel
  if(Channel == "neben"){
    ThingSpeak.setField(1, rssi);
    ThingSpeak.setField(2,Temp);
    ThingSpeak.setField(4,Druck);
    ThingSpeak.setField(3,Feuchte);
    x = ThingSpeak.writeFields(channelID_neben, writeAPIKey_neben);
  }
  // Main channel
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
// Initialization and connection 
void Initialisierung(){
  Serial.begin(9600);
  Wire.begin(D2,D1);
  ThingSpeak.begin(client);
  WiFi.begin(ssid, passwort);
  Serial.println("Initialisierung");
  Serial.print("Versuche eine WLAN-Verbindung herzustellen...");
  while (WiFi.status() != WL_CONNECTED) { // wating for WIFI
    delay(500);
    Serial.print(".");
  };
  Serial.println("hergestellt.");
  delay(1000);
  while(!bme.begin())   // waiting for BME
  {
    Serial.println("BME280 nicht gefunden!");
    delay(1000);

  }
}
