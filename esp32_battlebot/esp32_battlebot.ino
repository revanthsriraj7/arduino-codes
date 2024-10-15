#include <BluetoothSerial.h> //including bluetooth library for esp32
#include <Servo.h>  //including Servo library to run the servos

Servo servo1;
Servo servo2; //declaring servo variables
int flag = 3;

BluetoothSerial SerialBT;  //declaring bluetooth variable
 char incomingChar;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_BT"); // Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  servo1.attach(12);
  servo2.attach(14);
}

void loop() {
  if (SerialBT.available()) {
    // Read data from Bluetooth
    char incomingChar = SerialBT.read();
    Serial.println(incomingChar); // Print the received data to the Serial Monitor
    if (flag == 3) // Third gear
    {
      if (command == 'F') {
        servo1.write(180);
        servo2.write(68);
      } else if (command == 'B') {
        servo1.write(0);
        servo2.write(112);
      } else if (command == 'L') {
        servo1.write(0);
        servo2.write(0);
      } else if (command == 'R') {
        servo1.write(180);
        servo2.write(180);
      } else if (command == 'S') {
        servo1.write(90);
        servo2.write(90);
      } else if (command == '2') {
        flag = 2;
      } else if (command == '1') {
        flag = 1;
      }
    }

    if (flag == 2) // Second gear
    {
      if (command == 'F') {
        servo1.write(120);
        servo2.write(60);
      } else if (command == 'B') {
        servo1.write(60);
        servo2.write(120);
      } else if (command == 'L') {
        servo1.write(180);
        servo2.write(180);
      } else if (command == 'R') {
        servo1.write(0);
        servo2.write(0);
      } else if (command == 'S') {
        servo1.write(90);
        servo2.write(90);
      } else if (command == '3') {
        flag = 3;
      } else if (command == '1') {
        flag = 1;
      }
    }

    if (flag == 1) // First gear
    {
      if (command == 'F') {
        servo1.write(100);
        servo2.write(80);
      } else if (command == 'B') {
        servo1.write(80);
        servo2.write(100);
      } else if (command == 'L') {
        servo1.write(180);
        servo2.write(180);
      } else if (command == 'R') {
        servo1.write(0);
        servo2.write(0);
      } else if (command == 'S') {
        servo1.write(90);
        servo2.write(90);
      } else if (command == '2') {
        flag = 2;
      } else if (command == '3') {
        flag = 3;
      }
    }
  }
             
  }
}