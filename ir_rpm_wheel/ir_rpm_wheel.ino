#define IR_sensor 23

unsigned long startTime, elapsedTime;
int count = 0;
int lastState = HIGH; 

void setup() {
  pinMode(IR_sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  startTime = millis();
  count = 0; 

  while (millis() - startTime <= 1000) { // Measure for 1 second
    int currentState = digitalRead(IR_sensor);

    // Detect transition from HIGH to LOW (wheel slot passes the sensor)
    if (lastState == HIGH && currentState == LOW) {
      count++;
    }

    lastState = currentState; // Update the last state
  }

  // Calculate RPM (number of slots detected per minute)
  float rpm = (count * 60.0);

  // Output the RPM
  Serial.print("RPM: ");
  Serial.println(rpm);
  delay(500); // Small delay to avoid overwhelming the serial monitor
}
