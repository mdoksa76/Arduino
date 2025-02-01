// DHT Temperature & Humidity Sensor
// Unified Sensor Library Example
// Written by Tony DiCola for Adafruit Industries
// Released under an MIT license.

// Depends on the following Arduino libraries:
// - Adafruit Unified Sensor Library: https://github.com/adafruit/Adafruit_Sensor
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library


#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#define DHTPIN            4         // Pin which is connected to the DHT sensor.

// Uncomment the type of sensor in use:
#define DHTTYPE           DHT11     // DHT 11
//#define DHTTYPE           DHT22     // DHT 22 (AM2302)
//#define DHTTYPE           DHT21     // DHT 21 (AM2301)

// See guide for details on sensor wiring and usage:
//   https://learn.adafruit.com/dht/overview

U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);
//U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);  // Adafruit ESP8266/32u4/ARM Boards + FeatherWing OLED
DHT_Unified dht(DHTPIN, DHTTYPE);

const long screenInterval = 1000;           // interval at which to buffer (milliseconds)
unsigned long sensorInterval;
unsigned long previousMillis;

void setup() {
  u8g2.begin();
  dht.begin();
  u8g2.enableUTF8Print();
  u8g2.println("DHTxx Unified Sensor Example");
  // Print temperature sensor details.
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  u8g2.println("------------------------------------");
  u8g2.println("Temperature");
  u8g2.print  ("Sensor:       "); u8g2.println(sensor.name);
  u8g2.print  ("Driver Ver:   "); u8g2.println(sensor.version);
  u8g2.print  ("Unique ID:    "); u8g2.println(sensor.sensor_id);
  u8g2.print  ("Max Value:    "); u8g2.print(sensor.max_value); u8g2.println(" *C");
  u8g2.print  ("Min Value:    "); u8g2.print(sensor.min_value); u8g2.println(" *C");
  u8g2.print  ("Resolution:   "); u8g2.print(sensor.resolution); u8g2.println(" *C"); 
  u8g2.println("------------------------------------");
  // Print humidity sensor details.
  dht.humidity().getSensor(&sensor);
  u8g2.println("------------------------------------");
  u8g2.println("Humidity");
  u8g2.print  ("Sensor:       "); u8g2.println(sensor.name);
  u8g2.print  ("Driver Ver:   "); u8g2.println(sensor.version);
  u8g2.print  ("Unique ID:    "); u8g2.println(sensor.sensor_id);
  u8g2.print  ("Max Value:    "); u8g2.print(sensor.max_value); u8g2.println("%");
  u8g2.print  ("Min Value:    "); u8g2.print(sensor.min_value); u8g2.println("%");
  u8g2.print  ("Resolution:   "); u8g2.print(sensor.resolution); u8g2.println("%"); 
  u8g2.println("------------------------------------");
    // Set delay between sensor readings based on sensor details.
 sensorInterval = sensor.min_delay / 1000;
}

void loop() {
  for(static unsigned long previousMillis=millis();
      millis()-previousMillis>=sensorInterval;
      previousMillis=millis()){
        u8g2.clearBuffer();
        // Get temperature event and print its value.
        sensors_event_t event; 
        dht.temperature().getEvent(&event);
        if(isnan(event.temperature)) {u8g2.setFont(u8g2_font_5x7_tf);
           u8g2.setCursor(0,6);
           u8g2.println("        DOKSA");
           u8g2.setCursor(0,14);
           u8g2.println("Pogreska temperature!");
           u8g2.setCursor(0,36);
           u8g2.println("   Arduino - DHT11");
           }
           else {u8g2.setFont(u8g2_font_5x7_tf);
           u8g2.setCursor(0,6);
           u8g2.println("        DOKSA");
           u8g2.setCursor(0,14);
           u8g2.print("Temperatura: ");
           u8g2.print(event.temperature);
           u8g2.println("°C");
           u8g2.setCursor(0,36);
           u8g2.println("   Arduino - DHT11");
           }
           // Get humidity event and print its value.
           dht.humidity().getEvent(&event);
           if (isnan(event.relative_humidity)) {u8g2.setFont(u8g2_font_5x7_tf);
           u8g2.setCursor(0,23);
           u8g2.println("Pogreska vlaznosti!");
           }
           else {u8g2.setFont(u8g2_font_5x7_tf);
           u8g2.setCursor(0,23);
           u8g2.print("Vlaznost: ");
           u8g2.print(event.relative_humidity);
           u8g2.println("%");
           }
  }

  for(static unsigned long previousMillis=millis();
      millis()-previousMillis>=screenInterval/4;
      previousMillis=millis()){u8g2.sendBuffer();}
}        
