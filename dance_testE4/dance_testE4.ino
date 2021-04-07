// Visual Micro is in vMicro>General>Tutorial Mode
//
/*
    Name:       dancing.ino
    Created:  2018/10/7 11:11:00
    Author:     LiuYang
*/

// Define User Types below here or use a .h file
//

//E2

#include <SoftwareSerial.h>
#include <Servo.h>
#include <Wire.h>
#include "schedule.h"
#include "xbee.h"
extern float angle;
//PIN
//jy61 - uno:
//TX     RXD
//VCC    5V
//GND    GND
//
//uno - nano:
//D10   10
//D11   11
//D12   12
//D13   13
//
//nano:
//right motor   8
//left motor    7
//right encoder 3
//left encoder  2

void setup()
{
  scheduleInit();
  Serial.begin(9600);
}

// Add the main program code into the continuous loop() function
//void loop()
//{
//  turn(90, right);
//  delay(2000);
//}


void loop()
{
  schedule();
  //  standBy();
  //  delay(2000);
  //  alongWall(160);
  //  turn(90,left);
  //  alongWall(160);
  //  turn(90,left);
  //  alongWall(160);
  //  turn(90,left);
  //  alongWall(160);
  //  turn(90,left);
}
