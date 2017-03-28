#include<ESP8266WiFi.h>

void setup() {
  pinMode(0, OUTPUT);
  Serial.begin(115200);
  Serial.println("Electronical Hello World!");
}

void loop() {
  digitalWrite(0, HIGH);
  delay(500);
  digitalWrite(0, LOW);
  delay(500);

}
