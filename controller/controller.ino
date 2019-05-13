
/*
 NodeMCU-BlinkendeLED
 Led an dem Modul ESP8266 bzw. Board NodeMCU blinken lassen
 Programm erprobt ab Arduino IDE 1.6.13
 Weitere Beispiele unter https://www.mikrocontroller-elektronik.de/
 */

#define LED D0 //GPIO16 Interne Led auf dem NodeMCU Board 
               //oft auch bereits als LED_BUILTIN definiert
               //man koennte auch schreiben #define LED  16 (was das gleiche ist)

               // #define LED D7 //nur Falls du externe LED z.B. an D7 (GPIO13)
               // über ca. 330 Ohm Widerstand angeschlossen hast auskommentieren

void setup() {
 pinMode(LED, OUTPUT); // Port aus Ausgang schalten
 }

void loop() {
 digitalWrite(LED, LOW); //Led port ausschalten
 delay(1000); //1 Sek Pause
 digitalWrite(LED, HIGH); //Led port einschlaten
 delay(1000);
 }
