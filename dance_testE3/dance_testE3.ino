#include <SoftwareSerial.h>
#include <Servo.h>
#include <Wire.h>
#include "schedule.h"
#include "xbee.h"

void setup() {
  schedule_init();
}

void loop() {
  schedule();
//  standBy();
//  delay(2000);
//  alongLine(100);
}
