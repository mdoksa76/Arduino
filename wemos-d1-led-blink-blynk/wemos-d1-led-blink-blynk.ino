#define BLYNK_PRINT Serial
 
#include <ESP8266WiFi.h>

#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.

// Go to the Project Settings (nut icon).

//char auth[] = "BtpkXcRKCVqxOqbdxGjs6jdabIhYSWxm";
char auth[] = "DkkHxWBufga7eyWeg9BT3dGsdL1SD25Z";
 
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ZTE2801A6";
char pass[] = "20gabek08";

int LED = D11; // Define LED as an Integer (whole numbers) and pin D8 on Wemos D1 Mini Pro

void setup()
{
  // Debug console
  Serial.begin(115200);
 pinMode(LED, OUTPUT); //Set the LED (D8) as an output
  Blynk.begin(auth, ssid, pass);

}

void loop()
{
  Blynk.run();
 
}
 
// This function will be called every time button Widget
// in Blynk app writes values to the Virtual Pin V3
BLYNK_WRITE(V0) {
 int pinValue = param.asInt(); // Assigning incoming value from pin V3 to a variable
 if (pinValue == 1) {
    digitalWrite(LED, HIGH); // Turn LED on.
    Serial.println("LED light ON. Ledica upaljena.");
  } else {
    digitalWrite(LED, LOW); // Turn LED off.
    Serial.println("LED light OFF. Ledica ugašena.");
 }
}
