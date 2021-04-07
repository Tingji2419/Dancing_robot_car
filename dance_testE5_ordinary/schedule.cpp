#include "schedule.h"

//extern int mode;
//extern byte command[2];

void schedule_init()
{
  encoderInit();
  motorInit();
  ultrasonic_init();
  compassInit();
  xbee_init();
  led_matrix_init();
  pinMode(ledpin, OUTPUT);
  digitalWrite(ledpin, LOW);
}

void flash(int times)
{
  int i;
  for (i = 0; i < times; i++)
  {
    digitalWrite(ledpin, HIGH);
    delay(300);
    digitalWrite(ledpin, LOW);
    delay(300);
  }
}

void schedule()
{
  byte c1 = -1;
  c1 = getCommand();
  // Serial.write(c1);
  if (c1 != -1)
    command_execute(c1);
}

void command_execute(byte c)
{
  switch (c)
  {
    /*************************调试代码***********************************/
    case 0x90:
      standBy();
      break;
    /*******************************任务1***********************************/
    case 0xA1:
      sendSignal('5');//在此添加调试动作
      standBy();
      break;
      
    case 0xA2:
      delay(100);
      turn(45, left);
      delay(500);
      digitalWrite(ledpin,HIGH);
      standBy();
      break;
      
    case 0xA3:
    digitalWrite(ledpin,LOW);
      turn(45, right);
      standBy();
      break;
    /************************任务2***********************************/
    case 0xB1:
     flash(2);
      alongWall(15);
      delay(1000);
      turn(45, left);
      sendSignal('Q');//?
     delay(500);
      flash(2);
      delay(3000);
      sendSignal('V');//笑脸
      turn(45, right);
      delay(1000);
      alongWall(50);
      standBy();
      break;
      
    case 0xB2:
      //LED
      //   sendSignal(0x01);//在此添加调试动作
      turn(45, left);
      flash(2);
      delay(2500);
      turn(45, right);
      standBy();
      break;
      
    case 0xB3:
    //   sendSignal(0x01);//在此添加调试动作
      standBy();
      break;
    ///************************任务3***********************************/
    case 0xC1:
      //turn(45,left);
      //   sendSignal(0x01);//在此添加调试动作
      standBy();
      break;
      
    case 0xC2:
      //LED
      sendSignal('Y');
      sendSignal('U');//在此添加调试动作
      turn(45,left);
      delay(500);
      digitalWrite(ledpin,HIGH);
       delay(200);
       digitalWrite(ledpin,LOW);
       delay(200);
       digitalWrite(ledpin,HIGH);
       delay(200);
       digitalWrite(ledpin,LOW);
       delay(200);
       digitalWrite(ledpin,HIGH);
       delay(200);
       digitalWrite(ledpin,LOW);
      turn(45,right);
      standBy();
      break;
      
    case 0xC3:
      //SOS
      sendSignal('S');//在此添加调试动作
      alongWall(75);
      standBy();
      break;

    case 0xC4:
    //   sendSignal(0x01);//在此添加调试动作
      standBy();
      break;
    case 0xC5:
    //   sendSignal(0x01);//在此添加调试动作
      standBy();
      break;

    case 0xC6:
    //   sendSignal(0x01);//在此添加调试动作
      standBy();
      break;
      
    case 0xC7:
    //   sendSignal(0x01);//在此添加调试动作
      standBy();
      break;
      
    case 0xC8:
    //   sendSignal(0x01);//在此添加调试动作
      standBy();
      break;
      
    case 0xC9:
    //   sendSignal(0x01);//在此添加调试动作
      standBy();
      break;
      
    case 0xCA:
    sendSignal('V');//在此添加调试动作
      turn(90, left);
      alongWall(160);
      turn(90, left);
      alongWall(90);
      standBy();
      break;
      
    case 0xCB:
   sendSignal('V');//在此添加调试动作
      standBy();
      break;
      
    case 0xCC:
   sendSignal('V');//在此添加调试动作
      alongWall(55);
      turn(88, left);
      alongWall(165);
      turn(88, left);
      alongWall(25);
      turn(88, left);
      standBy();
      break;
    /************************任务4***********************************/
    
  }
}
