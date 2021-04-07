#ifndef _LED_MATRIX_H
#define _LED_MATRIX_H

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <SoftwareSerial.h>
#define RX2 5
#define TX2 6		
 
#define redHeart      0       //红心
#define escortFlash   1       //护航动画
#define greenSmile    2       //绿色笑脸
#define blueShield    3       //蓝盾
#define patrolFlash   4       //巡逻动画（红色）
#define redArrow      5       //红色箭头
#define greenS        6       //绿色粗S，表示安全
#define sos         7       //SOS动画
#define greenInput    8       //绿色输入，表救援
#define charA       9       //字母A
#define charC       10      //字母C
#define charH       11      //字母H
#define charI       12      //字母I
#define charJ       13      //字母J
#define charN       14      //字母N
#define charU       15      //字母U
#define scrollArrow 17      //滚动绿箭头

#define escortFlashTime 4000
#define patrolFlashTime 4000
#define sosTime       4000




void led_matrix_init();
void open_flash(byte index);
void close_flash();
int flash_over_judge();
void sendSignal(byte num);

#endif
