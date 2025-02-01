#include "math.h"
//#include "string.h"
#include <UTFTGLUE.h>
UTFTGLUE LCD(0, A2, A1, A3, A4, A0);

float a;
float b;
float c;
float O;
float P;
char junk = ' ';

void setup()
{
  randomSeed(analogRead(0));

  Serial.begin(9600);
  Serial.println("PITAGORIN TEOREM");
  Serial.println("");
  Serial.println("Izracunajmo hipotenuzu c");
  Serial.println("");

  Serial.flush();

  // Setup the LCD
  LCD.InitLCD();
  LCD.setFont(SmallFont);

  int buf[318];
  int x, x2;
  int y, y2;
  int r;

  LCD.clrScr();

  LCD.setColor(0, 0, 0);
  LCD.fillRect(0, 0, 320, 240);

  LCD.setColor(255,255,255);
  LCD.print("Pitagorin teorem", CENTER, 20);
}

void loop()
{
  Pitagora();
}

void Pitagora(void)
{
  Serial.println("Unesi duljinu katete a i stisni ENTER");
  LCD.print("Unesi duljinu katete a", LEFT, 40);
  while (Serial.available() == 0) ;  // Wait here until input buffer has a character
  {
      //Kateta a
    a = Serial.parseFloat();        // new command in 1.0 forward
    Serial.print("a = "); Serial.println(a, DEC);


    while (Serial.available() > 0)  // .parseFloat() can leave non-numeric characters
    { junk = Serial.read() ; }      // clear the keyboard buffer
  }

  Serial.println("Unesi duljinu katete b i stisni ENTER");
  while (Serial.available() == 0) ;
  {
      //Kateta b
    b = Serial.parseFloat();
    Serial.print("b = "); Serial.println(b, DEC);
    while (Serial.available() > 0)
    { junk = Serial.read() ; }

    c = sqrt (float( a*a + b*b ));
    O = a + b + c;
    P = (a * b)/2;

    Serial.print("Hipotenuza c = ");
    Serial.println(c, DEC); Serial.println();
    Serial.print("Opseg trokuta O = ");
    Serial.println(O, DEC); Serial.println();
    Serial.print("Povrsina trokuta P = ");
    Serial.println(P, DEC); Serial.println();

    LCD.print("Racun gotov!", CENTER,50);
  }
}
