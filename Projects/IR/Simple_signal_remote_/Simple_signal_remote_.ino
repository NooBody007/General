#include <IRremote.h>

#define ir_pin 7


void setup() {
  Serial.begin(9600);
  IrReceiver.begin(ir_pin);
}

void loop() {
  if(IrReceiver.decode()){
    IrReceiver.resume();
    Serial.println(IrReceiver.decodedIRData.command);
  }
}
