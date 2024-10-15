#include "AX12A.h"

int pos1 = 512;
int pos2 = 900;
int pos3 = 960;

void setup()
{
  ax12a.begin(9600, 17, &Serial2);

  ax12a.setEndless(1, OFF);  //base speed 100
  ax12a.setEndless(3, OFF);  //lower speed 40
  ax12a.setEndless(5, OFF);  //upper speed 40

  Serial.begin(9600);

  ax12a.moveSpeed(1, 512, 100);
  ax12a.moveSpeed(3, 900, 40);
  ax12a.moveSpeed(5, 960, 40);

}

void loop()
{
  if(Serial.available() > 0)
  {
    char command = Serial.read();
    if(command == 'a'){
        pos1 = pos1+5;
        ax12a.moveSpeed(1, pos1, 100);
        Serial.println(pos1);
    }
    else if(command == 'd'){
      pos1 = pos1-5;
      ax12a.moveSpeed(1, pos1, 100);
      Serial.println(pos1);
    }

    if(command == 'w'){
      pos2 = pos2+5;
      ax12a.moveSpeed(3, pos2, 40);
      Serial.println(pos2);
    }
    else if(command == 's'){
      pos2 = pos2-5;
      ax12a.moveSpeed(3, pos2, 40);
      Serial.println(pos2);
    }

    if(command == 'q'){
      pos3 = pos3+5;
      ax12a.moveSpeed(5, pos3, 40);
      Serial.println(pos3);
    }
    else if(command == 'e'){
      pos3 = pos3-5;
      ax12a.moveSpeed(5, pos3, 40);
      Serial.println(pos3);
    }
  }
}