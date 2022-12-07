

const int sw_pin = 2;
const int x_pin = 0;
const int y_pin = 1;

#define up_led 8
#define right_led 9
#define left_led 10
#define down_led 11





void setup() {
  pinMode(sw_pin, INPUT);
  digitalWrite(sw_pin,HIGH);
  Serial.begin(9600);

  pinMode(up_led, OUTPUT);
  pinMode(right_led, OUTPUT);
  pinMode(left_led, OUTPUT);
  pinMode(down_led, OUTPUT);

}

void loop() {
  Serial.print("Switch: ");
  Serial.print(digitalRead(sw_pin));
  Serial.print("\n");
  Serial.print("X axis: ");
  Serial.print(analogRead(x_pin));
  Serial.print("\n");
  Serial.print("Y axis");
  Serial.print(analogRead(y_pin));
  Serial.print("\n\n");

  delay(500);

  if(analogRead(x_pin) == 1023){
    digitalWrite(right_led, HIGH);
  }
  else if(analogRead(x_pin) == 0){
    digitalWrite(left_led, HIGH);
  }
  else if(analogRead(y_pin) == 1023){
    digitalWrite(down_led, HIGH);
  }
  else if(analogRead(y_pin) == 0){
    digitalWrite(up_led, HIGH);
  }
  else if(digitalRead(sw_pin) == 0){
    digitalWrite(up_led, HIGH);
    digitalWrite(left_led, HIGH);
    digitalWrite(right_led, HIGH);
    digitalWrite(down_led, HIGH);
  }

  else{
    digitalWrite(up_led, LOW);
    digitalWrite(left_led, LOW);
    digitalWrite(right_led, LOW);
    digitalWrite(down_led, LOW);
  }
}
