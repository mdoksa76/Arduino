const int led=12; // variable which stores pin number

void setup() 
{
  Serial.begin(9600);                //Start the Serial connection
  pinMode(led, OUTPUT);  //configures pin 3 as OUTPUT
}

void loop() 
{
   int sensor_value = analogRead(A1);
  if (sensor_value < 260)// the point at which the state of LEDs change 
    { 
      digitalWrite(led, HIGH);  //sets LEDs ON
      Serial.println(sensor_value);
    }
  else
    {
      digitalWrite(led,LOW);  //Sets LEDs OFF
      Serial.println(sensor_value);
    }

}
