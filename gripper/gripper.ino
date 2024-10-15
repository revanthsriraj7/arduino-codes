#include<ESP32Servo.h>
Servo servo;
void setup() {
  servo.attach(13);
  servo.write(15);
  Serial.begin(9600);
}

void loop() {
  for(int i =15; i<=80; i++){
    servo.write(i);
    delay(20);
    Serial.println(i);
  }
  for(int i =80; i>=15; i--){
    servo.write(i);
    delay(20);
  }
}
