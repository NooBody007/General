
const int sw_pin = 2;
const int x_pin = 0;
const int y_pin = 1;

#define r 11
#define g 10
#define b 9

const int redX = 512;
const int redY = 1023;
const int greenX = 1023;
const int greenY = 0;
const int blueX = 0;
const int blueY = 0;



void setup() {
  pinMode(sw_pin, INPUT);
  digitalWrite(sw_pin,HIGH);
  Serial.begin(9600);

  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);

}

void loop() {
  int xaxis = analogRead(A0);
  int yaxis = analogRead(A1);

  //xaxis = map(xaxis, 0, 1023, 0, 1023);
  //yaxis = map(yaxis, 0, 1023, 1023, 0);

  int distanceRed = sqrt(pow(abs(redX - xaxis),2) + pow(abs(redY - yaxis), 2));
  int distanceGreen = sqrt(pow(abs(greenX - xaxis), 2) + pow(abs(greenY - yaxis),2));
  int distanceBlue = sqrt(pow(abs(blueX - xaxis), 2) + pow(abs(blueY - yaxis),2));

  int brightRed = 255 - constrain(map(distanceRed, 0 ,1023, 0, 255), 0, 255);
  int brightGreen = 255 - constrain(map(distanceGreen, 0, 1023, 0, 255), 0, 255);
  int brightBlue = 255 - constrain(map(distanceBlue, 0, 1023, 0, 255), 0, 255);

  if(digitalRead(sw_pin) == 0){
    brightRed = 255;
    brightGreen = 255;
    brightBlue = 255;
  }

  analogWrite(r, brightRed);
  analogWrite(g, brightGreen);
  analogWrite(b, brightBlue);

  Serial.print("Key: ");
  Serial.print(digitalRead(sw_pin));
  Serial.print(", X: ");
  Serial.print(xaxis);
  Serial.print(", Y: ");
  Serial.print(yaxis);
  Serial.print(", R: ");
  Serial.print(brightRed);
  Serial.print(", G: ");
  Serial.print(brightGreen);
  Serial.print(", B: ");
  Serial.print(brightBlue);
  Serial.println("\n");
  delay(100);
}
