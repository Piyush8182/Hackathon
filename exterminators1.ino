#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"

 
#define Relay1            D1
#define Relay2            D2
#define Relay3            D3 
#define Relay4            D4
 
#define WLAN_SSID       "hotspot"             // Your SSID
#define WLAN_PASS       "8182064151"         //  Your password
 
/************************* Ada+ruit768768tup *********************************/ 
 
#define AIO_SERVER      "io.adafruit.com" 
#define AIO_SERVERPORT  1883                   // use 8883 for SSL 
#define AIO_USERNAME    "piyush8182"            // Replace it with your username
#define AIO_KEY         "aio_gqhN95yLE3Y78hdWIt9GTOjJ23YS"   // Replace with your Project Auth Key 
 
/************ Global State (you don't need to change this!) ******************/ 
 
// Create an ESP8266 WiFiClient class to connect to the MQTT server.
WiFiClient client; 
// or... use WiFiFlientSecure for SSL 
//WiFiClientSecure client; 
 
// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY); 
 
/****************************** Feeds ***************************************/ 
 
 
// Setup a feed called 'onoff' for subscribing to changes. 

 
 
Adafruit_MQTT_Subscribe Rel1 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME"/feeds/light1"); // FeedName
Adafruit_MQTT_Subscribe Rel2 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/light2");
Adafruit_MQTT_Subscribe Rel3 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/light3");
Adafruit_MQTT_Subscribe Rel4 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/fan");
 
void MQTT_connect(); 
 
void setup() 
{  
  Serial.begin(115200); 
 
  pinMode(Relay1, OUTPUT); 
  pinMode(Relay2, OUTPUT); 
  pinMode(Relay3, OUTPUT); 
  pinMode(Relay4, OUTPUT); 
  Serial.println(F("Adafruit MQTT demo")); 
  // Connect to WiFi access point. 
  Serial.println();
  Serial.println(); 
  Serial.print("Connecting to ");