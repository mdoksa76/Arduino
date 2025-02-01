// UTFT_Demo_320x240 
// Copyright (C)2015 Rinky-Dink Electronics, Henning Karlsen. All right reserved
// web: http://www.RinkyDinkElectronics.com/
//
// This program is a demo of how to use most of the functions
// of the library with a supported display modules.
//
// This demo was made for modules with a screen resolution 
// of 320x240 pixels.
//
// This program requires the UTFT library.
//

//################################################
// GLUE class that implements the UTFT API
// replace UTFT include and constructor statements
// remove UTFT font declaration e.g. SmallFont
//################################################

#include <UTFTGLUE.h>              //use GLUE class and constructor
UTFTGLUE myGLCD(0,A2,A1,A3,A4,A0); //all dummy args

// Declare which fonts we will be using
//extern uint8_t SmallFont[];      //GLUE defines as GFXFont ref

// Set the pins to the correct ones for your development shield
// ------------------------------------------------------------
// Arduino Uno / 2009:
// -------------------
// Standard Arduino Uno/2009 shield            : <display model>,A5,A4,A3,A2
// DisplayModule Arduino Uno TFT shield        : <display model>,A5,A4,A3,A2
//
// Arduino Mega:
// -------------------
// Standard Arduino Mega/Due shield            : <display model>,38,39,40,41
// CTE TFT LCD/SD Shield for Arduino Mega      : <display model>,38,39,40,41
//
// Remember to change the model parameter to suit your display module!
//UTFT myGLCD(ITDB32S,38,39,40,41);

void setup()
{
  randomSeed(analogRead(0));
  
// Setup the LCD
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
}

void okvir()
{
  // Brisanje ekrana, iscrtavanje okvira i ispis teksta
  myGLCD.clrScr();

  myGLCD.setColor(0, 255, 0);
  myGLCD.fillRect(0, 0, 319, 13);
  myGLCD.setColor(0, 255, 0);
  myGLCD.fillRect(0, 226, 319, 239);
  myGLCD.setColor(0, 0, 0);
  myGLCD.setBackColor(0, 255, 0);
  myGLCD.print("Muzej Prigorja", CENTER, 2);
  myGLCD.setColor(0, 0, 0);
  myGLCD.print("https://www.muzejprigorja.hr/", CENTER, 228);
  myGLCD.setColor(0, 0, 0);
  myGLCD.drawRect(0, 14, 319, 225);
}

void znak(float x, float y, float scale)
{
  myGLCD.setColor(255,255,255);
  myGLCD.drawRect((x+11)*scale,(y+94)*scale,(x+309)*scale,(y+106)*scale);
  myGLCD.fillRect((x+11)*scale,(y+94)*scale,(x+309)*scale,(y+106)*scale);
  myGLCD.drawRect((x+11)*scale,(y+106)*scale,(x+23)*scale,(y+144)*scale);
  myGLCD.fillRect((x+11)*scale,(y+106)*scale,(x+23)*scale,(y+144)*scale);
  myGLCD.drawRect((x+47)*scale,(y+106)*scale,(x+59)*scale,(y+144)*scale);
  myGLCD.fillRect((x+47)*scale,(y+106)*scale,(x+59)*scale,(y+144)*scale);
  myGLCD.drawRect((x+83)*scale,(y+106)*scale,(x+95)*scale,(y+144)*scale);
  myGLCD.fillRect((x+83)*scale,(y+106)*scale,(x+95)*scale,(y+144)*scale);
  myGLCD.drawRect((x+234)*scale,(y+106)*scale,(x+246)*scale,(y+144)*scale);
  myGLCD.fillRect((x+234)*scale,(y+106)*scale,(x+246)*scale,(y+144)*scale);
  myGLCD.drawRect((x+297)*scale,(y+106)*scale,(x+309)*scale,(y+144)*scale);
  myGLCD.fillRect((x+297)*scale,(y+106)*scale,(x+309)*scale,(y+144)*scale);
  myGLCD.drawRect((x+246)*scale,(y+132)*scale,(x+297)*scale,(y+144)*scale);
  myGLCD.fillRect((x+246)*scale,(y+132)*scale,(x+297)*scale,(y+144)*scale);
}

