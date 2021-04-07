#define SOUND 4
//#define SOUND_NEXT 3
//#define SOUND_STOP 4

void sound_init()
{
  //pinMode(SOUND_NEXT, OUTPUT);
  pinMode(SOUND, OUTPUT);
  digitalWrite(SOUND, LOW);
  //digitalWrite(SOUND_NEXT, LOW);


}
void sound_on()
{ //digitalWrite(SOUND_STOP, LOW);
  digitalWrite(SOUND, HIGH);
  delay(1000);
  digitalWrite(SOUND, LOW);
}


//void sound_next()
//{
//  sound_off();
//  delay(1000);
//  //digitalWrite(SOUND_NEXT, HIGH);
//  delay(1000);
// // digitalWrite(SOUND_NEXT, LOW);
//
//}


static int k = 0;
//void sound_off()
//{
//  if (k == 0) {
//    pinMode(SOUND_STOP, OUTPUT);
//    k = 1;
//    digitalWrite(SOUND_STOP, LOW);
//  }
//  else
//  {
//    digitalWrite(SOUND_STOP, HIGH);
//    digitalWrite(SOUND_STOP, LOW);
//  }
//  //  digitalWrite(SOUND_STOP, HIGH);
//  //  delay(1000);
//  //  digitalWrite(SOUND_STOP, LOW);
//}


void setup() {
  Serial.begin(9600);
}

void loop() {

//  sound_init();
//
//  sound_on();
//  /******************空指令*******************/
//  delay(43000);
//
//  Serial.flush();
//  Serial.write(0xA0);
//  Serial.flush();
  delay(15000);

  /*****************任务A********************/      //升旗

  Serial.flush();
  Serial.write(0xA1);//1号走到中间
  Serial.flush();
  delay(11000);
  Serial.flush();
  Serial.write(0xA2);//其他车左转45度
  Serial.flush();
  delay(5000);
  Serial.flush();
  Serial.write(0xA3);//所有车归位
  Serial.flush();
  delay(10000);

  //  /*****************任务B********************/    //护航

  Serial.flush();
  Serial.write(0xB1); //5号先走，4号跟随
  Serial.flush();
  delay(8000);
  Serial.flush();
  Serial.write(0xB2);//4,5交流
  Serial.flush();
  delay(4000);
  Serial.flush();
  Serial.write(0xB3);//4号返航，5号不动，其他归位
  Serial.flush();
  delay(16000);

  //  /*****************任务C********************/    //救援

  Serial.flush();
  Serial.write(0xC1);//1号走到5号旁边，劫持5号
  Serial.flush();
  delay(14000);
  Serial.flush();
  Serial.write(0xC2);//1，5交流
  Serial.flush();
  delay(5000);
  Serial.flush();
  Serial.write(0xC3);//走到目标区域
  Serial.flush();
  delay(10000);
  /****************************************************/
  Serial.flush();
  Serial.write(0xC4);//3号出列，转头 转向2
  Serial.flush();
  delay(10500);
  Serial.flush();
  Serial.write(0x41);//2回应
  Serial.flush();
  delay(3000);
  Serial.flush();
  Serial.write(0x43);//3再转头 转向4
  Serial.flush();
  delay(2000);
  Serial.flush();
  Serial.write(0x42);//4回应
  Serial.flush();
  delay(2000);
  Serial.flush();
  Serial.write(0x44);//3转回原位
  Serial.flush();
  delay(4000);

  Serial.flush();
  Serial.write(0xC5);//2，4巡逻，至1角
  Serial.flush();
  delay(5000);
  Serial.flush();
  Serial.write(0x51);//3转向2
  Serial.flush();
  delay(2000);
  Serial.flush();
  Serial.write(0x52);//2回应
  Serial.flush();
  delay(3000);
  Serial.flush();
  Serial.write(0x53);//3转向4
  Serial.flush();
  delay(2000);
  Serial.flush();
  Serial.write(0x54);//4回应
  Serial.flush();
  delay(3000);
  Serial.flush();
  Serial.write(0x55);//3转回原位
  Serial.flush();
  delay(2000);

  Serial.flush();
  Serial.write(0xC6);//2，4巡逻，至2角
  Serial.flush();
  delay(5000);
  Serial.flush();
  Serial.write(0x61);//3转向2
  Serial.flush();
  delay(2000);
  Serial.flush();
  Serial.write(0x62);//2回应
  Serial.flush();
  delay(3000);
  Serial.flush();
  Serial.write(0x63);//3转向4
  Serial.flush();
  delay(2000);
  Serial.flush();
  Serial.write(0x64);//4回应
  Serial.flush();
  delay(3000);
  Serial.flush();
  Serial.write(0x65);//3转回原位
  Serial.flush();
  delay(2000);

  Serial.flush();
  Serial.write(0xC7);//2，4巡逻，至终点
  Serial.flush();
  delay(4000);
  Serial.flush();
  Serial.write(0x71);//4警告
  Serial.flush();
  delay(3000);
  Serial.flush();
  Serial.write(0x72);//3回应
  Serial.flush();
  delay(11000);


  Serial.flush();
  Serial.write(0xC8);//3号面向1号，1号转向3号，发出警告
  Serial.flush();
  delay(7000);
  Serial.flush();
  Serial.write(0xC9);//2，3，4包围1号，1号投降
  Serial.flush();
  delay(10000);
  Serial.flush();
  Serial.write(0xCA);//4，5成列，发信号安全
  Serial.flush();
  delay(10000);
  Serial.flush();
  Serial.write(0xCB);//1，2，3成列，
  Serial.flush();
  delay(10000);
  Serial.flush();
  Serial.write(0xCC);//全体归位
  Serial.flush();
  delay(80000);
  //
  //  /*****************任务D********************/     //谢幕
  //
  //  Serial.flush();
  //  Serial.write(0xD1);//谢幕动画
  //  Serial.flush();
  //  Serial.flush();
  //  Serial.write(0xD2);
  //  Serial.flush();
  //  Serial.flush();
  //  Serial.write(0xD3);
  //  Serial.flush();
  //  delay(8000);
}
