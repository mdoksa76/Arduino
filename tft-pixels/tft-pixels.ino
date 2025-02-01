#include <UTFTGLUE.h>              //use GLUE class and constructor
UTFTGLUE myGLCD(0, A2, A1, A3, A4, A0); //all dummy args

void setup()
{
  randomSeed(analogRead(0));

  // Setup the LCD
  myGLCD.InitLCD();
  myGLCD.setFont(BigFont);
}

void loop()
{
  int buf[318];
  int x, x2;
  int y, y2;
  int r;

  // Clear the screen and draw the frame
  myGLCD.clrScr();

  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(0, 0, 320, 240);

  for (int r = 10; r < 241; r = r + 10)
  {
    myGLCD.setColor(random(255), random(255), random(255));
    myGLCD.drawCircle(160, 120, r);
    delay(10);
  }
  
  myGLCD.clrScr();
  for (float r = 10; r < 20; r = r + 0.01)
  {
    myGLCD.setColor(random(255), random(255), random(255));
    myGLCD.fillCircle(random(320), random(240), r);
    delay(10);
  }

  for (float r = 20; r > 10; r = r - 0.01)
  {
    myGLCD.setColor(random(255), random(255), random(255));
    myGLCD.fillCircle(random(320), random(240), r);
    delay(10);
  }

  myGLCD.clrScr();
  for (int i = 0; i < 1000; i++)
  {
    myGLCD.setColor(random(255), random(255), random(255));
    myGLCD.drawPixel(2 + random(318), 2 + random(238));
  }

  for (int i = 0; i < 10000; i++)
  {
    myGLCD.setColor(0, 0, 0);
    myGLCD.drawPixel(2 + random(318), 2 + random(238));
  }

  for (int i = 10; i < 321; i = i + 10)
  {
    myGLCD.setColor(random(255), random(255), random(255));
    myGLCD.drawLine(1, i, 320, i);
    myGLCD.drawLine(i, 1, i, 240);
    delay(10);
  }

  myGLCD.setColor(255, 255, 255);
  myGLCD.print("GAME OVER!", CENTER, 110);
  delay(3000);
}
