#include <VarSpeedServo.h> 
 
VarSpeedServo myservo1;  // create servo object to control a servo 
                         // a maximum of eight servo objects can be created 
VarSpeedServo myservo2;
 
const int servoPin1 = 8; // the digital pin used for the first servo
const int servoPin2 = 10; // the digital pin used for the second servo
 
void setup() { 
  myservo1.attach(servoPin1);  // attaches the servo on pin 9 to the servo object
  myservo1.write(0,255,false); // set the intial position of the servo, as fast as possible, run in background
  myservo2.attach(servoPin2);  // attaches the servo on pin 9 to the servo object
  myservo2.write(0,255,true);  // set the intial position of the servo, as fast as possible, wait until done
} 

void loop() {
  myservo1.write(180,15,false);        // move the servo to 180, fast speed, run background
                                        // write(degrees 0-180, speed 1-255, wait to complete true-false)
  myservo2.write(90,15,true);
  myservo1.wait();         // move the servo to 180, fast speed, wait until done
  
  myservo1.write(90,15,false);           // move the servo to 180, slow speed, run in background
  myservo2.write(180,15,true); 
  
  myservo1.wait();           // move the servo to 180, slow speed, wait until done
} 
