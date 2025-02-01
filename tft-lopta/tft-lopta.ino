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

  lopta1();
  lopta2();
  lopta3();
  lopta4();
}

void lopta1(void) {
    for (int x=160; x<320; x=x+5) {
      LCD.setColor(random(255),random(255),random(255));
      LCD.fillCircle(random(x+10),random(x+10),random(10));
      LCD.fillCircle(random(x+20),random(x+20),random(10));
      LCD.fillCircle(random(x+30),random(x+30),random(10));
      LCD.fillCircle(random(x+50),random(x+50),random(10));
      LCD.fillCircle(random(x+75),random(x+75),random(10));
      LCD.fillCircle(random(x-10),random(x-10),random(10));
      LCD.fillCircle(random(x-20),random(x-20),random(10));
      LCD.fillCircle(random(x-30),random(x-30),random(10));
      LCD.fillCircle(random(x-40),random(x-50),random(10));
      LCD.fillCircle(random(x-75),random(x-75),random(10));
      delay(20);
      LCD.clrScr();
    }
}

void lopta2(void) {
    for (int x=0; x<320; x=x+5) {
      LCD.setColor(255,255,0);
      LCD.fillCircle(4*x,x,10);
      LCD.fillCircle(3*x,240-0.5*x,10);
      LCD.fillCircle(320-2*x,120,10);
      delay(20);
      LCD.clrScr();
    }
}

void lopta3(void) {
    for (int x=0; x<3200; x=x+1) {
      LCD.setColor(random(255),random(255),random(255));
      LCD.fillCircle(x,119+(sin(((x*1.13)*3.14)/180)*95),5);
      LCD.fillCircle(x,119+0.9*(sin(((x*1.13)*3.14)/90)*95),5);
      LCD.fillCircle(x,119+1.1*(cos(((x*1.13)*3.14)/90)*95),5);
    }
}

void lopta4(void) {
  int buf[320];
  int x, x2;
  int y, y2;
  int r;
 
  x=0;
  for (int i=1; i<(318*20); i++) 
  {
    x++;
    if (x==320)
      x=0;
    if (i>320)
    {
      if ((x==160)||(buf[x-1]==120))
        LCD.setColor(0,0,0);
      else
        LCD.setColor(0,0,0);
      LCD.drawPixel(x,buf[x-1]);
    }
    LCD.setColor(0,255,255);
    y=120+(sin(((i*1.1)*3.14)/180)*(90-(i / 100)));
    LCD.drawPixel(x,y);
    buf[x-1]=y;
  }
}
