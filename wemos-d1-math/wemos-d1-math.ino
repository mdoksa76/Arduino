/* DHTServer - ESP8266 Webserver with a DHT sensor as an input

   Based on ESP8266Webserver, DHTexample, and BlinkWithoutDelay (thank you)

   Version 1.0  5/3/2014  Version 1.0   Mike Barela for Adafruit Industries
*/
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

// Replace with your network details
const char* ssid     = "ZTE2801A6";
const char* password = "20gabek08";

ESP8266WebServer server(80);

#include "math.h"               // include the Math Library

float a;
float b;
float c;
float O;
float P;
char junk = ' ';


void handle_root() {
  server.send(200, "text/plain", "ESP8266 on WEMOS D1 Web Server\n\nMD76");
  delay(100);
}

void setup(void)
{
  // You can open the Arduino IDE Serial Monitor window to see what the code is doing
  Serial.begin(9600);  // Serial connection from ESP-01 via 3.3v console cable

  // Connect to WiFi network
  WiFi.begin(ssid, password);
  Serial.print("\n\r \n\rWorking to connect");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("ESP8266 WEMOS D1 Web Server - MD76!");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handle_root);

  server.begin();
  Serial.println("HTTP server started");

}

void loop(void)
{
  server.handleClient();

  Serial.println("PITAGORIN TEOREM");
  Serial.println("");
  Serial.println("Izracunajmo hipotenuzu c");
  Serial.println("");

  Serial.println("Unesi duljinu katete a i stisni ENTER");
  while (Serial.available() == 0) ;  // Wait here until input buffer has a character
  {
      //Kateta a
    a = Serial.parseFloat();        // new command in 1.0 forward
    Serial.print("a = "); Serial.println(a, DEC);

    while (Serial.available() > 0)  // .parseFloat() can leave non-numeric characters
    { junk = Serial.read() ; }      // clear the keyboard buffer
  }

  Serial.println("Unesi duljinu katete b i stisni ENTER");
  while (Serial.available() == 0) ;
  {
      //Kateta b
    b = Serial.parseFloat();
    Serial.print("b = "); Serial.println(b, DEC);
    while (Serial.available() > 0)
    { junk = Serial.read() ; }

    c = sqrt (float( a*a + b*b ));
    O = a + b + c;
    P = (a * b)/2;

    Serial.print("Hipotenuza c = ");
    Serial.println(c, DEC); Serial.println();
    Serial.print("Opseg trokuta O = ");
    Serial.println(O, DEC); Serial.println();
    Serial.print("Povrsina trokuta P = ");
    Serial.println(P, DEC); Serial.println();
  }
}
