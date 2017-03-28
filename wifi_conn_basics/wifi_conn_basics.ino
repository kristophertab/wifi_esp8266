#include <ESP8266WiFi.h>

char ssid[]="wifi512";
char passwd[]="BrakHasla123";
int wait=0;

void setup()
{
  Serial.begin(115200);
  Serial.println();

  WiFi.begin(ssid, passwd);

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
    wait++;
  }
  Serial.println();

  Serial.print("Connected to ");
  Serial.print(ssid);
  Serial.print(" in sec: ");
  Serial.println(wait/2);
  Serial.print(" IP address: ");
  Serial.println(WiFi.localIP());

  WiFi.printDiag(Serial);

}

void loop() {}
