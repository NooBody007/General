#include <virtuabotixRTC.h>

virtuabotixRTC clk(6,7,8);  //clk data rst

String Days[] = {"Monday", "Tuesday", "Wednesday", "Thirsday", "Friday", "Saturday", "Sunday"};

void setup() {
  //clk.setDS1302Time(0,51,14,7,4,9,2022);     //setting up the time seconds,minutes, hours, dayofweek,dayofmonth,month,year
  Serial.begin(9600);
}

void loop() {
  clk.updateTime();
  Serial.print(clk.hours);
  Serial.print(":");
  Serial.print(clk.minutes);
  Serial.print(":");
  Serial.print(clk.seconds);
  Serial.print(" ");
  Serial.print(clk.dayofmonth);
  Serial.print("/");
  Serial.print(clk.month);
  Serial.print("/");
  Serial.print(clk.year);
  Serial.print(" ");
  Serial.println(Days[clk.dayofweek - 1]);
  delay(1000);

}
