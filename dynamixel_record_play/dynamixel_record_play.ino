#include "AX12A.h"

int pos1 = 512;
int pos2 = 900;
int pos3 = 960;

const int maxSteps = 100;   // Maximum steps to record
int pos1Record[maxSteps];
int pos2Record[maxSteps];
int pos3Record[maxSteps];
int recordIndex = 0;
bool isRecording = false;
bool isPlaying = false;
int playIndex = 0;

void setup()
{
  ax12a.begin(9600, 17, &Serial2);

  ax12a.setEndless(1, OFF);
  ax12a.setEndless(3, OFF);
  ax12a.setEndless(5, OFF);

  Serial.begin(9600);

  ax12a.moveSpeed(1, pos1, 100);
  ax12a.moveSpeed(3, pos2, 40);
  ax12a.moveSpeed(5, pos3, 40);
}

void loop()
{
  if (Serial.available() > 0)
  {
    char command = Serial.read();
    
    if (command == 'r') {   // Start or stop recording
      isRecording = !isRecording;
      if (isRecording) {
        Serial.println("Recording started...");
        recordIndex = 0;
      } else {
        Serial.println("Recording stopped.");
      }
    }
    else if (command == 'p') {  // Start playing the recorded sequence
      if (!isRecording) {
        isPlaying = true;
        playIndex = 0;
        Serial.println("Playing recorded sequence...");
      }
    }

    if (isRecording && recordIndex < maxSteps) {
      // Record current positions
      pos1Record[recordIndex] = pos1;
      pos2Record[recordIndex] = pos2;
      pos3Record[recordIndex] = pos3;
      recordIndex++;
    }

    if (!isPlaying) {
      // Manual control (position adjustment)
      if (command == 'a') {
        pos1 = pos1 + 5;
        ax12a.moveSpeed(1, pos1, 100);
        Serial.println(pos1);
      }
      else if (command == 'd') {
        pos1 = pos1 - 5;
        ax12a.moveSpeed(1, pos1, 100);
        Serial.println(pos1);
      }

      if (command == 'w') {
        pos2 = pos2 + 5;
        ax12a.moveSpeed(3, pos2, 40);
        Serial.println(pos2);
      }
      else if (command == 's') {
        pos2 = pos2 - 5;
        ax12a.moveSpeed(3, pos2, 40);
        Serial.println(pos2);
      }

      if (command == 'q') {
        pos3 = pos3 + 5;
        ax12a.moveSpeed(5, pos3, 40);
        Serial.println(pos3);
      }
      else if (command == 'e') {
        pos3 = pos3 - 5;
        ax12a.moveSpeed(5, pos3, 40);
        Serial.println(pos3);
      }
    }
  }

  if (isPlaying) {
    if (playIndex < recordIndex) {
      
      pos1 = pos1Record[playIndex];
      pos2 = pos2Record[playIndex];
      pos3 = pos3Record[playIndex];

      ax12a.moveSpeed(1, pos1, 100);
      ax12a.moveSpeed(3, pos2, 40);
      ax12a.moveSpeed(5, pos3, 40);

      Serial.print("Playing step: ");
      Serial.println(playIndex);

      playIndex++;
    } else {
      Serial.println("Playback finished.");
      isPlaying = false;
    }

    delay(500);  // Add some delay between steps to simulate smooth playback
  }
}
