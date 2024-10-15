#include <Arduino.h>                    // needed for PlatformIO

#define SERVO_PIN      9                // Servo motor PWM control pin
#define TARGET_ANGLE   90               // Target angle for the servo
#define SPEED          10               // degree/s, slower speed

#include <Servo.h>
Servo myservo;                          // create servo object to control a servo

#include <Ramp.h>
rampInt myAngle;                        // create a ramp object to interpolate servo position

byte previousAngle = 0;

void updateServo() {
  int val = myAngle.update();           // update ramp value
  Serial.println(val);                  // print angle value
  myservo.write(val);                   // transmit it to the servo
}

void updateServoPosition(int targetAngle) {
  // Calculate ramp duration in ms according to the speed
  uint32_t duration = 1000 * abs(myAngle.getValue() - targetAngle) / SPEED;  

  if (abs(targetAngle - previousAngle) >= 2) {
    myAngle.go(targetAngle, duration);  // set next ramp interpolation in ms
    previousAngle = targetAngle;        // save previous angle
  }
}

void setup() {
  Serial.begin(115200);
  myservo.attach(SERVO_PIN);            // attaches the servo on pin 9 to the servo object
  myAngle.go(previousAngle);            // Initialize ramp with the starting position
  updateServoPosition(TARGET_ANGLE);    // Set the initial target position
}

void loop() {
  updateServo();                        // update servo according to the new target position
  delay(20);                            // delay for smooth ramping updates
}
