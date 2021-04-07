#include "motor.h"

Servo motorL, motorR;
//extern float currentAngle;
extern float distance_cm;
extern int countLeft, countRight;
extern float angle;
float temp_angle, e, temp, aim_angle;

void motorInit() {
  motorL.attach(pinL);
  motorR.attach(pinR);
  motorL.writeMicroseconds(1500);
  motorR.writeMicroseconds(1500);
}



void turn(float angletoturn, int mode)
{
  detachInterrupt(0);
  detachInterrupt(1);
  get_angle();
  temp_angle = angle;
  if (angletoturn <= 90 && angletoturn > 0)  //对偏差进行手动调整
  {
    angletoturn -= angletoturn / 18;
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
      motorL.writeMicroseconds(1550);
      motorR.writeMicroseconds(1550);
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
      motorL.writeMicroseconds(1450);
      motorR.writeMicroseconds(1450);
    }
  }
  attachInterrupt(0, blinkLeft, CHANGE);
  attachInterrupt(1, blinkRight, CHANGE);
  motorL.writeMicroseconds(1500);
  motorR.writeMicroseconds(1500);
}

void alongLine(float setDistance)
{
  volatile float distanceLeft = 0, distanceRight = 0, e;
  volatile float leftSpeed = 1603, rightSpeed = 1405;
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


    //   e=e*2;
    Serial.println(e);
//    if (e - EPS >= 3)  //对两轮走的距离的偏差进行修正
//    {
//      leftSpeed = 1550;
//      rightSpeed = 1405;
//    }
//    else if (e + EPS <= -3)
//    {
//      leftSpeed = 1603;
//      rightSpeed = 1455;
//    }
//    else if (e - EPS >= -0.5 && e + EPS <= 0.5)
//    {
      leftSpeed = 1600;
      rightSpeed = 1405;
//    }
//    else if (e + EPS > -3 && e - EPS < -0.5)
//    {
//      leftSpeed = 1603 - e * 20;
//      rightSpeed = 1405 ;
//    }
//    else
//    {
//      leftSpeed = 1603 ;
//      rightSpeed = 1405 - e * 20;
//    }
    motorL.writeMicroseconds(leftSpeed);
    motorR.writeMicroseconds(rightSpeed);
    Serial.print("leftspeed: "); Serial.println(leftSpeed);
    Serial.print("rightspeed: "); Serial.println(rightSpeed);
    Serial.println();
  } while (actualDistance < setDistance);
  motorL.writeMicroseconds(1500);
  motorR.writeMicroseconds(1500);
}

void standBy()
{
  motorL.writeMicroseconds(1500);
  motorR.writeMicroseconds(1500);
}

//walk  along the wall to set distance
//void alongWall(float setDistance)
//{
//  float last, now, deviation;
//  float distanceLeft = 0, distanceRight = 0, actualDistance = 0;
//  countLeft = 0;
//  countRight = 0;
//  getDistance();
//  last = distance_cm;
//  while (setDistance > actualDistance) {
//    getDistance();
//    now = distance_cm;
//    distanceLeft = left_round * countLeft / 60;  //单位：cm
//    distanceRight = right_round * countRight / 60;
//    actualDistance = (distanceLeft + distanceRight) / 2;
//    deviation = now - last;
//    Serial.println(deviation);
//    if (deviation <= 0.05 && deviation >= -0.08)
//    {
//      motorL.writeMicroseconds(1605);
//      motorR.writeMicroseconds(1405);
//    }
//    else if (deviation < -0.08 && deviation > -0.5)
//    {
//      motorL.writeMicroseconds(1605);
//      motorR.writeMicroseconds(1415 - 100 * e);
//    }
//    else if (deviation <= -0.5)
//    {
//      motorL.writeMicroseconds(1605);
//      motorR.writeMicroseconds(1480);
//    }
//    else if (deviation < 0.5 && deviation > 0.05)
//    {
//      motorL.writeMicroseconds(1590 - 110 * e);
//      motorR.writeMicroseconds(1400);
//    }
//    else
//    {
//      motorL.writeMicroseconds(1540);
//      motorR.writeMicroseconds(1400);
//    }
//    last = now;
//    delay(55);
//  }
//}
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
    Serial.println(deviation);
    if (deviation <= 0.1 && deviation >= -0.05)
    {
      motorL.writeMicroseconds(1605);
      motorR.writeMicroseconds(1400);
    }
    else if (deviation < -0.05 && deviation > -0.5)
    {
      motorL.writeMicroseconds(1630);
      motorR.writeMicroseconds(1410 - deviation * 100);
    }
    else if (deviation <= -0.5)
    {
      motorL.writeMicroseconds(1660);
      motorR.writeMicroseconds(1410);
    }
    else if (deviation < 0.5 && deviation > 0.1)
    {
      motorL.writeMicroseconds(1580);
      motorR.writeMicroseconds(1400 - deviation * 100);
    }
    else
    {
      motorL.writeMicroseconds(1550);
      motorR.writeMicroseconds(1400);
    }
    last = now;
    delay(55);
  }
}
