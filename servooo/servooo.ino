#include "AX12A.h"

void setup()
{
  // Start communication with AX-12A at 9600 baud rate
  ax12a.begin(9600, 17, &Serial2);

  // Disable endless mode (wheel mode) to enable joint mode
  ax12a.setEndless(1, OFF);  // Set ID 1 to joint mode
  ax12a.setEndless(2, OFF);  // Set ID 1 to joint mode
  ax12a.setEndless(5, OFF); 
}

void loop()
{
  // Move the servo to specific positions
  ax12a.moveSpeed(1, 512, 50);
  ax12a.moveSpeed(2, 900, 100);
  ax12a.moveSpeed(5, 960, 50);
  delay(2000);         // Wait 1 second
  ax12a.moveSpeed(1, 0, 50);
  ax12a.moveSpeed(2, 500, 100);
  ax12a.moveSpeed(5, 400, 50);
  delay(2000);         // Wait 1 second
  
}
