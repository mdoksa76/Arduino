/* Right Triangle - User Interactive via Serial Terminal
   M. Ray Burnette 20130125
   Arduino Nano 328P target processor
   Binary sketch size: 5,184 bytes (of a 30,720 byte maximum)
*/

#include "math.h"               // include the Math Library

float a;
float b;
float c;
float O;
float P;
char junk = ' ';


void setup()                    // run once, when the sketch starts
{
  Serial.begin(9600);           // set up Serial library at 9600 bps

  Serial.println("PITAGORIN TEOREM");
  Serial.println("");
  Serial.println("Izracunajmo hipotenuzu c");
  Serial.println("");

  Serial.flush();
}

void loop()
{
  Serial.println("Unesi duljinu katete a i stisni ENTER");
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
  }
}
