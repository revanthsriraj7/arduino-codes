#include <HardwareSerial.h>

HardwareSerial SerialPort(2); // use UART2


void setup()
{
  SerialPort.begin(15200, SERIAL_8N1, 16, 17);
  Serial.begin(9600);
}
void loop()
{
  if (SerialPort.available())
  {
    String command = SerialPort.readString();
    Serial.println(command);
  }
}