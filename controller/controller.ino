#include <ESP8266WiFi.h>
#include "WifiSettings.h"    
   

int wifiStatus;



#define LED D0 //LED PORT

void setup() {
 pinMode(LED, OUTPUT); // Port aus Ausgang schalten
 
       Serial.begin(115200);\
      delay(200);
      
     
     
      // We start by connecting to a WiFi network
     
      Serial.println();
      Serial.println();
      Serial.print("Your are connecting to;");
      Serial.println(ssid);
      
      WiFi.begin(ssid, password);
      
      while (WiFi.status() != WL_CONNECTED) {
        delay(250);
        digitalWrite(LED, HIGH); //Led port einschlaten
        delay(250);
        digitalWrite(LED, LOW); //Led port einschlaten
        
        Serial.print(".");
      }


 
 }

void loop() {
 digitalWrite(LED, LOW); //Led port ausschalten
 delay(10000); //1 Sek Pause
 
 delay(1000);

 wifiStatus = WiFi.status();

 if(wifiStatus == WL_CONNECTED){
    Serial.println("");
    Serial.println("Your ESP is connected!");  
    Serial.println("Your IP address is: ");
    Serial.println(WiFi.localIP());  
    }
  else{
    Serial.println("");
    Serial.println("WiFi not connected");
    }
  delay(1000); // check for connection every once a second

 
 }
