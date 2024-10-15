void setup() {
  Serial.begin(9600);  // Set the baud rate to 9600
}

void loop() {
  Serial.println("m1:run");  // Send data at 9600 baud
  delay(2000);
  Serial.println("m2:stop");
  delay(2000);

  String command = Serial.readStringUntil('\n');
  if(command == 'stop'){
    
  }
}
