#include "motor.h"


Servo motorL, motorR;
extern int countLeft, countRight;
extern float distance_cm;
extern float angle;
float temp_angle, e, temp, aim_angle;

void motorInit() {
  motorL.attach(pinL);
  motorR.attach(pinR);
  motorL.write(90);
  motorR.write(90);
}

void alongLine(float setDistance)
{
  volatile float distanceLeft = 0, distanceRight = 0, e;
  volatile float leftSpeed = 120, rightSpeed = 60;
  float actualDistance = 0;
  countLeft = 0;
  countRight = 0;
  do {
    distanceLeft = left_round * countLeft / 60;  //单位：cm
    distanceRight = right_round * countRight / 60;
    //    Serial.print(countLeft);
    //    Serial.print(' ');
    //    Serial.print(countRight);
    //    Serial.print(' ');
    //    Serial.print(distanceLeft);
    //    Serial.print(' ');
    //    Serial.println(distanceRight);
    actualDistance = (distanceLeft + distanceRight) / 2;
    e = distanceLeft - distanceRight;
    if (e - EPS >= 3)  //对两轮走的距离的偏差进行修正
    {
      leftSpeed = 92;
      //rightSpeed = 80;
      rightSpeed = 78;
    }
    else if (e + EPS <= -3)
    {
      leftSpeed = 100;
      rightSpeed = 88;
    }
    else if (e - EPS >= -0.5 && e + EPS <= 0.5)
    {
      leftSpeed = 100;
      //rightSpeed = 80;
      rightSpeed = 78;
    }
    else if (e + EPS > -3 && e - EPS < -0.5)
    {
      leftSpeed = 100;
      rightSpeed = 82.0 - e * 2.0;
    }
    else
    {
      leftSpeed = 98.0 - e * 2.0;
      //rightSpeed = 80;
      rightSpeed = 78;
    }
    motorL.write(leftSpeed);
    motorR.write(rightSpeed);
  } while (actualDistance < setDistance);
  motorL.write(90);
  motorR.write(90);
}

//walk along the wall to set distance
void alongWall(float setDistance)
{
  float last, now, deviation;
  float distanceLeft = 0, distanceRight = 0, actualDistance = 0;
  countLeft = 0;
  countRight = 0;
  getDistance();
  last = distance_cm;
  while (setDistance > actualDistance) {
    getDistance();
    Serial.println(deviation);
    now = distance_cm;
    distanceLeft = left_round * countLeft / 60;  //单位：cm
    distanceRight = right_round * countRight / 60;
    actualDistance = (distanceLeft + distanceRight) / 2;
    deviation = now - last;
    //Serial.print("  ");
    Serial.println(deviation);
    if (deviation <= 0.05 && deviation >= -0.1)
    {
      motorL.write(100);

      motorR.write(80);
    }
    else if (deviation < -0.1 && deviation > -0.5)
    {
      motorL.write(100 + deviation * 8);
      motorR.write(80);

    }
    else if (deviation <= -0.5)
    {
      motorL.write(96);
      motorR.write(80);
    }
    else if (deviation < 0.5 && deviation > 0.05)
    {
      motorL.write(100);
      motorR.write(82 + deviation * 8);
    }
    else
    {
      motorL.write(103);
      motorR.write(84);
    }

    last = now;
    delay(55);
  }
}

void turn(float angletoturn, int mode)
{
  detachInterrupt(0);
  detachInterrupt(1);
  get_angle();
  temp_angle = angle;
  if (angletoturn <= 90 && angletoturn > 0)  //对偏差进行手动调整
  {
    angletoturn -= angletoturn / 16;
  }
  else if (angletoturn > 90 && angletoturn <= 180)
  {
    angletoturn -= angletoturn / 24;
  }
  if (mode)
  {
    /*右转*/
    aim_angle = temp_angle - angletoturn - 2;
    if (aim_angle < -1e-7)
    {
      aim_angle += 360;
    }
    while (1)
    {
      get_angle();
      if (fabs(aim_angle - angle) < 1.0) {
        break;
      }
      //e = fabs(temp_angle - angle) / angletoturn * 10;
      motorL.write(95);
      motorR.write(95);
    }
  }
  else
  {
    /*左转*/
    aim_angle = temp_angle + angletoturn;
    if (aim_angle >= 360)
    {
      aim_angle -= 360;
    }
    while (1)
    {
      get_angle();
      if (fabs(aim_angle - angle) < 1.0) {
        break;
      }
      //e = fabs(temp_angle - angle) / angletoturn * 10;
      motorL.write(85);
      motorR.write(85);
    }
  }
  attachInterrupt(0, blinkLeft, CHANGE);
  attachInterrupt(1, blinkRight, CHANGE);
  motorL.write(90);
  motorR.write(90);
  //standBy();
  //delay(100);
}

void standBy()
{
  motorL.write(90);
  motorR.write(90);
}
