String command;

void setup() {
  Serial.begin(9600);  // For communication with ESP32
}

void loop() {
  if (Serial.available()) {
    command = Serial.readStringUntil('\n');
    command.trim();  // Remove any trailing/leading whitespace

    //Serial.println(command);  // Echo the command for debugging

    if (command == "WS 1") {
      Serial.println("WS A");  // Open door
    } 
    else if (command == "WS 0") {
      Serial.println("WS A");  // Close door
    } 
    else if (command == "T") {
      Serial.println("T S       005.00 g");  // Tare response
    } 
    else if (command == "S") {
      Serial.println("s s       002.00 g");  // Weight response
    }
  }
}
