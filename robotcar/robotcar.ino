#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2, 3); 
char command;

int in1 = 8;
int in2 = 9;
int in3 = 10;
int in4 = 11;
int flag = 0;
int trigPin = 12; // trig pin of HC-SR04
int echoPin = 13;
long duration, distance;

void setup()
{
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(in1, OUTPUT); // set Motor pins as output
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(trigPin, OUTPUT); // set trig pin as output
  pinMode(echoPin, INPUT);
}
void loop() 
{

  if(bluetooth.available()>0)
  {
   command = bluetooth.read();
   Serial.println(command);
  }
   if(command=='1'){
    flag =1;
   }
    if(flag==1){ 
    
    if(command=='F'){
    forward();
   }
   if(command=='R'){
    right();
   }
   if(command=='L'){
    left();
   }
   if(command=='B'){
    backward();
   }
   if(command=='S'){
    stop();
   }
   if(command=='2'){
    mode2();
   
   }
   }
  }
void mode2(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // send waves for 10 us
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH); // receive reflected waves
  distance = duration / 58.2; // convert to distance
  //Serial.println(distance);
  delay(10);

  if (distance >5)
    {
      forward();
    }
  else if(distance<5){
      stop();
      delay(500);
      backward();
      delay(500);
      stop();
      delay(500);
      right();
      delay(500);
    }

}
void forward()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void backward()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void left()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void right()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stop()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
  


