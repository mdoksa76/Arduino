int led1=9;
int led2=10;
int brightness1=0;
int brightness2=0;
int fadeAmount1=5;
int fadeAmount2=25;

void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
}

void loop() {
  analogWrite(led1,brightness1);
  analogWrite(led2,brightness2);
  brightness1=brightness1+fadeAmount1;
  brightness2=brightness2+fadeAmount2;
  fadeAmount1=-fadeAmount1;
  fadeAmount2=-fadeAmount2;

  if (brightness1<=0 || brightness1>=255){
    fadeAmount1=-fadeAmount1;
  }
  if (brightness2<=0 || brightness2>=255){
    fadeAmount2=-fadeAmount2;
  }
  delay(20);
}
