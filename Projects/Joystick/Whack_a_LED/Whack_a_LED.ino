
int x = A0;
int y = A1;

int ssx;  //state of x
int ssy;  //state of y
int ss;   //converted state

int rnum;   //random number
int wins = 0;
int highScore = 0;

const int easy = 1000;
const int medium = 500;
const int hard = 325;
const int stupid = 250;

int ledpins[] = {5,2,4,3,6,7,8};
int pincount = 7;


void setup() {

  Serial.begin(9600);
  pinMode(x,INPUT);
  pinMode(y,INPUT);

  for(int i = 0; i<pincount; i++){
    pinMode(ledpins[i],OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

  rnum = random(4);
  delay(1000);
  digitalWrite(ledpins[rnum],HIGH);
  delay(easy);

  ssx = analogRead(x);
  delay(100);
  ssy = analogRead(y);

  ss = 0;
  switch(ssx){
    case 0:
    ss = 1;
    break;
    case 1023:
    ss = 2;
    break;
  }
  switch(ssy){
    case 0:
    ss = 3;
    break;
    case 1023:
    ss = 4;
    break;
  }
  digitalWrite(ledpins[rnum],LOW);
  if(ss-1==rnum){
    wins++;
    for(int i = 0; i<=3; i++){
      digitalWrite(ledpins[4],HIGH);
      delay(50);
      digitalWrite(ledpins[4],LOW);
      delay(50);
    }
  }
  else{
    if(wins>highScore){
      highScore = wins;
      wins = 0;
    }
    for(int i = 0; i<=3; i++){
      digitalWrite(ledpins[5],HIGH);
      delay(50);
      digitalWrite(ledpins[5],LOW);
      delay(50);
    }
    for(int i = 0; i<highScore; i++){
      digitalWrite(ledpins[6], HIGH);
      delay(200);
      digitalWrite(ledpins[6],LOW);
      delay(200);
    }
      
    }
  }
