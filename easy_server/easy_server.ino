#include <ESP8266WiFi.h>

char ssid[]="wifi512";
char passwd[]="BrakHasla123";
String webpage = "";
boolean success=false;
boolean currentLineIsBlank;

WiFiServer server(80);

void setup(){
  webpage += "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\n";
  webpage += "<body>\n<center><h1>Hello world!</h1><br/>\n<p>this is webserver based on esp8266</p></center>\n</body>\n</html>";
  Serial.begin(115200);

  Serial.print("Connecting");
  WiFi.begin(ssid, passwd);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(". ");
  }
  Serial.println("Connection success");

  server.begin();
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}
void loop(){
  WiFiClient client = server.available();
  if(client){
    Serial.println("New client!");
    success=false;
    currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
       char c = client.read();
       if (c == '\n' && currentLineIsBlank){
        client.print(webpage);
        success=true;
        break;
       }
       if (c == '\n') {
         currentLineIsBlank = true;
       }
       else if (c != '\r') {
         currentLineIsBlank = false;
       }
      }
    }
    delay(1);
    client.stop();
    if(success) {
      Serial.println("Everything works :)");
    }else{
      Serial.println("Sometching goes wrong :(");
    }
  }
}

