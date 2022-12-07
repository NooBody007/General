#include <Servo.h>

const int sw_pin = 2;
const int x_pin = 0;
const int y_pin = 1;

const int servo_pin = 8;
int range;

Servo motor;

void setup() {
  pinMode(sw_pin,INPUT);
  motor.attach(servo_pin);
  Serial.begin(9600);

}

void loop() {
  int xaxis = analogRead(A0);
  int yaxis = analogRead(A1);

  xaxis = xaxis * 0.1750;
  //xaxis = 180 - xaxis;
  motor.write(xaxis);
  /*if(analogRead(x_pin)<=1023 && analogRead(x_pin)>512){
    range = constrain(1023-xaxis,0,45);
    Serial.println(45-range);
    motor.write(range-45);
  }
  delay(400);
  if(analogRead(x_pin)<512 && analogRead(x_pin)>=0){
    range = constrain(512-xaxis,0,45);
    Serial.println(45-range);
    motor.write(45-range);
  }
  delay(400);*/

}
