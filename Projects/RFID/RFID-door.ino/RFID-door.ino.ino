#include <SPI.h>
#include <Servo.h>
#include <MFRC522.h>

int servo_pin = 8;
int ss_pin = 10;
int rst_pin = 9;

Servo motor;
MFRC522 rfid(ss_pin,rst_pin);

byte ID[4] = {163, 59, 81, 47};

void setup() {
  motor.attach(servo_pin);
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
}

void loop() {
  if(! rfid.PICC_IsNewCardPresent())
    return;
  if(! rfid.PICC_ReadCardSerial())
    return;

  if(rfid.uid.uidByte[0] == ID[0] && 
  rfid.uid.uidByte[1] == ID[1] && 
  rfid.uid.uidByte[2] == ID[2] && 
  rfid.uid.uidByte[3] == ID[3]){
    Serial.println("Kapı Acıldı");
    ekranayazdir();
    motor.write(180);
    delay(3000);
    motor.write(0);
    delay(1000);
  }
  else{
    Serial.println("Yetkisiz Kart");
    ekranayazdir();
    rfid.PICC_HaltA();
  }
}

void ekranayazdir(){
  Serial.print("ID Numarası: ");
  for(int counter=0; counter < rfid.uid.size; counter++){
    Serial.print(rfid.uid.uidByte[counter]);
    Serial.print(" ");
  }
  Serial.println();
}
