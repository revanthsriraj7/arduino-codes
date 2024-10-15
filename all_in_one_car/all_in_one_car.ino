#include<Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2, 3);

Servo servo;

#define trig 12
#define echo 13


int in1 = 8;
int in2 = 9;
int in3 = 10;
int in4 = 11;

int flag = 3;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(trig, OUTPUT); // set trig pin as output
  pinMode(echo, INPUT); //set echo pin as input to capture
  servo.attach(7);
  servo.write(90);
  Serial.begin(9600);
  bluetooth.begin(9600);


}

void loop() {
  
  if(bluetooth.available()>0){
    char command = bluetooth.read();
    Serial.println(command);
    if(command == 1){
      if(command == 'F')
      {
        forward();
      }
      if(command == 'B')
      {
        backward();
      }
      if(command == 'R')
      {
        right();
      }
      if(command == 'L')
      {
        left();
      }
      if(command == 'S')
      {
        stop();
      }
    }
    else if(command==2){
      //ultrasonic loop
      int distanceR = 0;
      int distanceL = 0;
      int distanceF = distance();
      Serial.println(distanceF);
      if(distanceF<15){
        stop();
        delay(100);
        backward();
        delay(300);
        stop();
        delay(200);
        distanceR = lookRight();
        delay(200);
        Serial.println("Rdistance= ");
        Serial.print(distanceR);
        distanceL = lookLeft();
        delay(200);

        if(distanceR>=distanceL)
        {
          right();
          delay(2000);
          stop();
        }else
       {
          left();
          delay(2000);
          stop();
       }
      }else
      {
       forward();
       }

      }
    }
  }
  



void forward(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void backward(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void left(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void right(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

int distance(){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH); // send waves for 10 us
  delayMicroseconds(10);
  int duration = pulseIn(echo, HIGH); // receive reflected waves
  int distance = duration / 58.2; // convert to distance
  delay(10);
  return distance;
}

int lookRight()
{
    servo.write(50); 
    delay(500);
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH); // send waves for 10 us
    delayMicroseconds(10);
    int duration = pulseIn(echo, HIGH); // receive reflected waves
    int distance = duration / 58.2; // convert to distance
    delay(10);
    delay(100);
    servo.write(115); 
    return distance;
}

int lookLeft()
{
    servo.write(170); 
    delay(500);
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH); // send waves for 10 us
    delayMicroseconds(10);
    int duration = pulseIn(echo, HIGH); // receive reflected waves
    int distance = duration / 58.2; // convert to distance
    delay(10);
    delay(100);
    servo.write(115); 
    return distance;
    delay(100);
}
