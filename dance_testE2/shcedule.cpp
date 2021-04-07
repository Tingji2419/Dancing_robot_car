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
  c = getCommand();
  if (-1 != c)
    command_execute(c);
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
  for (i = 0; i < times; i++)
  {
    digitalWrite(ledpin, HIGH);
    delay(300);
    digitalWrite(ledpin, LOW);
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
      sendSignal('2');//在此添加调试动作
      standBy();
      break;

    case 0xA2:
      turn(45, left);
      delay(500);
      digitalWrite(ledpin, HIGH);
      standBy();
      break;

    case 0xA3:
      digitalWrite(ledpin, LOW);
      turn(45, right);
      standBy();
      break;

    /*******************************任务2***********************************/
    case 0xB1:
      delay(1000);
      turn(45, right);
      //   sendSignal(0x01);//在此添加调试动作
      delay(500);
      digitalWrite(ledpin, HIGH);
      standBy();
      break;
    case 0xB2:
      //   sendSignal(0x01);//在此添加调试动作
      standBy();
      break;

    case 0xB3:
      digitalWrite(ledpin, LOW);
      turn(45, left);
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

    case 0x41:
      turn(30, right);
      sendSignal('X');//在此添加调试动作
      //LED
      delay(500);
      digitalWrite(ledpin, HIGH);
      delay(1000);
      digitalWrite(ledpin, LOW);
      turn(30, left);
      standBy();
      break;

    case 0xC5:
      turn(90, left);
      sendSignal('X');//在此添加调试动作
      delay(100);
      alongWall(35);
      standBy();
      break;

    case 0x52:
      turn(135, right);
      delay(1000);
      sendSignal('X');//在此添加调试动作
      digitalWrite(ledpin, HIGH);
      delay(1000);
      digitalWrite(ledpin, LOW);
      turn(45, left);
      standBy();
      break;

    case 0xC6:
      sendSignal('X');//在此添加调试动作
      alongWall(50);
      standBy();
      break;
    case 0x62:
      turn(85, right);
      delay(1000);
      sendSignal('X');//在此添加调试动作
      digitalWrite(ledpin, HIGH);
      delay(1000);
      digitalWrite(ledpin, LOW);
      standBy();
      break;

    case 0xC7:
      sendSignal('X');//在此添加调试动作
      alongLine(40);
      turn(92, left);
      standBy();
      break;

    case 0xC8:
      sendSignal('X');//在此添加调试动作
      standBy();
      break;

    case 0xC9:
      sendSignal('X');//在此添加调试动作
      alongWall(50);
      turn(82, right);
      alongWall(30);
      standBy();
      break;

    case 0xCA:
      sendSignal('X');
      standBy();
      break;

    case 0xCB:
      sendSignal('X');
      delay(1500);
      turn(87, left);
      alongLine(18);
      turn(90, right);
      delay(200);
      alongWall(45);
      turn(90, right);
      standBy();
      break;

    case 0xCC:
      sendSignal('X');
      turn(90, left);
      alongLine(20);
      turn(180, left);
      standBy();
      break;

      /*******************************任务4***********************************/
      //case 0xD:   还没想好

  }
}
