#include <Servo.h>
//1.Thr Spectre 2.Routine
//切歌一定要先暂停后才能切,所以在切歌函数里加了stop
//每次开启sound_on是从第一首开始
Servo motorL, motorR;
#define SOUND 2
#define SOUND_NEXT 3
#define SOUND_STOP 4
void setup()
{
  motorL.attach(7);
  motorR.attach(8);
  //motorL.write(90);
  //motorR.write(90);
  motorL.writeMicroseconds(1500);
  motorR.writeMicroseconds(1500);
}
void sound_init()
{
  pinMode(SOUND_NEXT, OUTPUT);
  digitalWrite(SOUND, LOW);
  pinMode(SOUND, OUTPUT);
  digitalWrite(SOUND_NEXT, LOW);


}
void sound_on()
{ digitalWrite(SOUND_STOP, LOW);
  digitalWrite(SOUND, HIGH);
  delay(1000);
  digitalWrite(SOUND, LOW);
}


void sound_next()
{
  sound_off();
  digitalWrite(SOUND_NEXT, HIGH);
  delay(1000);
  digitalWrite(SOUND_NEXT, LOW);

}


static int k = 0;
void sound_off()
{
  if (k == 0) {
    pinMode(SOUND_STOP, OUTPUT);
    k = 1;
    digitalWrite(SOUND_STOP, LOW);
  }
  else
  {
    digitalWrite(SOUND_STOP, HIGH);
    digitalWrite(SOUND_STOP, LOW);
  }
  //  digitalWrite(SOUND_STOP, HIGH);
  //  delay(1000);
  //  digitalWrite(SOUND_STOP, LOW);
}

void loop()
{
  sound_init();

  delay(10000);
  sound_next();
  delay(10000);
   sound_off();
   delay(5000);
   sound_on();

  while (1) {};

}
