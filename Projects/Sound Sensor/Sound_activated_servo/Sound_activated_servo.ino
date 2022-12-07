#include <Servo.h>

const int ss = 0;
const int led = 7;

int level;
const int maxdb = 640;

const int servo_pin = 8;
int checker = false;


Servo motor;


void setup() {
  motor.attach(servo_pin);
  pinMode(led,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  level = analogRead(ss);
  if(level>maxdb && checker == false){
    digitalWrite(led,HIGH);
    motor.write(180);
    delay(1000);
    digitalWrite(led,LOW);
    checker = true;
  }
  else if(level>maxdb && checker == true){
    digitalWrite(led,HIGH);
    motor.write(0);
    delay(1000);
    digitalWrite(led,LOW);
    checker = false; 
  }
  else{
    digitalWrite(led,LOW);
  }
}
