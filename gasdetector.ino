#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

BlynkTimer timer;

char auth[] = ""; //Isi dengan Auth Code dari Blynk
char ssid[] = ""; //Isi dengan ssid WiFi yang dipakai
char pass[] = ""; //Isi dengan password WiFi yang dipakai
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
