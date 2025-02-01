#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  izbornik();
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim(); 

    if (input == "1") {
      kalkulator(); 
    } else if (input == "2") {
      potencije();
    } else {
      Serial.println("Invalid option! Please select a valid option:");
      izbornik();
    }
  }
}

void izbornik() {
  Serial.println("ESP8266 kalkulator!!!");
  Serial.println("Izbornik:");
  Serial.println("1. Osnovne matematičke operacije");
  Serial.println("2. Potencije");
}

void kalkulator() {
  float num1, num2;
  String operation;

  Serial.println("Unesi broj:");
  while (!Serial.available()) {} 
  num1 = Serial.parseFloat(); 
  Serial.readStringUntil('\n'); // Clear the buffer
  Serial.print("Prvi broj: ");
  Serial.println(num1, 6); // Ispisuje broj s 6 decimalnih mjesta

  Serial.println("Matematička operacija: +, -, *, /:");
  while (!Serial.available()) {} 
  operation = Serial.readStringUntil('\n');
  operation.trim();
  Serial.print("Operacija: ");
  Serial.println(operation);

  Serial.println("Unesi broj:");
  while (!Serial.available()) {} 
  num2 = Serial.parseFloat();
  Serial.readStringUntil('\n'); // Clear the buffer
  Serial.print("Drugi broj: ");
  Serial.println(num2, 6); // Ispisuje broj s 6 decimalnih mjesta

  float result;
  if (operation == "+") {
    result = num1 + num2;
  } else if (operation == "-") {
    result = num1 - num2;
  } else if (operation == "*") {
    result = num1 * num2;
  } else if (operation == "/") {
    if (num2 != 0) {
      result = num1 / num2;
    } else {
      Serial.println("Greška: Dijeljenje s 0!");
      return; 
    }
  } else {
    Serial.println("Nepoznata operacija!");
    return; 
  }

  Serial.print("Rezultat: ");
  Serial.println(result, 6); // Ispisuje rezultat s 6 decimalnih mjesta

  Serial.println("Stisni 'i' za Izbornik ili 'k' za novi račun:");
  while (!Serial.available()) {} 
  String choice = Serial.readStringUntil('\n');
  choice.trim();

  if (choice == "i") {
    izbornik(); 
  } else if (choice == "k") {
    kalkulator();
  }
}

void potencije() {
  float base, exponent;
  
  Serial.println("Unesi bazu:");
  while (!Serial.available()) {}
  base = Serial.parseFloat();
  Serial.readStringUntil('\n'); // Clear the buffer
  Serial.print("Baza: ");
  Serial.println(base, 6); // Ispisuje broj s 6 decimalnih mjesta
  
  Serial.println("Unesi eksponent:");
  while (!Serial.available()) {}
  exponent = Serial.parseFloat();
  Serial.readStringUntil('\n'); // Clear the buffer
  Serial.print("Eksponent: ");
  Serial.println(exponent, 6); // Ispisuje broj s 6 decimalnih mjesta
  
  float result = pow(base, exponent);
  Serial.print("Result: ");
  Serial.println(result, 6);

  Serial.println("Stisni 'i' za Izbornik ili 'p' za novi račun:");
  while (!Serial.available()) {} 
  String choice = Serial.readStringUntil('\n');
  choice.trim();

  if (choice == "i") {
    izbornik(); 
  } else if (choice == "p") {
    potencije();
  }
}
