#include "Adafruit_GFX.h"
#include "MCUFRIEND_kbv.h"
MCUFRIEND_kbv tft;
#include <UTFTGLUE.h>              //use GLUE class and constructor
UTFTGLUE myGLCD(0,A2,A1,A3,A4,A0); //all dummy args

#include "Fonts/FreeSans9pt7b.h"
#include "Fonts/FreeSans12pt7b.h"
#include "Fonts/FreeSerif12pt7b.h"
#include "FreeDefaultFonts.h"

#define PI 3.1416

int col[8];

void setup()
{
  randomSeed(analogRead(0));
  
// Setup the LCD
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
}

void showmsgXY(int x, int y, int sz, const GFXfont *f, const char *msg)
{
  int16_t x1, y1;
  uint16_t wid, ht;


  tft.setFont(f);
  tft.setCursor(x, y);
  tft.setTextColor(0x0000);
  tft.setTextSize(sz);
  tft.print(msg);
}

void loadingSetup() {
  tft.reset();
  Serial.begin(9600);
  uint16_t ID = tft.readID();
  tft.begin(ID);
  tft.setRotation(1);
  tft.invertDisplay(true);
  tft.fillScreen(0xffff);
  showmsgXY(120, 200, 1, &FreeSans9pt7b, "Loading...");
  col[0] = tft.color565(155, 0, 50);
  col[1] = tft.color565(170, 30, 80);
  col[2] = tft.color565(195, 60, 110);
  col[3] = tft.color565(215, 90, 140);
  col[4] = tft.color565(230, 120, 170);
  col[5] = tft.color565(250, 150, 200);
  col[6] = tft.color565(255, 180, 220);
  col[7] = tft.color565(255, 210, 240);

}

void loading() {
  for (int i = 8; i > 0; i--) {
    tft.fillCircle(160 + 40 * (cos(-i * PI / 4)), 100 + 40 * (sin(-i * PI / 4)), 10,  col[0]); delay(15);
    tft.fillCircle(160 + 40 * (cos(-(i + 1)*PI / 4)), 100 + 40 * (sin(-(i + 1)*PI / 4)), 10,  col[1]); delay(15);
    tft.fillCircle(160 + 40 * (cos(-(i + 2)*PI / 4)), 100 + 40 * (sin(-(i + 2)*PI / 4)), 10,  col[2]); delay(15);
    tft.fillCircle(160 + 40 * (cos(-(i + 3)*PI / 4)), 100 + 40 * (sin(-(i + 3)*PI / 4)), 10,  col[3]); delay(15);
    tft.fillCircle(160 + 40 * (cos(-(i + 4)*PI / 4)), 100 + 40 * (sin(-(i + 4)*PI / 4)), 10,  col[4]); delay(15);
    tft.fillCircle(160 + 40 * (cos(-(i + 5)*PI / 4)), 100 + 40 * (sin(-(i + 5)*PI / 4)), 10,  col[5]); delay(15);
    tft.fillCircle(160 + 40 * (cos(-(i + 6)*PI / 4)), 100 + 40 * (sin(-(i + 6)*PI / 4)), 10,  col[6]); delay(15);
    tft.fillCircle(160 + 40 * (cos(-(i + 7)*PI / 4)), 100 + 40 * (sin(-(i + 7)*PI / 4)), 10,  col[7]); delay(15);
  }
}

void loop() {
  int buf[318];
  int x, x2;
  int y, y2;
  int r;

  loading();
  
// Brisanje ekrana, iscrtavanje okvira i ispis teksta
  myGLCD.clrScr();

  myGLCD.setColor(0, 255, 0);
  myGLCD.fillRect(0, 0, 319, 13);
  myGLCD.setColor(0, 255, 0);
  myGLCD.fillRect(0, 226, 319, 239);
  myGLCD.setColor(0, 0, 0);
  myGLCD.setBackColor(0, 255, 0);
  myGLCD.print("Muzej Prigorja", CENTER, 3);
  myGLCD.setColor(0, 0, 0);
  myGLCD.print("https://www.muzejprigorja.hr/", CENTER, 229);

  myGLCD.setColor(0, 0, 0);
  myGLCD.drawRect(0, 14, 319, 225);

// Crtanje znaka Muzeja Prigorja unutar okvira
  myGLCD.setColor(255,255,255);
  myGLCD.drawRect(11,94,309,106);
  myGLCD.fillRect(11,94,309,106);
  myGLCD.drawRect(11,106,23,144);
  myGLCD.fillRect(11,106,23,144);
  myGLCD.drawRect(47,106,59,144);
  myGLCD.fillRect(47,106,59,144);
  myGLCD.drawRect(83,106,95,144);
  myGLCD.fillRect(83,106,95,144);
  myGLCD.drawRect(234,106,246,144);
  myGLCD.fillRect(234,106,246,144);
  myGLCD.drawRect(297,106,309,144);
  myGLCD.fillRect(297,106,309,144);
  myGLCD.drawRect(246,132,297,144);
  myGLCD.fillRect(246,132,297,144);
  myGLCD.setBackColor(0,0,0);
  myGLCD.print("Muzej Prigorja", CENTER, 40);
  myGLCD.print("Trg Dragutina Domjanica 5", CENTER, 50);
  myGLCD.print("10360 Sesvete", CENTER, 60);
  myGLCD.print("Grad Zagreb", CENTER, 180);
  myGLCD.print("Republika Hrvatska", CENTER, 190);

  delay(10000);

  loading();
  
// Crtanje Impresuma
  myGLCD.fillScr(0, 0, 255);
  myGLCD.setColor(255, 0, 0);
  myGLCD.fillRoundRect(80, 70, 239, 169);
  
  myGLCD.setColor(255, 255, 255);
  myGLCD.setBackColor(255, 0, 0);
  myGLCD.print("Muzej Prigorja", CENTER, 90);
  myGLCD.print("Arduino radionice, 2020.", CENTER, 105);
  myGLCD.print("Restart za", CENTER, 120);
  myGLCD.print("5 sekundi ...", CENTER, 130);
  
  myGLCD.setColor(0, 255, 0);
  myGLCD.setBackColor(0, 0, 255);
  myGLCD.print("Runtime: (ms)", CENTER, 210);
  myGLCD.printNumI(millis(), CENTER, 225);
  
  delay (5000);
}
