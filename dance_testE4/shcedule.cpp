#include "schedule.h"

int mode = 0;
byte command[2];

void scheduleInit()
{
  compassInit();
  encoderInit();
  motorInit();
  ledMatrixInit();
  xbee_init();
  pinMode(15, OUTPUT);
  digitalWrite(15, LOW);
  ultrasonic_init();
}

void schedule()
{
  byte c;
  //print_data(2000);
  //write_parameter();      这两行代码是用来调参数的
  //  if (mode == 0){
  //    command[1] = command[0] = getCommand();
  //  }
  //  if (command[1] < 0xFF)
  //  {
  //    for (c = command[0]; c <= command[1]; c++)
  //    {
  c = getCommand();
  if (-1 != c)
    command_execute(c);
  //    }
  //    command[0] = command[1] = -1;
  //  }
}

void turnRound(int a)
{
  if (a)
  {
    turn(180, right);
    turn(180, right);
    turn(20, right);
  }
  else
  {
    turn(180, left);
    turn(180, left);
    turn(20, left);
  }
}

void flash(int times)
{
  int i;
  for(i=0;i<times;i++)
  {
    digitalWrite(ledpin,HIGH);
    delay(300);
    digitalWrite(ledpin,LOW);
    delay(300);
  }
}

void command_execute(byte c)      //任务执行函数 c是从受到的协调器的命令
{
  switch (c)
  {
    /*************************调试代码***********************************/
    case 0x90:
         standBy();
      break;

    /*******************************任务1***********************************/
    case 0xA1:
   sendSignal('4');//在此添加调试动作
      standBy();
      break;

    case 0xA2:
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

    /*******************************任务2***********************************/
    case 0xB1:
    //   sendSignal(0x01);//在此添加调试动作
      delay(5000);
      turn(45, right);
      delay(500);
      flash(2);
      sendSignal('P');//在此添加调试动作
      sendSignal('X');
      turn(45, left);
      delay(2800);
      alongWall(60);
      standBy();
      break;

    case 0xB2:
      //LED
      sendSignal('X');//在此添加调试动作
      delay(800);
      turn(45, right);
      delay(500);
      flash(2);
      delay(2500);
      standBy();
      break;
      
    case 0xB3:
    sendSignal('X');//在此添加调试动作
      turn(130, right);
      alongLine(60);
      turn(180, left);
      standBy();
      break;

    /*******************************任务3***********************************/
    case 0xC1:
    //   sendSignal(0x01);//在此添加调试动作
      standBy();
      break;

    case 0xC2:
    //   sendSignal(0x01);//在此添加调试动作
      standBy();
      break;

    case 0xC3:
    //   sendSignal(0x01);//在此添加调试动作
      standBy();
      break;

    case 0xC4:
    sendSignal('X');//在此添加调试动作
      standBy();
      break;

    case 0x42:
  sendSignal('X');//在此添加调试动作
      turn(30, left);
      //LED
       delay(500);
      digitalWrite(ledpin,HIGH);
      delay(1000);
      digitalWrite(ledpin,LOW);
      turn(30, right);
      standBy();
      break;

    case 0xC5:
    sendSignal('X');//在此添加调试动作
      turn(95, right);
      delay(200);
      alongWall(45);
      standBy();
      break;
      
    case 0x54:
    sendSignal('X');//在此添加调试动作
      turn(135, left);
      delay(1000);
      digitalWrite(ledpin,HIGH);
      delay(1000);
      digitalWrite(ledpin,LOW);
      turn(47, right);
      standBy();
      break;

    case 0xC6:
   sendSignal('X');
    alongWall(60);
      standBy();
      break;
      
    case 0x64:
   sendSignal('X');
      turn(88, left);
      delay(1500);
      digitalWrite(ledpin,HIGH);
      delay(1000);
      digitalWrite(ledpin,LOW);
      standBy();
      break;

    case 0xC7:
   sendSignal('X');
      alongLine(45);
      standBy();
      break;
    case 0x71:
      //LED
      sendSignal('Y');//在此添加调试动作
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
      delay(200);
       digitalWrite(ledpin,HIGH);
      delay(200);
      digitalWrite(ledpin,LOW);
      turn(90,right);
      standBy();
      break;

    case 0xC8:
   sendSignal('X');//在此添加调试动作
      standBy();
      break;

    case 0xC9:
  sendSignal('X');//在此添加调试动作
      turn(88, right);
      alongLine(45);
      turn(88, left);
      alongWall(40);
      standBy();
      break;

    case 0xCA:
   sendSignal('X');//在此添加调试动作
      alongWall(63);
      turn(90, left);
      alongWall(160);
      turn(90, left);
      alongWall(40);
      standBy();
      break;

    case 0xCB:
  sendSignal('X');
      standBy();
      break;

    case 0xCC:
   sendSignal('X');
      alongWall(120);
      turn(90, left);
      alongWall(160);
      turn(180, left);
      standBy();
      break;
      /*******************************任务4***********************************/
      //case 0xD:  

  }
}
