#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <FS.h>

// Zamijenite s vašim WiFi SSID i lozinkom
const char* ssid[] = {"Speedport-705734", "Optima-6a54a1", "SSID3"};
const char* password[] = {"chsn5u5ere3nxcng", "OPTIMA2843501301", "PASSWORD3"};
const int ssidCount = sizeof(ssid) / sizeof(ssid[0]);

ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  for (int i = 0; i < ssidCount; i++) {
    Serial.print("Connecting to ");
    Serial.println(ssid[i]);
    WiFi.begin(ssid[i], password[i]);

    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED && attempts < 20) {
      delay(500);
      Serial.print(".");
      attempts++;
    }

    if (WiFi.status() == WL_CONNECTED) {
      Serial.println("");
      Serial.println("WiFi connected");
      Serial.println("IP address: ");
      Serial.println(WiFi.localIP());
      break;
    } else {
      Serial.println("");
      Serial.println("Failed to connect to ");
      Serial.println(ssid[i]);
    }
  }

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Could not connect to any WiFi network");
  }

  if (!SPIFFS.begin()) {
    Serial.println("Failed to mount file system");
    return;
  }

  server.on("/", handleRoot);
  server.on("/wemos-d1.jpg", handleImage);
  server.on("/calculate", handleCalculate);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}

void handleRoot() {
  String html = "<html><body>";
  html += "<h1>ESP8266 system info</h1>";
  html += "<img src=\"/wemos-d1.jpg\" alt=\"Wemos D1\">";
  html += "<p>Flash chip size: " + String(ESP.getFlashChipRealSize() / 1024) + " KB</p>";
  html += "<p>CPU frequency: " + String(ESP.getCpuFreqMHz()) + " MHz</p>";
  html += "<p>Free heap size: " + String(ESP.getFreeHeap() / 1024) + " KB</p>";
  html += "<p>Chip ID: " + String(ESP.getChipId()) + "</p>";
  html += "<p>SDK version: " + String(ESP.getSdkVersion()) + "</p>";
  html += "<p>Core version: " + String(ESP.getCoreVersion()) + "</p>";
  html += "<h2>Kalkulator: +, -, *, /</h2>";
  html += "<form id='calcForm'>";
  html += "Number 1: <input type='text' id='num1'><br>";
  html += "Operation: <input type='text' id='operation'><br>";
  html += "Number 2: <input type='text' id='num2'><br>";
  html += "<button type='button' onclick='calculate()'>Calculate</button>";
  html += "</form>";
  html += "<p id='result'></p>";
  html += "<script>";
  html += "function calculate() {";
  html += "var num1 = parseFloat(document.getElementById('num1').value).toFixed(6);";
  html += "var operation = encodeURIComponent(document.getElementById('operation').value);";
  html += "var num2 = parseFloat(document.getElementById('num2').value).toFixed(6);";
  html += "var xhr = new XMLHttpRequest();";
  html += "xhr.open('GET', '/calculate?num1=' + num1 + '&operation=' + operation + '&num2=' + num2, true);";
  html += "xhr.onreadystatechange = function() {";
  html += "if (xhr.readyState == 4 && xhr.status == 200) {";
  html += "document.getElementById('result').innerHTML = 'Result: ' + parseFloat(xhr.responseText).toFixed(6);";
  html += "console.log('Result: ' + parseFloat(xhr.responseText).toFixed(6));"; // Ispis rezultata u konzolu
  html += "} else if (xhr.readyState == 4) {";
  html += "console.error('Error: ' + xhr.status);";
  html += "}";
  html += "};";
  html += "xhr.send();";
  html += "}";
  html += "</script>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}

void handleImage() {
  File file = SPIFFS.open("/wemos-d1.jpg", "r");
  if (!file) {
    server.send(404, "text/plain", "File not found");
    return;
  }

  server.streamFile(file, "image/jpeg");
  file.close();
}

void handleCalculate() {
  if (server.hasArg("num1") && server.hasArg("operation") && server.hasArg("num2")) {
    float num1 = server.arg("num1").toFloat();
    String operation = server.arg("operation");
    float num2 = server.arg("num2").toFloat();
    float result;

    Serial.print("num1: ");
    Serial.println(num1);
    Serial.print("operation: ");
    Serial.println(operation);
    Serial.print("num2: ");
    Serial.println(num2);

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
        server.send(200, "text/plain", "Error: Division by zero!");
        return;
      }
    } else {
      server.send(200, "text/plain", "Invalid operation!");
      return;
    }

    Serial.print("Result: ");
    Serial.println(result, 6); // Ispis rezultata u serijski terminal s točnošću na 6 decimala
    server.send(200, "text/plain", String(result, 6)); // Ispis rezultata s točnošću na 6 decimala
  } else {
    server.send(200, "text/plain", "Missing parameters!");
  }
}
