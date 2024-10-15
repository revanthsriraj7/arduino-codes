#include <SPI.h>
#include <SD.h>

File myFile;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);

  if (!SD.begin(15)) {
    Serial.println("Initialization failed!");
    return;
  }
  Serial.println("Initialization done.");
  
  // Open the CSV file for reading:
  myFile = SD.open("data.csv");
  if (myFile) {
    Serial.println("data.csv:");
    
    // Read each line from the file
    while (myFile.available()) {
      String line = myFile.readStringUntil('/');  // Read a full line until newline
      Serial.println(line);
      if (line.startsWith("0D B1 B8 71")) {  // Check if the line starts with "REVANTH"
        Serial.println("Match found:");
        Serial.println(line);  // Print the entire matching line
      }
      else{
        Serial.println("match not found");
      }
    }
    
    // Close the file
    myFile.close();
  } else {
    // If the file didn't open, print an error
    Serial.println("Error opening data.csv");
  }
}

void loop() {
  // Nothing happens after setup
}
