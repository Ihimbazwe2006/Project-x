
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>
 const char* ssid = ""; /*wifi name*/
 const char* password = ""; /*passworf*/
 const char* serverName = "http:/ /*IP Address*//tutorial/start.php";
 const int ledPin = D1;
 const int buzzer = D3;
 const int ledgreen = D2;
 
void setup() {

  Serial.begin(115200);
 WiFi.begin(ssid,password);
 pinMode(ledPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
   pinMode(ledgreen, OUTPUT);
   digitalWrite(ledPin,LOW);
   Serial.print("connecting to wifi");
   while(WiFi.status() != WL_CONNECTED){
   delay(1000);
    Serial.print(".");
   }
   Serial.println("\n Connected to wifi");
   digitalWrite(buzzer,HIGH);
   delay(500);
   digitalWrite(buzzer,LOW);
}

void loop() {
  // wait for WiFi connection
  if(WiFi.status() == WL_CONNECTED){
    HTTPClient http;
    WiFiClient client;
    
    http.begin(client, serverName);
    int httpCode = http.GET();

    if(httpCode > 0) {
      String payload = http.getString();
      Serial.println("Status:" + payload);

      if(payload = "ON") {
        digitalWrite(ledgreen, HIGH);
        for(int i=0;i<10000;i++) {
          digitalWrite(ledPin, HIGH);
          digitalWrite(buzzer, HIGH);
          delay(100);
          digitalWrite(ledPin, LOW);
          digitalWrite(buzzer, LOW);
        }
        
      }
      else{
        digitalWrite(ledPin, LOW);
          digitalWrite(buzzer, LOW);
          digitalWrite(ledgreen, LOW);
          Serial.println("Light is off");
        }}
     while (1);
        else{
          Serial.println("Error in http request");
          }
          http.end();
  }
  else{
    Serial.println("WI-FI Disconnected");
    }
    delay(500);
}
