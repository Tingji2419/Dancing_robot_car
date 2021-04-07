#include<SoftwareSerial.h>
int f=1;
SoftwareSerial mySerial(10, 11);
/*
 每一次开始前需要将屏幕复位，不然升旗动画不会从头开始播放
 * */
void Wait(){
  byte wait[9]={0xEE,0xB1,0x00,0x00,0x00,0xFF,0xFC,0xFF,0xFF};
  for(int i=0;i<9;i++){
   mySerial.write(wait[i]);
 }
}//初始界面，没有国旗的旗杆

void Raise(){
  byte rise[9]={0xEE,0xB1,0x00,0x00,0x01,0xFF,0xFC,0xFF,0xFF};
  for(int i=0;i<9;i++){
   mySerial.write(rise[i]);
 }
}//开始升旗，过程30秒

void Escort(){
  byte Top[9]={0xEE,0xB1,0x00,0x00,0x03,0xFF,0xFC,0xFF,0xFF};
  for(int i=0;i<9;i++){
   mySerial.write(Top[i]);
 }
}//护航图片

void Patrol(){
  byte Top[9]={0xEE,0xB1,0x00,0x00,0x04,0xFF,0xFC,0xFF,0xFF};
  for(int i=0;i<9;i++){
   mySerial.write(Top[i]);
 }
}//巡逻图片

void Rescure(){
  byte Top[9]={0xEE,0xB1,0x00,0x00,0x05,0xFF,0xFC,0xFF,0xFF};
  for(int i=0;i<9;i++){
   mySerial.write(Top[i]);
 }
}//救援图片

void Finish(){
  byte Top[9]={0xEE,0xB1,0x00,0x00,0x06,0xFF,0xFC,0xFF,0xFF};
  for(int i=0;i<9;i++){
   mySerial.write(Top[i]);
 }
}//完成图片

void TheEnd(){
  byte Top[9]={0xEE,0xB1,0x00,0x00,0x07,0xFF,0xFC,0xFF,0xFF};
  for(int i=0;i<9;i++){
   mySerial.write(Top[i]);
 }
}//谢幕图片

 void setup() {
 mySerial.begin(9600);
 Wait();
}
 
void loop() {
  delay(3000);
  Raise();
  delay(35000);
  Escort();
  delay(3000);
  Patrol();
  delay(3000);
  Rescure();
  delay(3000);
  Finish();
  delay(3000);
  TheEnd();
  delay(30000);//test
}
