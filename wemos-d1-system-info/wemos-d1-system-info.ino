#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ; // Wait for serial port to connect. Needed for native USB port only
  }
  Serial.println();
  Serial.println("Starting ESP8266 diagnostics...");
}

void loop() {
  // CPU frequency
  Serial.print("CPU frequency: ");
  Serial.print(ESP.getCpuFreqMHz());
  Serial.println(" MHz");

  // Free heap size (available RAM)
  Serial.print("Free heap size: ");
  Serial.print(ESP.getFreeHeap() / 1024);
  Serial.println(" KB");

  // Flash chip information
  Serial.print("Flash chip size: ");
  Serial.print(ESP.getFlashChipRealSize() / 1024);
  Serial.println(" KB");

  // Chip ID
  Serial.print("Chip ID: ");
  Serial.println(ESP.getChipId());

  // SDK version
  Serial.print("SDK version: ");
  Serial.println(ESP.getSdkVersion());

  // Core version
  Serial.print("Core version: ");
  Serial.println(ESP.getCoreVersion());

  // Add a delay to avoid flooding the serial monitor
  delay(60000); // 60 seconds delay
}
