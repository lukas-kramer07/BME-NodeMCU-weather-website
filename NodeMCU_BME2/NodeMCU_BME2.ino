
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
String password = PASSWORD;      


//---------------------------------------------------------------------------------------------
// Apikey and channelId for ThingSpeak Upload
unsigned long channelID_secondary = ;
const char*  writeAPIKey_secondary = "";
unsigned long channelID_main = ;
const char*  writeAPIKey_main = "";





  
//---------------------------------------------------------------------------------------------
// variables for Millis Timer
const long Minute = 60000;
long Reset_secondary = 0;
long Reset_main = 0;


void setup() {
  delay(100);
  Initialization();
}

//---------------------------------------------------------------------------------------------
void loop()
{
  // uploading to Thingspeak main channel every 10 min
  if(millis() > Minute*10 + Reset_main){
    Serial.println("Beginn");
    Reset_main = millis();
    Upload_BME("main"); 
  }
  // uploading to Thingspeak secondary channel every 20 sec. The website will request these values
  if(millis() > Minute*0.3 + Reset_secondary){
    Serial.println("Beginn");
    Reset_secondary = millis();
    Upload_BME("secondary"); 
  }
}

  
//---------------------------------------------------------------------------------------------
// Thingspeak Upload
void Upload_BME(String Channel){
  float Pressure, Temp, Humidity;
  bme.read(Pressure, Temp, Humidity);
  long rssi = WiFi.RSSI();
  int x;
  // Secondary channel
  if(Channel == "secondary"){
    ThingSpeak.setField(1, rssi);
    ThingSpeak.setField(2,Temp);
    ThingSpeak.setField(4,Pressure);
    ThingSpeak.setField(3,Humidity);
    x = ThingSpeak.writeFields(channelID_secondary, writeAPIKey_secondary);
  }
  // Main channel
  else if(Channel == "main"){
    ThingSpeak.setField(5, rssi);
    ThingSpeak.setField(6,Temp);
    ThingSpeak.setField(7,Pressure);
    ThingSpeak.setField(8,Humidity);
    x = ThingSpeak.writeFields(channelID_main, writeAPIKey_main);
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
void Initialization(){
  Serial.begin(9600);
  Wire.begin(D2,D1);
  ThingSpeak.begin(client);
  WiFi.begin(ssid, password);
  Serial.println("Initialization");
  Serial.print("Wifi connection...");
  while (WiFi.status() != WL_CONNECTED) { // wating for WIFI
    delay(500);
    Serial.print(".");
  };
  Serial.println("connected.");
  delay(1000);
  while(!bme.begin())   // waiting for BME
  {
    Serial.println("BME280 not found!");
    delay(1000);

  }
}
