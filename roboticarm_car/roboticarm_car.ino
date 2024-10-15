#include <ESP32Servo.h>
#include <BluetoothSerial.h>

Servo bottomarm, upperarm, swivelarm, gripper;
BluetoothSerial SerialBT;
char command;

int bottompos = 0;
int upperpos = 20; 
int swivelpos = 90;

int enA = 27;

int in1 = 14;
int in2 = 12;
int in3 = 33;
int in4 = 25;

int enB = 26;

void setup() {
  Serial.begin(9600);
  SerialBT.begin("ROBOTIC ARM");
  bottomarm.attach(23);
  upperarm.attach(22);
  swivelarm.attach(21);
  gripper.attach(19);

  bottomarm.write(bottompos);
  upperarm.write(upperpos);
  swivelarm.write(swivelpos);
  gripper.write(80);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  digitalWrite(enA, 50);
  digitalWrite(enB, 50);
}

void loop() {
  if (SerialBT.available()) {
    command = SerialBT.read();
    Serial.println(command);

    if(command == 'F'){
      forward();
    }
    else if(command == 'B'){
      backward();
    }
    else if(command == 'L'){
      left();
    }
    else if(command == 'R'){
      right();
    }
    else if(command == 'S'){
      stop();
    }

    if(command == 'l' && bottompos < 150) {
      bottompos += 5;
    } else if(command == 'r' && bottompos > 0) {
      bottompos -= 5; 
    }

    bottomarm.write(bottompos);
    Serial.println(bottompos);
    delay(15); 

    if(command == 'U' && upperpos >= 35) {
      upperpos -= 5; 
    } else if(command == 'D' && upperpos < 180) {
      upperpos += 5; 
    }
    upperarm.write(upperpos);
    Serial.println(upperpos);
    delay(15);

    if(command == 'u' && swivelpos < 180) {
      swivelpos += 5;
    } else if(command == 'd' && swivelpos > 0) {
      swivelpos -= 5; 
    }

    swivelarm.write(swivelpos);
    Serial.println(bottompos);
    delay(15); 

    if(command == 'C'){
      close();
    }

    if(command == 'O'){
      open();
    }
    
  }
}

void close(){
  for(int i =15; i<=80; i++){
    gripper.write(i);
    delay(20);
    Serial.println(i);
  }
}

void open(){
  for(int i =80; i>=15; i--){
    gripper.write(i);
    delay(20);
  }
}

void backward()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void forward()
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
