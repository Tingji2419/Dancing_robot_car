#ifndef _MOTOR_H
#define _MOTOR_H

#include "Servo.h"
#include "compass.h"
#include "encoder.h"
#include "ult_wall.h"

#define pinL 7  // the number of pin
#define pinR 8
#define L_Speed 79
#define R_Speed 101
#define left 0
#define right 1

void motorInit();
//void motorCtrl(float eps);
void alongLine(float setDistance);
void alongWall(float setDistance);
void turn(float angletoturn,int mode);
void standBy();

#endif // !_MOTOR_H
