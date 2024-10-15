// a maximum of eight servo objects can be created
// write(degrees 0-180, speed 1-255, wait to complete true-false)

#include <VarSpeedServo.h> 
 
VarSpeedServo myservo1;                            
VarSpeedServo myservo2;
 
void setup() 
{ 
  myservo1.attach(8);
  myservo2.attach(10);  
} 

void loop() 
{
  myservo1.write(90,225,false);                                              
  myservo2.write(0,225,true);         
  
  myservo1.write(180,30,false);           
  myservo2.write(40,30,true); 

  myservo1.write(90,30,false);           
  myservo2.write(0,30,true);            
}