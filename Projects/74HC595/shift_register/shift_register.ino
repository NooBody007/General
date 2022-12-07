const int data = 4;
const int latch = 5;   
const int clockp = 6;   

byte leds= 0;


void setup() {
  pinMode(data,OUTPUT);
  pinMode(latch,OUTPUT);
  pinMode(clockp,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  leds = 0;
  writeregister();
  delay(500);

  for(int i = 0; i<8;++i){
    bitSet(leds,i);
    writeregister();
    delay(500);
  }
  for(int i = 8; i >=0; i--){
    bitClear(leds,i);
    writeregister();
    delay(500);
  }
}

void writeregister(){
  digitalWrite(latch,LOW);
  shiftOut(data,clockp,LSBFIRST,leds);
  digitalWrite(latch,HIGH);
}
