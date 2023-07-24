# NodeMCU Project with BMI Sensors and Weather App

This project involves displaying BMI data from two NodeMCUs with BMI sensors. The first NodeMCU acts as the main Node and hosts the web server, displaying the BMI data. This NodeMCU also uses the OpenWeather API to display weather data for any city searched by the user. Additionally, the user can get cat pictures through another API and change the background and the city of which the weather data is displayed on the home screen in the settings.

The second NodeMCU connects to the internet and uploads its BMI data to ThingSpeak, where the first NodeMCU can obtain it using the ThingSpeak API. By copying the used concepts, more Nodes can be added.



## Features (website)

Displays current weather information such as temperature, humidity, pressure, wind speed, and weather description.
User can enter the name of a city and country code to get the weather information.
User can save a custom background image for the app.
Responsive design for mobile and desktop devices.
Automatically updates the weather information every 20 seconds.


## Technologies Used
This project uses the following technologies:

NodeMCU
BME280 sensor
ESPAsyncWebServer library
ESP8266WiFi library
ThingSpeak API
OpenWeather API
HTML, CSS, and JavaScript (for the web interface)

## Installation
To install this project, follow these steps:

Connect the BMI sensor to each NodeMCU.
Upload the Node_1 code to the first NodeMCU and the Node_2 code to the second NodeMCU using the Arduino IDE. To do this, you'll have to [add the nodeMCU to your Boardmanager](https://www.electronicwings.com/nodemcu/getting-started-with-nodemcu-using-arduino-ide).

Create accounts and obtain API keys for the OpenWeather and ThingSpeak APIs.
Set up a WiFi network and connect both NodeMCUs to it.
Modify the Node_1 code with your WiFi network SSID and password, hotspot SSID and password, ThingSpeak channel ID and write API key, and OpenWeather API key.
Update the web interface HTML, CSS, and JavaScript files with your own design and functionality if desired.

## Usage
To use this project, follow these steps:

Access the IP address of the first NodeMCU to view the web server.
Enter the name of the city and the country code in the input fields provided.
Click on the "Search" button to fetch the current weather information for the specified location.
Optionally, save a custom background image by clicking on the "Settings" button, selecting an image URL or a preset image, and clicking on the "Save" button.
To return to the weather information screen, click on the "Weather App" button in the navigation bar.
The app will automatically update the weather information every 20 seconds.

## Node_1 Code (Arduino)

The Node_1 code handles the main Node that hosts the web server.

The code imports the following libraries and header files:
```
ESP8266WiFi.h: WiFi Library
ESPAsyncTCP.h: Libraries for the Asynchronous Webserver
ESPAsyncWebServer.h
BME280I2C.h: BME Libraries
Wire.h
ThingSpeak.h: ThingSpeak Library
html_code.h: HTML code
Netzwerk_1.h: Network password and SSID
The web server is hosted on port 80 (HTTP).
```

The code initializes the following variables:

```
ssid and password for the local network
ssid_HotSpot and password_HotSpot for the hotspot
channelID and writeAPIKey for the ThingSpeak upload
Minute and Reset for the millis timer
```

The code contains the following functions:

```
Abfrage_BME(String Wert): This function queries the BME values for the webpage. It reads the temperature, pressure, and humidity values using the BME sensor and returns the requested value.
werte_onload(const String& var): This function returns the BME values when the webpage loads. It calls the Abfrage_BME function and returns the requested value.
Upload_BME(): This function uploads the BME values to ThingSpeak. It reads the temperature, pressure, and humidity values using the BME sensor and the RSSI value using the WiFi library. It sets the fields on ThingSpeak and writes the values. It outputs a message if the upload is successful or if there is an error.
```
The code initializes the following function:
```
Initialisierung(): This function initializes the sensors, connects to the WiFi network, and creates a hotspot with a predefined SSID and password. It outputs the IP address of the hotspot.
The setup() function calls the Initialisierung() function.
```

## Node_2 Code (Arduino)
The Node_2 code handles the secondary Node that uploads BME sensor data to ThingSpeak.

The code imports the following libraries and header files:
```
ESP8266WiFi.h: WiFi Library
ESPAsyncTCP.h: Libraries for the Asynchronous Webserver
ESPAsyncWebServer.h
BME280I2C.h: BME Libraries
Wire.h
ThingSpeak.h: ThingSpeak Library
Netzwerk_2.h: Network password and SSID
```
The code initializes the following variables:

```
ssid and password for the local network
channelID_neben and writeAPIKey_neben for uploading BME sensor data to a secondary ThingSpeak channel
channelID_haupt and writeAPIKey_haupt for uploading BME sensor data to the main ThingSpeak channel
Reset_neben and Reset_haupt for the millis timer
```
The code contains the following functions:

```
Upload_BME(String Channel): This function reads BME sensor data and WiFi RSSI values and uploads them to either the secondary or main ThingSpeak channels based on the Channel parameter passed to it. 
It sets the fields on ThingSpeak and writes the values. It outputs a message if the upload is successful or if there is an error.
```

The code initializes the following function:
```
Initialisierung(): This function initializes the sensors, connects to the WiFi network, and initializes the ThingSpeak client. It outputs a message when it is finished with the initialization.
The setup() function calls the Initialisierung() function.
```


The code uses two separate channels to upload data to ThingSpeak. The secondary channel is used to upload data every 20 seconds, so it can be accessed by the webserver for display. The main channel is used to upload data every 10 minutes. The millis timer is used to keep track of the last time each channel was uploaded to. The BME sensor data is read and uploaded using the ThingSpeak library. If the upload is successful, the code outputs a success message, and if it fails, it outputs an error message.
