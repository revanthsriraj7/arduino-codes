#include <BluetoothSerial.h>
#include<ESP32Servo.h>

Servo servo;

BluetoothSerial SerialBT;
char command;

int in1 = 27;
int in2 = 26;
int in3 = 25;
int in4 = 33;

bool seedsowing = false;

void setup() {
  Serial.begin(9600);
  SerialBT.begin("SEED SOWING ROBOT");
  servo.attach(12);
  servo.write(90);
  pinMode(15, OUTPUT);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  if (SerialBT.available()) {

    char command = SerialBT.read();
    Serial.println(command);
    
    switch (command) {
      case 'F':
        forward();
        break;
      case 'B':
        backward();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
      case 'S':
        stop();
        break;
      case 'O':
        seedsowing = true;
        break;
      case 'C':
        servo.write(90);
        seedsowing = false;
        break;
    }
  }

  digitalWrite(15, HIGH);
  if(seedsowing){
    seedsow();
  }
}

void seedsow() {
  for (int i = 45; i <= 135; i++) {
    servo.write(i);
    delay(7);
  }
  for (int i = 135; i >= 45; i--) {
    servo.write(i);
    delay(7);
  }
}

void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void backward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void left() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void right() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
