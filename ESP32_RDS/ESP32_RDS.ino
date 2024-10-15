#include<ESP32Servo.h>

Servo base, lower, upper, gripper;

void setup() {

  base.attach(32, 500, 1800);
  lower.attach(25, 500, 1800);
  upper.attach(27, 500, 1800);
  gripper.attach(12, 500, 1800);

  base.write(90);
  lower.write(0);
  upper.write(0);
  gripper.write(0);

  Serial.begin(9600);
  
}

void loop() {
  
}
