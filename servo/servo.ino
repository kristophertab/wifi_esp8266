#include <ESP8266WiFi.h>
#include <Servo.h>

#define led 0
#define servo 2

Servo srv;

void setup() {
  srv.attach(servo);
  pinMode(led, OUTPUT);
  
  Serial.begin(115200);
  Serial.println("start");
}

void loop() {
int i=0;
for(i=0; i<=180; i+=1){
  srv.write(i);
  delay(20);
}
for(i=180; i>=0; i-=1){
  srv.write(i);
  delay(20);
}
  
}
