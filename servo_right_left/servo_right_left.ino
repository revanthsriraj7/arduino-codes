#include<Servo.h>
Servo servo;
int ini = 90;

void setup() {
  servo.attach(9);
  servo.write(ini);
  }

void loop() {
  for(int pos = ini; pos<=ini+100; pos++)
  {
    servo.write(pos);
    delay(15);
  }
  servo.write(90);
  delay(2000);

  for(int pos = ini; pos>=ini-60; pos--)
  {
    servo.write(pos);
    delay(15);
  }
  delay(2000);
  servo.write(90);
  delay(2000);
}
