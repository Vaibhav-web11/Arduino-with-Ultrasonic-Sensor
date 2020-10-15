#include <LiquidCrystal.h>

//const int rs = 12, 2n = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(12,11,5,4,3,2);
int trigPin = 7;
int echoPin = 6;
long distance;
long duration;
void setup(){
  lcd.begin(16, 2);
  pinMode(13, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}


void loop(){

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  
  lcd.setCursor(0,0);
  lcd.print("UltraSonic");
  lcd.setCursor(0,1);
  lcd.print("distance : ");
  lcd.print(distance);
  lcd.print("cm");
  if (distance<int(12))
  {
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(100);
  }
}
  //digitalWrite(13,LOW);
