#include "led_matrix.h"

SoftwareSerial led_matrix_Serial(5, 6);  //A1, A2

void led_matrix_init()
{
  led_matrix_Serial.begin(9600);
}

void sendSignal(byte num)
{
  led_matrix_Serial.flush();
  led_matrix_Serial.write(num);
  led_matrix_Serial.flush();
}

