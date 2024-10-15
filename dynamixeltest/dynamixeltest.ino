#include "AX12A.h"

void setup()
{
  ax12a.begin(9600, 17, &Serial2);

  ax12a.setEndless(2, OFF); 

}

void loop() {
  
  ax12a.moveSpeed(2, 1023, 40);
  //int pos = ax12a.readPosition(2);
 // Serial.println(pos);

  delay(2000);

  ax12a.moveSpeed(2, 0, 40);
  //Serial.println(pos);
  delay(2000);

}
