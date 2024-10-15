
void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println("m1:run");
  delay(2000);
  Serial.println("m2:stop");
  delay(2000);

}
