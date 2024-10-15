// controlling multiple servos 0 to 180 and 180 to 0 in loop

#include <Servo.h>

#define NUM_SERVOS 3

Servo servos[NUM_SERVOS];
int servoPins[NUM_SERVOS] = {8, 9, 10};  // defining servo pins

int servoTargets[NUM_SERVOS] = {180, 180, 180}; // target pos
int servoAngles[NUM_SERVOS] = {0, 0, 0}; //initial pos
unsigned long lastMoveTime = 0;

bool increasing = true; // Flag to track direction

void setup() {
  for (int i = 0; i < NUM_SERVOS; i++) {
    servos[i].attach(servoPins[i]);
    servos[i].write(servoAngles[i]);
  }
}

void loop() {
  unsigned long currentTime = millis();
  
  if (currentTime - lastMoveTime >= 15) {
    lastMoveTime = currentTime;
    for (int i = 0; i < NUM_SERVOS; i++) {
      if (increasing) {
        servoTargets[i] = 180; // Set target to 180 degrees
      } else {
        servoTargets[i] = 0; // Set target to 0 degrees
      }
      
      if (servoAngles[i] != servoTargets[i]) {
        if (servoAngles[i] < servoTargets[i]) {
          servoAngles[i]++;
        } else {
          servoAngles[i]--;
        }
        servos[i].write(servoAngles[i]);
      }
    }
    
    if (servoAngles[0] == 0 && servoAngles[1] == 0 && servoAngles[2] == 0) {
      increasing = true; // Change direction to increasing when all servos reach 0 degrees
    } else if (servoAngles[0] == 180 && servoAngles[1] == 180 && servoAngles[2] == 180) {
      increasing = false; // Change direction to decreasing when all servos reach 180 degrees
    }
  }
}
