#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0);

#define bmw_width 32
#define bmw_height 32
static char bmw_bits[] = {
  0xFF, 0xBF, 0xFC, 0xFF, 0xFF, 0xC7, 0xC7, 0xFF, 0xFF, 0xBC, 0x3D, 0xFF,
  0x7F, 0x3F, 0xF9, 0xFE, 0xBF, 0x3F, 0xF8, 0xFD, 0xDF, 0xBF, 0xFE, 0xFA,
  0x2F, 0x7F, 0xFF, 0xF6, 0x57, 0xCE, 0x70, 0xE8, 0x8F, 0xFA, 0x40, 0xDD,
  0x9B, 0xFD, 0x80, 0xD0, 0xBD, 0xFE, 0x00, 0xFC, 0xFD, 0xFF, 0x00, 0xBF,
  0x7D, 0xFF, 0x00, 0xBE, 0x7F, 0xFF, 0x00, 0xFE, 0xFE, 0xFF, 0x00, 0xBE,
  0xBE, 0xFF, 0x00, 0x7C, 0x3E, 0x00, 0xFF, 0x7D, 0x7F, 0x00, 0xFF, 0xFF,
  0x7D, 0x00, 0xFF, 0xBE, 0x7D, 0x00, 0xFF, 0xBE, 0xFD, 0x00, 0xFF, 0xBF,
  0xFF, 0x00, 0x7F, 0xFF, 0xFB, 0x01, 0xBF, 0xDF, 0xFB, 0x03, 0xDF, 0xDF,
  0xF7, 0x0F, 0xF3, 0xEF, 0xEF, 0xBF, 0xFE, 0xF7, 0xDF, 0xFF, 0xFF, 0xFB,
  0xBF, 0xFF, 0xFF, 0xFD, 0x7F, 0xFF, 0xFF, 0xFE, 0xFF, 0xFD, 0x3F, 0xFF,
  0xFF, 0xE3, 0xE7, 0xFF, 0xFF, 0xBF, 0xFC, 0xFF, };

void draw(void) {
// graphic commands to redraw the complete screen should be placed here
u8g2.drawXBMP(52, 0, bmw_width, bmw_height, bmw_bits);
}

void setup(void) {
u8g2.begin();
}

void loop(void) {
// picture loop
u8g2.firstPage();
do {
    draw();
   } while( u8g2.nextPage() );

// rebuild the picture after some delay
delay(1000);
}
