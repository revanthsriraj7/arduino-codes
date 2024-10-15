#define RX2 16
#define TX2 17

void setup() {
  Serial.begin(15200);
  Serial.println("STARTED");
  Serial2.begin(9600, SERIAL_8N1, RX2, TX2);

}

void loop() {
  Serial2.write("yessss\n");
  delay(200);

}
