#include <IRremote.h>

#define ir_pin 13

#define g A5
#define f A4
#define a A3
#define b 1
#define e A2
#define d A1
#define c A0

bool on_check =false;

int on_pin = 2;
int off_pin = 3;

int channel[] = {9,10,11,12};
int channel_led = 0;

int volume[] = {4,5,6,7,8};
int volume_num = 0;
int volume_led = 0;

void setup() {
  Serial.begin(9600);
  pinMode(on_pin,OUTPUT);
  pinMode(off_pin,OUTPUT);
  digitalWrite(on_pin,LOW);
  digitalWrite(off_pin,HIGH);
  
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);

  for(int i = 0;i < sizeof(channel);++i){
    pinMode(channel[i],OUTPUT);
  }
  for(int i = 0;i < sizeof(volume);++i){
    pinMode(volume[i],OUTPUT);
  }
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  IrReceiver.begin(ir_pin);
}

void loop() {
  if(IrReceiver.decode()){
    delay(100);
    IrReceiver.resume();
    //Serial.println(IrReceiver.decodedIRData.command);
    switch(IrReceiver.decodedIRData.command){
      case 67:
      if(on_check == false){
        on_check = true;
        digitalWrite(on_pin,HIGH);
        digitalWrite(off_pin,LOW);
        Serial.println("TV ON");
        digitalWrite(channel[channel_led],HIGH);
        segment(channel_led);
        delay(300);
        break;
      }
      else{
        on_check = false;
        digitalWrite(on_pin,LOW);
        digitalWrite(off_pin,HIGH);
        alloff();
        Serial.println("TV OFF");
        delay(300);
        break;
      }
      case 69:
      if(on_check){
        if(channel_led != 0){
          digitalWrite(channel[channel_led-1],HIGH);
          closechannel(channel_led-1,channel);
          channel_led -= 1;
          segment(channel_led);
        }
        Serial.println("previous channel"); 
        break;
      }
      case 71:
      if(on_check){
        if(channel_led != 3){
          digitalWrite(channel[channel_led+1],HIGH);
          closechannel(channel_led+1,channel);
          channel_led += 1;
          segment(channel_led);
        }
        Serial.println("next channel"); 
        break;
      }
      case 7:
      if(on_check){
        if(volume_num != 0){
          volume_num -= 1;
        }

        Serial.println("volume decreased");
        break;
      }
      case 21:
      if(on_check){
        if(volume_num != 50){
          volume_num += 1;
        }
        Serial.println("volume increased");
        break; 
      }
      case 22:
      if(on_check){
        digitalWrite(channel[0],HIGH);
        closechannel(0,channel);
        segment(0);
        channel_led = 0;
        Serial.println("CHANNEL 0");
        break; 
      }
      case 12:
      if(on_check){
        digitalWrite(channel[1],HIGH);
        closechannel(1,channel);
        segment(1);
        channel_led = 1;
        Serial.println("CHANNEL 1");
        break; 
      }
      case 24:
      if(on_check){
        digitalWrite(channel[2],HIGH);
        closechannel(2,channel);
        segment(2);
        channel_led = 2;
        Serial.println("CHANNEL 2");
        break; 
      }
      case 94:
      if(on_check){
        digitalWrite(channel[3],HIGH);
        closechannel(3,channel);
        segment(3);
        channel_led = 3;
        Serial.println("CHANNEL 3");
        break; 
      }
      /*case 8:
      if(on_check){
        digitalWrite(channel[4],HIGH);
        closechannel(4,channel);
        Serial.println("CHANNEL 4");
        break; 
      }
      case 28:
      if(on_check){
        digitalWrite(channel[5],HIGH);
        closechannel(5,channel);
        Serial.println("CHANNEL 5");
        break; 
      }*/
    }
    if(on_check){
     volume_led = volume_num / 10;
     for(int i = 0; i < volume_led; ++i){
      digitalWrite(volume[i],HIGH);
     }
     for(int i = volume_led ; i < sizeof(volume); ++i){
      digitalWrite(volume[i],LOW);
     }
    }
  }
}


void closechannel(int x,int channel[]){
  for(int i = 0; i<sizeof(channel)+2;i++){
    if(i==x){
      continue;
    }
    else{
      digitalWrite(channel[i],LOW);
    }
  }
}

void segment(int x){
  if(x == 0){
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,LOW);
  }
  else if(x==1){
    digitalWrite(a,LOW);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);
  }
  else if(x==2){
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,LOW);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,LOW);
    digitalWrite(g,HIGH);
  }
  else if(x==3){
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,HIGH);
  }
}

void alloff(){
    for(int i = 0; i<sizeof(channel)+2;i++){
      digitalWrite(channel[i],LOW);
    }
    for(int i = 0; i<sizeof(volume)+2;i++){
      digitalWrite(volume[i],LOW);
    }
    digitalWrite(a,LOW);
    digitalWrite(b,LOW);
    digitalWrite(c,LOW);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);
}
