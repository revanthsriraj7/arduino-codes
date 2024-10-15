#include <ESP32Servo.h>

#define num_servos 4

Servo servos[num_servos];
int servoPins[num_servos] = {32, 33, 25, 26};

int servoTargets[num_servos] = {180, 180, 180, 180}; 
int servoAngles[num_servos] = {0, 0, 0, 0}; // Initial positions
unsigned long lastMoveTime = 0;

void setup() {
  for (int i = 0; i < num_servos; i++) {
    servos[i].attach(servoPins[i]);
    servos[i].write(servoAngles[i]);
  }
}

void loop() {
  unsigned long currentTime = millis();
  
  if (currentTime - lastMoveTime >= 15) {
    lastMoveTime = currentTime;
    for (int i = 0; i < num_servos; i++) {
      if (servoAngles[i] != servoTargets[i]) {
        if (servoAngles[i] < servoTargets[i]) {
          servoAngles[i]++;
          delay(10);
        } else {
          servoAngles[i]--;
        }
        servos[i].write(servoAngles[i]);
      }else{
        int temp = servoTargets[i];
        servoTargets[i] = servoAngles[i];
        servoAngles[i] = temp;
      }
    }
  }

  
}