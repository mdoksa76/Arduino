#include <UTFTGLUE.h>
UTFTGLUE LCD(0, A2, A1, A3, A4, A0);

void setup()
{
  randomSeed(analogRead(0));

  // Setup the LCD
  LCD.InitLCD();
  LCD.setFont(BigFont);
}

void loop()
{
  int buf[318];
  int x, x2;
  int y, y2;
  int r;

  LCD.clrScr();

  LCD.setColor(0, 0, 0);
  LCD.fillRect(0, 0, 320, 240);

  for (int i=0; i<1000; i++)
  {
    LCD.setColor(random(255), random(255), random(255));
    LCD.fillCircle(160+random(10),240-random(20),random(4));
    LCD.fillCircle(160-random(10),240-random(20),random(4));
    delay(10);
    LCD.fillCircle(160+random(20),240-random(30),random(4));
    LCD.fillCircle(160-random(20),240-random(30),random(4));
    delay(10);
    LCD.fillCircle(160+random(30),240-random(40),random(4));
    LCD.fillCircle(160-random(30),240-random(40),random(4));
    delay(10);
    LCD.fillCircle(160+random(40),240-random(50),random(4));
    LCD.fillCircle(160-random(40),240-random(50),random(4));
    delay(10);
    LCD.fillCircle(160+random(50),240-random(60),random(4));
    LCD.fillCircle(160-random(50),240-random(60),random(4));
    delay(10);
    LCD.fillCircle(160+random(60),240-random(70),random(4));
    LCD.fillCircle(160-random(60),240-random(70),random(4));
    delay(10);
    LCD.fillCircle(160+random(80),240-random(80),random(4));
    LCD.fillCircle(160-random(80),240-random(80),random(4));
    delay(10);
  }
}
