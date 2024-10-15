#include<Adafruit_Sensor.h>
#include<Adafruit_ADXL345_U.h>
#include<Wire.h>

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);


void setup(void) {
  Serial.begin(9600);
  if(!accel.begin())
  {
    Serial.println("sensor not detected, check wiring");
    while(1);
  }
  accel.setRange(ADXL345_RANGE_16_G);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  // put your setup code here, to run once:

}

void loop(void) {
  sensors_event_t event;
  accel.getEvent(&event);

  int anglex = event.acceleration.x;
  int angley = event.acceleration.y;
  int anglez = event.acceleration.z;
  Serial.println(anglex);


}
