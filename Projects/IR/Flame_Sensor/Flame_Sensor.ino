

const int sensormin = 0;
const int sensormax = 1024;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorReading = analogRead(A0);
  int range = map(sensorReading ,sensormin ,sensormax, 0 ,3);

  switch(range){
    case 0:
    Serial.println("** Close Fire **");
    break;
    case 1:
    Serial.println("Distant Fire");
    break;
    case 2:
    Serial.println("No Fire");
    break;
  }
  delay(1000);
}
