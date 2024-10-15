String incoming;

void setup() {
  Serial.begin(9600);
}

void loop() { 
  while (Serial.available() >= 1) {
    incoming = Serial.readStringUntil('\n');
    Serial.println(incoming);
  }
}