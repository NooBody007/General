
int a = 11;
int b = 10;
int c = 7;
int d = 8;
int e = 9;
int f = 12;
int g = 13;
int dp = 6;

int buttonpin = 2;
bool btnpress = false;


int btn_counter = 0;
int btn_state = 0;
int last_btn_state = 0;




void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(dp, OUTPUT);

  pinMode(buttonpin, INPUT_PULLUP);
  Serial.begin(9600);
  DisplayDigit(btn_counter);
}

void loop() {

  btn_state = digitalRead(buttonpin);

  //compare btn state to previous state
  if (btn_state != last_btn_state){
    if(btn_state == LOW){
      btnpress = true;
      btn_counter++;
      if(btn_counter > 9) btn_counter = 0;
      Serial.println("ON");
    }
    else{
      Serial.println("OFF");
    }
    delay(50);
  }
  
  last_btn_state = btn_state;

  if(btnpress){
    turnoff();
    DisplayDigit(btn_counter);
  }
}



void DisplayDigit(int digit){
  
  //Conditions for a
  if(digit != 1 && digit != 4){
    digitalWrite(a,HIGH);
  }
  
  //Conditions for b
  if(digit != 5 && digit != 6){
    digitalWrite(b,HIGH);
  }
  
  //Conditions for c
  if(digit != 2){
    digitalWrite(c,HIGH);
  }

  //Conditions for d
  if(digit != 1 && digit != 4 && digit != 7){
    digitalWrite(d, HIGH);
  }

  //Conditions for e
  if(digit == 2 || digit == 6 || digit == 8 || digit == 0){
    digitalWrite(e,HIGH);
  }

  //Conditions for f
  if(digit != 1 && digit != 2 && digit != 3 && digit != 7){
    digitalWrite(f,HIGH);
  }

  //Conditions for g
  if(digit!= 0 && digit != 1 && digit != 7){
    digitalWrite(g,HIGH);
  }
}

void turnoff(){
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}
