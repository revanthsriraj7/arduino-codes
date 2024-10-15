#include<ESP32Servo.h>

Servo servo;

const int step1 = 13;
const int dir1 = 12;

int count = 0;

void setup() 
{
  pinMode(step1,OUTPUT);
  pinMode(dir1,OUTPUT);

  Serial.begin(9600);
  Serial2.begin(115200, SERIAL_8N1, 16, 17);
  servo.attach(23);
  servo.write(60);

}

void loop() 
{
  while (Serial2.available() >= 1) {
    //Serial.print(char(Serial2.read()));
    String incoming = Serial2.readStringUntil('\n');
    Serial.println(incoming);

  String machine = incoming.substring(0, 2);
  Serial.println(machine);
  String command = incoming.substring(2);
  Serial.println(command);

  if(machine == "m1")
  {
    if(command == "run")
  {
    servo.write(3);
    delay(500);
    for(int i =0; i<=20000; i++){
      digitalWrite(dir1, HIGH);          
      digitalWrite(step1, HIGH);
      delay(3);  
      digitalWrite(step1, LOW);
      delay(3);   
      count = count + 1;
      //Serial.println(count);
      count = 0;
    }

    for(int i = 0; i<20000; i++){
      digitalWrite(dir1, LOW);          //Base
      digitalWrite(step1, HIGH);
      delay(3);  
      digitalWrite(step1, LOW);
      delay(3);   
      count = count + 1;
      //Serial.println(count);
      count = 0;
    }

    Serial2.println("done");
  }
  }
  
}
}
