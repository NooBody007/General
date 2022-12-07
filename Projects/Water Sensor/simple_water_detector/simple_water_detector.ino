
#define water_sensor 3
#define led 8



void setup() {
  pinMode(water_sensor, INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(water_sensor) == HIGH){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }
}
