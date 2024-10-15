#include <Servo.h>
Servo servolower;
Servo servoupper;
Servo servobase;
Servo servobent;
Servo servoswel;
int pos;


void setup() 
{
Serial.begin(9600);
servolower.attach(D2);
servoupper.attach(D3);  
servobase.attach(D4);
servobent.attach(D6, 500, 2400);  
servoswel.attach(D5, 500, 2400);

pinMode(D7 ,OUTPUT);

servolower.write(0); 
servoupper.write(15);
servobase.write(90);
servobent.write(0);
servoswel.write(90);
digitalWrite(D7,HIGH);
delay(3000);

}





void loop() 
{
 part1();
 delay(4000); 

 part2();
 delay(4000); 
}








void part1()
{
 
for(int b = 90 ; b >= 35 ; b--)// the base will face the part 1
{
 servobase.write(b);
 delay(20);  
}

for(int n = 0 ; n <= 50 ; n++) //extend the end effectors
{
  servobent.write(n);
  delay(20);
}

for(int u = 15 ; u <= 106 ; u++) //lower and the upper will move together to get the thing
{
  servolower.write(u);
  servoupper.write(u);
  delay(20);
}

delay(1000);
digitalWrite(D7 , LOW);
Serial.println("The OPERATION IS DONE of pickup");
delay(1000);

for(int g = 106 ; g >= 50 ; g--)// lower back
{
  servolower.write(g);
  delay(20);
}

for(int u = 106 ; u <= 120 ; u++) //upper front
{
  servoupper.write(u);
  delay(20);
}

for(int h = 50 ; h >= 22 ; h--)// bent back
{
  servobent.write(h);
  delay(20);
}

for(int j = 90 ; j >= 75 ; j--)// swel back
{
  servoswel.write(j);
  delay(20);
}

for(int v = 35 ; v <= 78 ; v++) //base front
{
  servobase.write(v);
  delay(20);
}

for(int v = 50 ; v <= 80 ; v++) //lower front
{
  servolower.write(v);
  delay(20);
}

delay(1000);
digitalWrite(D7 , HIGH);
Serial.println("The OPERATION IS DONE!! to attach");
delay(1000); 

for(int j = 80 ; j >= 0 ; j--)// lower back
{
  servolower.write(j);
  delay(20);
}

for(int j = 78 ; j <= 90 ; j++)// base back
{
  servobase.write(j);
  delay(20);
}

for(int h = 22 ; h >= 0 ; h--)// bent back
{
  servobent.write(h);
  delay(20);
}

for(int j = 120 ; j >= 15 ; j--)// upper back
{
  servoupper.write(j);
  delay(20);
}

for(int v = 75 ; v <= 90 ; v++) //swel center
{
  servoswel.write(v);
  delay(20);
}

delay(1000);
}

//********************************************************//

void part2()
{
for(int n = 90 ; n <= 145 ; n++) //base move
{
  servobase.write(n);
  delay(20);
}  

for(int n = 0 ; n <= 52 ; n++) //bent move
{
  servobent.write(n);
  delay(20);
}  

for(int n = 15 ; n <= 100 ; n++) //upper move
{
  servoupper.write(n);
  delay(20);
}  

for(int n = 0 ; n <= 101 ; n++) //lower move
{
  servolower.write(n);
  delay(20);
}  

delay(1500);
digitalWrite(D7, LOW);
delay(1500);

for(int b = 101 ; b >= 50 ; b--)//lower will go up
{
 servolower.write(b);
 delay(20);  
}


for(int b = 145 ; b >= 75 ; b--)//base will go up
{
 servobase.write(b);
 delay(20);  
}


for(int b = 100 ; b <= 116 ; b++)//upper will go up
{
 servoupper.write(b);
 delay(20);  
}

for(int b = 52 ; b >= 24 ; b--)//bent will go down
{
 servobent.write(b);
 delay(20);  
}

for(int b = 90 ; b >= 78 ; b--)//swel will go up
{
 servoswel.write(b);
 delay(20);  
}

for(int b = 50 ; b <= 77 ; b++)//lower will go down
{
 servolower.write(b);
 delay(20);  
}

delay(1500);
digitalWrite(D7, HIGH);
delay(1500);

for(int j = 77 ; j >= 0 ; j--)// lower back
{
  servolower.write(j);
  delay(20);
}

for(int b = 78 ; b <= 90 ; b++)//swel
{
 servoswel.write(b);
 delay(20);  
}

for(int b = 24 ; b >= 0 ; b--)//bent will go down
{
 servobent.write(b);
 delay(20);  
}

for(int b = 116 ; b >= 15 ; b--)//upper will go down
{
 servoupper.write(b);
 delay(20);  
}

for(int b = 75 ; b <= 90 ; b++)//base will go up
{
 servobase.write(b);
 delay(20);  
}

delay(1000);
}