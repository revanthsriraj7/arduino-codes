#include <Arduino.h>
#include <Servo.h>
#include <Ramp.h>

#define SERVO_PIN 8
#define SERVO_PIN2 10 
#define SERVO_PIN3 13                // Servo motor PWM control pin
#define SPEED 30                      // degrees per second

Servo servo1, servo2, servo3;                 // Create servo objects to control the servos
rampInt Angle1(0);
rampInt Angle2(0);                    // Initialize ramp with a starting angle of 0
rampInt Angle3(0);

void updateServos() {
  int val1 = Angle1.update();         // Update ramp value for servo1
  int val2 = Angle2.update(); 
  int val3 = Angle3.update();
          // Update ramp value for servo2

  servo1.write(val1);                 // Transmit the value to servo1
  servo2.write(val2);  
  servo3.write(val3);               // Transmit the value to servo2
}

void moveServos(int startAngle1, int targetAngle1, int startAngle2, int targetAngle2, int startAngle3, int targetAngle3) {
  Angle1 = startAngle1;               // Set the starting angle for servo1
  Angle2 = startAngle2;    
  Angle3 = startAngle3;           // Set the starting angle for servo2

  uint32_t duration1 = 1000L * abs(startAngle1 - targetAngle1) / SPEED; // Calculate ramp duration for servo1
  uint32_t duration2 = 1000L * abs(startAngle2 - targetAngle2) / SPEED;
  uint32_t duration3 = 1000L * abs(startAngle3 - targetAngle3) / SPEED; // Calculate ramp duration for servo2

  Angle1.go(targetAngle1, duration1); // Set the target angle and duration for servo1
  Angle2.go(targetAngle2, duration2);
  Angle3.go(targetAngle3, duration3); // Set the target angle and duration for servo2

  while (!Angle1.isFinished() || !Angle2.isFinished() || !Angle3.isFinished()) {  // Loop until both ramps complete
    updateServos();
    delay(10);                      // Limit update to ~100 Hz
  }
}

void setup() {
  Serial.begin(115200);
  servo1.attach(SERVO_PIN); 
  servo2.attach(SERVO_PIN2);
  servo3.attach(SERVO_PIN3);        // Attach the servos on the specified pins
        // Move both servos from 0 to 180 degrees simultaneously
}

void loop() {
  moveServos(0, 180, 0, 180, 0, 180); 
}
