#include "motor.h"

Servo motorL, motorR;
extern int countLeft, countRight;
extern float distance_cm;
extern float angle;
float temp_angle, e, temp, aim_angle;

void motorInit() {
  motorL.attach(pinL);
  motorR.attach(pinR);
  motorL.write(91);
  motorR.write(90);
}

void alongLine(float setDistance)
{
  volatile float distanceLeft = 0, distanceRight = 0, e;
  volatile float leftSpeed = 102, rightSpeed = 81;
  float actualDistance = 0;
  countLeft = 0;
  countRight = 0;
  do {
    distanceLeft = left_round * countLeft / 60;  //单位：cm
    distanceRight = right_round * countRight / 60;
    actualDistance = (distanceLeft + distanceRight) / 2;
    e = distanceLeft - distanceRight;
    Serial.print("left: "); Serial.println(countLeft);
    Serial.print("right: "); Serial.println(countRight);
    Serial.println(e);
    if (e - EPS >= 3)  //对两轮走的距离的偏差进行修正
    {
      leftSpeed = 94;
      rightSpeed = 81;
    }
    else if (e + EPS <= -3)
    {
      leftSpeed = 120;
      rightSpeed = 89;
    }
    else if (e - EPS >= -0.5 && e + EPS <= 0.5)
    {
      leftSpeed = 102;
      rightSpeed = 81;
    }
    else if (e + EPS > -3 && e - EPS < -0.5)
    {
      leftSpeed = 102;
      rightSpeed = 83.0 - e * 2.0;
    }
    else
    {
      leftSpeed = 100.0 - e * 2.5;
      rightSpeed = 81;
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
    now = distance_cm;
    distanceLeft = left_round * countLeft / 60;  //单位：cm
    distanceRight = right_round * countRight / 60;
    actualDistance = (distanceLeft + distanceRight) / 2;
    deviation = now - last;
    //Serial.println(deviation);
    if (deviation <= 0.1 && deviation >= -0.1)
    {
      motorL.write(102);
      motorR.write(80);
    }
    else if (deviation < -0.1 && deviation > -0.5)
    {
      //motorL.write(100);
      //motorR.write(83);
      motorL.write(102 - deviation * 5);
      motorR.write(84);
    }
    else if (deviation <= -0.5)
    {
      //motorL.write(100);
      //motorR.write(85);
      motorL.write(106);
      motorR.write(84);
    }
    else if (deviation < 0.5 && deviation > 0.1)
    {
      motorL.write(102 - deviation * 8);
      motorR.write(80);
    }
    else
    {
      motorL.write(95);
      motorR.write(80);
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
    angletoturn -= angletoturn / 23;
  }
  if (mode)
  {
    /*右转*/
    aim_angle = temp_angle - angletoturn;
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
  //    motorL.write(90);
  //    motorR.write(90);
  standBy();
  delay(100);
}

void standBy()
{
  motorL.write(91);
  motorR.write(90);
}
