void setup() {
    Serial.begin(9600); // Set baud rate
}

void loop() {
    // Simulate stable weight
    float weight = 123.45; // Replace with any dummy value
    Serial.print("S S    "); // Start stable weight response
    Serial.print(weight, 2); // Print weight with two decimal places
    Serial.println(" g"); // Print unit (grams)

    delay(1000); // Wait for 1 second before sending the next data
}
