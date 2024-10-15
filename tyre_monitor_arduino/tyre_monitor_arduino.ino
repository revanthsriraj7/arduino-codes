#include<Servo.h>
#include <Adafruit_BMP085.h>

Adafruit_BMP085 bmp;

Servo servo;
void setup() {
  servo.attach(13);
  pinMode(A0, INPUT);

  Serial.begin(9600);
  if (!bmp.begin())
  {
    while (1)
    {
    
    }
  }

}

void loop() {
  int val = analogRead(A0);
  int angle = map(0, 1023, 0, 180);

  servo.write(angle);
  delay(15);

  Serial.print(bmp.readPressure()/6894.76);
  Serial.print(bmp.readTemperature());

}