void kurija()
{
  myGLCD.drawLine(25,154,35,154);
  myGLCD.drawLine(35,154,35,134);
  myGLCD.drawLine(35,134,58,134);
  myGLCD.drawLine(58,134,58,154);
  myGLCD.drawLine(58,154,151,154);
  myGLCD.drawLine(151,154,151,126);
  myGLCD.drawLine(151,126,169,126);
  myGLCD.drawLine(169,126,169,154);
  myGLCD.drawLine(169,154,262,154);
  myGLCD.drawLine(262,154,262,134);
  myGLCD.drawLine(262,134,285,134);
  myGLCD.drawLine(285,134,285,154);
  myGLCD.drawLine(285,154,295,154);
  myGLCD.drawLine(295,154,295,121);
  myGLCD.drawLine(295,121,254,121);
  myGLCD.drawLine(254,121,254,134);
  myGLCD.drawLine(254,134,237,134);
  myGLCD.drawLine(237,134,237,93);
  myGLCD.drawLine(237,93,240,93);
  myGLCD.drawLine(240,93,240,70);
  myGLCD.drawLine(240,70,211,46);
  myGLCD.drawLine(211,46,107,46);
  myGLCD.drawLine(107,46,79,70);
  myGLCD.drawLine(79,70,79,93);
  myGLCD.drawLine(79,93,82,93);
  myGLCD.drawLine(82,93,82,134);
  myGLCD.drawLine(82,134,66,134);
  myGLCD.drawLine(66,134,66,121);
  myGLCD.drawLine(66,121,25,121);
  myGLCD.drawLine(25,121,25,154);
  myGLCD.drawRect(18,113,72,121);
  myGLCD.drawRect(247,113,300,121);
  myGLCD.drawLine(82,121,237,121);
  myGLCD.drawLine(82,93,237,93);
  myGLCD.drawLine(112,70,119,63);
  myGLCD.drawLine(119,63,126,70);
  myGLCD.drawLine(139,70,146,63);
  myGLCD.drawLine(146,63,153,70);
  myGLCD.drawLine(166,70,173,63);
  myGLCD.drawLine(173,63,180,70);
  myGLCD.drawLine(193,70,200,63);
  myGLCD.drawLine(200,63,207,70);
  myGLCD.drawRect(93,126,103,137);
  myGLCD.fillRect(93,126,103,137);
  myGLCD.drawRect(113,126,123,137);
  myGLCD.fillRect(113,126,123,137);
  myGLCD.drawRect(133,126,143,137);
  myGLCD.fillRect(133,126,143,137);
  myGLCD.drawRect(175,126,185,137);
  myGLCD.fillRect(175,126,185,137);
  myGLCD.drawRect(195,126,205,137);
  myGLCD.fillRect(195,126,205,137);
  myGLCD.drawRect(215,126,225,137);
  myGLCD.fillRect(215,126,225,137);
  myGLCD.drawRect(93,100,103,111);
  myGLCD.fillRect(93,100,103,111);
  myGLCD.drawRect(113,100,123,111);
  myGLCD.fillRect(113,100,123,111);
  myGLCD.drawRect(133,100,143,111);
  myGLCD.fillRect(133,100,143,111);
  myGLCD.drawRect(154,100,164,111);
  myGLCD.fillRect(154,100,164,111);
  myGLCD.drawRect(175,100,185,111);
  myGLCD.fillRect(175,100,185,111);
  myGLCD.drawRect(195,100,205,111);
  myGLCD.fillRect(195,100,205,111);
  myGLCD.drawRect(215,100,225,111);
  myGLCD.fillRect(215,100,225,111);
  myGLCD.drawRect(115,72,123,83);
  myGLCD.fillRect(115,72,123,83);
  myGLCD.drawRect(142,72,150,83);
  myGLCD.fillRect(142,72,150,83);
  myGLCD.drawRect(169,72,177,83);
  myGLCD.fillRect(169,72,177,83);
  myGLCD.drawRect(196,72,204,83);
  myGLCD.fillRect(196,72,204,83);
  myGLCD.drawRect(112,37,127,46);
  myGLCD.fillRect(112,37,127,46);
  myGLCD.drawRect(192,37,207,46);
  myGLCD.fillRect(192,37,207,46);
  myGLCD.print("Kurija Zagrebackog kaptola, 1784.", CENTER, 176);
  myGLCD.print("Muzej Prigorja, 1977.", CENTER, 191);
  myGLCD.print("Galerija Kurija", CENTER, 206);
}

void loop()
{
  int buf[318];
  int x, x2;
  int y, y2;
  int r;

// Crtanje znaka Muzeja Prigorja unutar okvira
  okvir();
  znak(0,0,1);
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.print("Muzej Prigorja", CENTER, 35);
  myGLCD.print("Trg Dragutina Domjanica 5", CENTER, 50);
  myGLCD.print("10360 Sesvete", CENTER, 65);
  myGLCD.print("Grad Zagreb", CENTER, 175);
  myGLCD.print("Republika Hrvatska", CENTER, 190);

  delay(3000);

// Poigravanje sa znakom

  znak(400,300,0.1);
  delay(50);
  myGLCD.clrScr();
  znak(320,260,0.2);
  delay(50);
  myGLCD.clrScr();
  znak(280,220,0.3);
  delay(50);
  myGLCD.clrScr();
  znak(240,180,0.4);
  myGLCD.clrScr();
  znak(200,150,0.5);
  delay(50);
  myGLCD.clrScr();
  znak(160,120,0.6);
  delay(50);
  myGLCD.clrScr();
  znak(120,90,0.7);
  delay(50);
  myGLCD.clrScr();
  znak(80,60,0.8);
  delay(50);
  myGLCD.clrScr();
  znak(40,30,0.9);
  delay(50);
  myGLCD.clrScr();
  znak(0,0,1);
  
  delay(1000);

// Crtanje Kurije
  myGLCD.clrScr();
  myGLCD.setColor(255,0,0);
  kurija();
  delay(1000);
  myGLCD.setColor(0,255,0);
  kurija();
  delay(1000);
  myGLCD.setColor(0,0,255);
  kurija();
  delay(1000);
  myGLCD.setColor(255,255,255);
  kurija();
  delay(2000);
  
// Crtanje Impresuma
  okvir();

  //myGLCD.fillScr(0, 255, 0);
  myGLCD.setColor(0, 255, 0);
  myGLCD.fillRect(0, 13, 320, 225);
  myGLCD.setColor(255, 0, 0);
  myGLCD.fillRoundRect(80, 50, 239, 149);
  
  myGLCD.setColor(255, 255, 255);
  myGLCD.setBackColor(255, 0, 0);
  myGLCD.print("Muzej Prigorja", CENTER, 60);
  myGLCD.print("Arduino radionice", CENTER, 75);
  myGLCD.print("2020.", CENTER, 90);
  myGLCD.print("Restart za", CENTER, 115);
  myGLCD.print("5 sekundi ...", CENTER, 130);
  
  myGLCD.setColor(0, 0, 0);
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.fillRoundRect(100, 175, 220, 205);
  myGLCD.setColor(255, 255, 255);
  myGLCD.print("Runtime: (ms)", CENTER, 178);
  myGLCD.printNumI(millis(), CENTER, 193);
  
  delay (5000);
}
