#include <NewPing.h>

// Pin Definitions
#define ULTRASONIC_SENSOR_TRIG 11
#define ULTRASONIC_SENSOR_ECHO 12
#define MAX_FORWARD_MOTOR_SPEED 75
#define MAX_MOTOR_TURN_SPEED_ADJUSTMENT 50
#define MIN_DISTANCE 10
#define MAX_DISTANCE 30
#define IR_SENSOR_RIGHT 2
#define IR_SENSOR_LEFT 3

// Right Motor
int enableRightMotor = 5;
int rightMotorPin1 = 7;
int rightMotorPin2 = 8;

// Left Motor
int enableLeftMotor = 6;
int leftMotorPin1 = 9;
int leftMotorPin2 = 10;

NewPing mySensor(ULTRASONIC_SENSOR_TRIG, ULTRASONIC_SENSOR_ECHO, 400);

// Function Declarations
void rotateMotor(int rightMotorSpeed, int leftMotorSpeed);

void setup() {
  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);
  pinMode(IR_SENSOR_RIGHT, INPUT);
  pinMode(IR_SENSOR_LEFT, INPUT);
  rotateMotor(0, 0);
}

void loop() {
  int distance = mySensor.ping_cm();
  int rightIRSensorValue = digitalRead(IR_SENSOR_RIGHT);
  int leftIRSensorValue = digitalRead(IR_SENSOR_LEFT);

  // If right sensor detects hand, turn right
  if (rightIRSensorValue == LOW && leftIRSensorValue == HIGH) {
    rotateMotor(MAX_FORWARD_MOTOR_SPEED - MAX_MOTOR_TURN_SPEED_ADJUSTMENT, MAX_FORWARD_MOTOR_SPEED + MAX_MOTOR_TURN_SPEED_ADJUSTMENT);
  } 
  // If left sensor detects hand, turn left
  else if (rightIRSensorValue == HIGH && leftIRSensorValue == LOW) {
    rotateMotor(MAX_FORWARD_MOTOR_SPEED + MAX_MOTOR_TURN_SPEED_ADJUSTMENT, MAX_FORWARD_MOTOR_SPEED - MAX_MOTOR_TURN_SPEED_ADJUSTMENT);
  } 
  // If distance is within range, go straight
  else if (distance >= MIN_DISTANCE && distance <= MAX_DISTANCE) {
    rotateMotor(MAX_FORWARD_MOTOR_SPEED, MAX_FORWARD_MOTOR_SPEED);
  } 
  // Stop the motors
  else {
    rotateMotor(0, 0);
  }
}

void rotateMotor(int rightMotorSpeed, int leftMotorSpeed) {
  // Right Motor
  if (rightMotorSpeed < 0) {
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, HIGH);
  } else if (rightMotorSpeed > 0) {
    digitalWrite(rightMotorPin1, HIGH);
    digitalWrite(rightMotorPin2, LOW);
  } else {
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
  }
  // Left Motor
  if (leftMotorSpeed < 0) {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, HIGH);
  } else if (leftMotorSpeed > 0) {
    digitalWrite(leftMotorPin1, HIGH);
    digitalWrite(leftMotorPin2, LOW);
  } else {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
  }
  analogWrite(enableRightMotor, abs(rightMotorSpeed));
  analogWrite(enableLeftMotor, abs(leftMotorSpeed));
}