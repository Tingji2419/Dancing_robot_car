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
  byte c;
  c = getCommand();
  if (-1 != c)
    command_execute(c);
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
      sendSignal('3');//在此添加调试动作
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
    /************************任务2***********************************/
    case 0xB1:
      delay(1000);
      turn(45, right);
      delay(500);
      digitalWrite(ledpin, HIGH);
      standBy();
      break;

    case 0xB2:
      //   sendSignal(0x01);//在此添加调试动作
      standBy();
      break;

    case 0xB3:
      //   sendSignal(0x01);//在此添加调试动作
      digitalWrite(ledpin, LOW);
      turn(43, left);
      break;
    ///************************任务3***********************************/
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
      flash(2);
      delay(1000);
      alongLine(70);
      delay(1000);
      turn(148, left);
      sendSignal('Q');
      delay(500);
      //   sendSignal(0x01);//在此添加调试动作
      digitalWrite(ledpin, HIGH);
      //LED
      standBy();
      break;

    case 0x43:
      digitalWrite(ledpin, LOW);
      turn(60, left);
      delay(500);
      sendSignal('Q');//在此添加调试动作
      delay(1000);
      digitalWrite(ledpin, HIGH);
      standBy();
      break;

    case 0x44:
      //   sendSignal(0x01);//在此添加调试动作
      digitalWrite(ledpin, LOW);
      sendSignal('X');
      turn(148, left);
      standBy();
      break;

    case 0xC5:
      sendSignal('X');//在此添加调试动作
      standBy();
      break;

    case 0x51:
      //   sendSignal(0x01);//在此添加调试动作

      turn(135, left);
      sendSignal('Q');
      delay(1000);
      digitalWrite(ledpin, HIGH);
      standBy();
      break;

    case 0x53:
      sendSignal('X');
      digitalWrite(ledpin, LOW);
      turn(90, left);
      delay(500);
      sendSignal('Q');//在此添加调试动作
      delay(1000);
      digitalWrite(ledpin, HIGH);
      standBy();
      break;

    case 0x55:
      digitalWrite(ledpin, LOW);
      sendSignal('X');
      turn(130, left);
      standBy();
      break;

    case 0xC6:
      sendSignal('X');
      standBy();
      break;

    case 0x61:
      turn(90, left);
      delay(700);
      sendSignal('Q');//在此添加调试动作
      delay(1000);
      digitalWrite(ledpin, HIGH);
      standBy();
      break;

    case 0x63:
      digitalWrite(ledpin, LOW);
      turn(180, left);
      delay(500);
      sendSignal('Q');//在此添加调试动作
      delay(1000);
      digitalWrite(ledpin, HIGH);
      standBy();
      break;

    case 0x65:
      sendSignal('X');
      digitalWrite(ledpin, LOW);
      turn(85, left);
      standBy();
      break;

    case 0xC7:
      sendSignal('X');
      standBy();
      break;

    case 0x72:
      //LED
      flash(3);
      delay(1000);
      turn(90, right);
      sendSignal('W');
      delay(1000);
      turn(90, right);
      delay(1000);
      turn(90, right);
      delay(1000);
      turn(88, right);
      flash(2);
      standBy();
      break;


    case 0xC8:
      sendSignal('Y');
      turn(45, right);
      standBy();
      break;

    case 0xC9:
      sendSignal('X');
      alongLine(30);
      standBy();
      break;

    case 0xCA:
      sendSignal('X');
      standBy();
      break;

    case 0xCB:
      sendSignal('X');
      turn(43, right);
      alongLine(40);
      turn(90, right);
      alongWall(15);
      standBy();
      break;

    case 0xCC:
      sendSignal('X');
      turn(88, left);
      alongLine(20);
      turn(180, left);
      standBy();
      break;
      /************************任务4***********************************/

  }
}
