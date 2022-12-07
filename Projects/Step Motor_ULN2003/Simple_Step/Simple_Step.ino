#define A 2
#define B 3
#define C 4
#define D 5
#define number_of_steps_per_rev 512

void setup() {
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
}

void loop() {
  int i=0;
  while(i<number_of_steps_per_rev/2){
    onestep();
    ++i;
  }
  while(i<number_of_steps_per_rev){
    reversestep();
    ++i;
  }
}


void Write(int a, int b, int c, int d){
  digitalWrite(A,a);
  digitalWrite(B,b);
  digitalWrite(C,c);
  digitalWrite(D,d);
}

void onestep(){
  Write(1,0,0,0);
  delay(5);
  Write(1,1,0,0);
  delay(5);
  Write(0,1,0,0);
  delay(5);
  Write(0,1,1,0);
  delay(5);
  Write(0,0,1,0);
  delay(5);
  Write(0,0,1,1);
  delay(5);
  Write(0,0,0,1);
  delay(5);
  Write(1,0,0,1);
  delay(5);
}

void reversestep(){
  Write(1,0,0,1);
  delay(5);
  Write(0,0,0,1);
  delay(5);
  Write(0,0,1,1);
  delay(5);
  Write(0,0,1,0);
  delay(5);
  Write(0,1,1,0);
  delay(5);
  Write(0,1,0,0);
  delay(5);
  Write(1,1,0,0);
  delay(5);
  Write(1,0,0,0);
  delay(5);
}
