const int ss = 0;
const int led = 7;

int level;
const int maxdb = 640;

void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
 level = analogRead(ss);
 if(level > maxdb){
  digitalWrite(led,HIGH);
  delay(1000);
  digitalWrite(led,LOW);
 }
 else{
  digitalWrite(led,LOW);
 }
  
}
