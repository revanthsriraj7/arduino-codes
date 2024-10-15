#include <Adafruit_BMP085.h>

Adafruit_BMP085 bmp, bmp2, bmp3, bmp4;
void setup()
{
  Serial.begin(115200);
  if (!bmp.begin())
  {
    Serial.println("BMP180 Sensor not found ! ! !");
    while (1)
    {
    
    }
  }

  if (!bmp2.begin())
  {
    Serial.println("BMP180 Sensor not found ! ! !");
    while (1)
    {
    
    }
  }

  if (!bmp3.begin())
  {
    Serial.println("BMP180 Sensor not found ! ! !");
    while (1)
    {
    
    }
  }

  if (!bmp4.begin())
  {
    Serial.println("BMP180 Sensor not found ! ! !");
    while (1)
    {
    
    }
  }
}

void loop()
{
  Serial.print("Pressure1 = ");
  Serial.print(bmp.readPressure()/6894.76);
  Serial.print(" PSI");
  Serial.print("  Temp1 = ");
  Serial.print(bmp.readTemperature());
  Serial.println("ºC");

  Serial.print("Pressure2 = ");
  Serial.print(bmp2.readPressure()/6894.76);
  Serial.print(" PSI");
  Serial.print("  Temp2 = ");
  Serial.print(bmp2.readTemperature());
  Serial.println("ºC");

  Serial.print("Pressure3 = ");
  Serial.print(bmp3.readPressure()/6894.76);
  Serial.print(" PSI");
  Serial.print("  Temp3 = ");
  Serial.print(bmp3.readTemperature());
  Serial.println("ºC");

  Serial.print("Pressure4 = ");
  Serial.print(bmp4.readPressure()/6894.76);
  Serial.print(" PSI");
  Serial.print("  Temp4 = ");
  Serial.print(bmp4.readTemperature());
  Serial.println("ºC");

  delay(3000);
}