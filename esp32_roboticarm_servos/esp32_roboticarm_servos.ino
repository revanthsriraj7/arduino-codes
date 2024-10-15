#include<ESP32Servo.h>
#include<BluetoothSerial.h>
Servo servo1, servo2, servo3;
BluetoothSerial bt;
char command;
int pos =0;

void setup() {
  servo1.attach(13);
  servo2.attach(12);
  servo3.attach(14);

  servo1.write(pos);
  servo2.write(pos);
  servo3.write(pos);
  Serial.begin(9600);
  bt.begin();

}

void loop() {
  if(bt.available()){
    char command = bt.read();
    Serial.println(command);
    if(command == 'F'){
      pos+=30;
      servo1.write(pos);
      servo2.write(pos);
      servo3.write(pos);
      
    }
    else if(command == 'B'){
      pos-=30;
      servo1.write(pos);
      servo2.write(pos);
      servo3.write(pos);
    
    }
  }

}
