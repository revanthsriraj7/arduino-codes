#include <Arduino.h>                        // needed for PlatformIO
#include <Ramp.h> 
#include <Servo.h>                           // include library
ramp myRamp;                                // new ramp object (ramp<unsigned char> by def
Servo servo1;
ramp myRamp2;                                // new ramp object (ramp<unsigned char> by def
Servo servo2;

void setup() 
{
  Serial.begin(9600);  
  servo1.attach(10);
  servo2.attach(9);                     // begin Serial communication            
}

void loop() 
{
  myRamp.setValue(90);                      // set the initial value to 90
  myRamp.go(180, 30000);
  Serial.println(myRamp.update());    
  servo1.write(myRamp.update()); 

  myRamp2.setValue(0);                      // set the initial value to 90
  myRamp2.go(180, 30000);
  Serial.println(myRamp2.update());    
  servo2.write(myRamp2.update());                   
}