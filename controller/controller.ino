#include <ESP8266WiFi.h>
#include "WifiSettings.h"    
#include "DHT.h"


#define LED D0 //LED PORT

//DHT dht = DHT(D1, DHT11, 6); // DHT(uint8_t pin, uint8_t type, uint8_t count=6);
DHT dht;
int wifiStatus;

void setup() {
  
   pinMode(LED, OUTPUT); // Port aus Ausgang schalten

   dht.setup(D1);   /* D1 is used for data communication */
 
   Serial.begin(115200);
   delay(200);   

   connectWifi();

   Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)");

    
}

void loop() {
      checkWifi();
      checkValues();
      delay(10000);
}


void checkWifi() {
  
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
      connectWifi();
    }  
 }

 void connectWifi()  {
  
      // We start by connecting to a WiFi network     
      Serial.println();
      Serial.println();
      Serial.print("Your are connecting to;");
      Serial.println(ssid);
      
      WiFi.begin(ssid, password);
      
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        digitalWrite(LED, HIGH); //Led port einschlaten
        delay(500);
        digitalWrite(LED, LOW); //Led port ausschlaten
        
        Serial.print(".");
      }
   }

  void checkValues(){
     delay(dht.getMinimumSamplingPeriod()); /* Delay of amount equal to sampling period */
      float humidity = dht.getHumidity();/* Get humidity value */
      float temperature = dht.getTemperature();/* Get temperature value */
      Serial.print(dht.getStatusString());/* Print status of communication */
      Serial.print("\t");
      Serial.print(humidity, 1);
      Serial.print("\t\t");
      Serial.print(temperature, 1);
      Serial.print("\t\t");
 
  }
