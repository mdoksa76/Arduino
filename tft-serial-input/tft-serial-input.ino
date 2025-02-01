#include <SPI.h>
#include <UTFTGLUE.h>
UTFTGLUE myGLCD(0,A2,A1,A3,A4,A0);

void setup()
{
  randomSeed(analogRead(0));
  Serial.begin(9600);
  Serial.println("Dobar dan!\n");
  Serial.println("Unesite tekst koji želite ispisati na ekranu.\n");
  
// Setup the LCD
  myGLCD.InitLCD();
  myGLCD.setFont(BigFont);
}

void printText(void)
{
  String s;
  if (Serial.available())
  {
    s=Serial.readString();
    myGLCD.print(s,CENTER,50);
  }
}

void loop()
{
  printText();
  delay(5000);
  myGLCD.clrScr();
}
