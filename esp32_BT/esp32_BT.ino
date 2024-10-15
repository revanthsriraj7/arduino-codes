#include <BluetoothSerial.h>

BluetoothSerial SerialBT;
 char incomingChar;

void setup() {
  Serial.begin(9600);
  SerialBT.begin("MASS ROBOTIC ARM"); // Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  if (SerialBT.available()) {
    // Read data from Bluetooth
    char incomingChar = SerialBT.read();
    
    // Print the received data to the Serial Monitor
    Serial.println(incomingChar);
      if (incomingChar=='a'){
  delay(1000); 
  }
             
  }
  
  // You can add your other code or functionality here
}