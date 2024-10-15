#include <VarSpeedServo.h> 
 
VarSpeedServo myservo1;  // create servo object to control a servo 
                         // a maximum of eight servo objects can be created 
VarSpeedServo myservo2, myservo3;
 
const int servoPin1 = 8; // the digital pin used for the first servo
const int servoPin2 = 10; // the digital pin used for the second servo

const int servoPin3 = 12;
 
void setup() { 
  myservo1.attach(servoPin1);  // attaches the servo on pin 9 to the servo object
  myservo1.write(0,255,false); // set the intial position of the servo, as fast as possible, run in background
  myservo2.attach(servoPin2);  // attaches the servo on pin 9 to the servo object
  myservo2.write(0,255,false);  // set the intial position of the servo, as fast as possible, wait until done
  myservo3.attach(servoPin3);  // attaches the servo on pin 9 to the servo object
  myservo3.write(0,255,true);

  pinMode(6, INPUT);
  Serial.begin(9600);
} 

void loop() {

  int val = digitalRead(6);
  Serial.println(val);

  if(val == 0){

  myservo1.write(180,30,false);        // move the servo to 180, fast speed, run background
                                        // write(degrees 0-180, speed 1-255, wait to complete true-false)
  myservo2.write(180,30,false);         // move the servo to 180, fast speed, wait until done

  myservo3.write(180,30,true);
  
  myservo1.write(0,30,false);           // move the servo to 180, slow speed, run in background
  myservo2.write(0,30,false);            // move the servo to 180, slow speed, wait until done

  myservo3.write(0,30,true);

  myservo1.write(90,30,false);           // move the servo to 180, slow speed, run in background
  myservo2.write(90,30,false);            // move the servo to 180, slow speed, wait until done

  myservo3.write(90,30,true);

  }

  else if(val == 1){
    myservo1.stop();
    myservo2.stop();
    myservo3.stop();
  }

} 
