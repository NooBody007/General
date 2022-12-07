#include <Servo.h>

const int ss = 0;
const int led = 7;  //or buzzer


int level;
const int maxdb = 640;

const int servo_pin = 8;
bool checker = false;

Servo scanner;

void setup() {
  scanner.attach(servo_pin);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  //scanner.write(0);
}

void loop() {
  for(int i = 0; i<=180; ++i){
    level = analogRead(ss);
    if(level > maxdb){
      Serial.println("in if 1");
      analogWrite(led,HIGH);
    }
    else{
      Serial.println("in else 1");
      analogWrite(led,LOW);
    }
    scanner.write(i);
    delay(1000);
  }
  for(int i = 180; i>=0; --i){
    level = analogRead(ss);
    if(level > maxdb){
      Serial.println("in if 2");
      analogWrite(led,HIGH);
    }
    else{
      Serial.println("in else 2");
      analogWrite(led,LOW);
    }
    scanner.write(i);
    delay(1000);
  }
  /*if(scanner.read()==180){
    scanner.write(0);
    delay(500);
  }
  if(scanner.read()==0){
    scanner.write(180);
    delay(500);
  }*/
  /*scanner.write(180);
  if(analogRead(ss) > maxdb){
    analogWrite(led,HIGH);
  }
  else{
    analogWrite(led,LOW);
  }
  delay(1000);
  scanner.write(0);*/
}
