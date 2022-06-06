#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

BlynkTimer timer;

char auth[] = "5XOOwW-iYrEXHw8xqr2rYlwYz8EwBWA0";
char ssid[] = "BEDABISA";
char pass[] = "I23A5678g";
int nilai;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, sendUptime);
}

void sendUptime(){
  Blynk.virtualWrite(V1, nilai);  
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  timer.run();
  nilai = analogRead(A0);
  
  delay(200);
}
