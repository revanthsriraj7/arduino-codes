#include <SPI.h>
#include <MFRC522.h>
#include <SD.h>

#define SS_PIN D4
#define RST_PIN D3


MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

File myFile, newFile;
String line;

void setup() {
  Serial.begin(9600);  // Initialize serial communications
  SPI.begin();           // Init SPI bus
  mfrc522.PCD_Init();    // Init MFRC522

  Serial.println("Scan RFID card...");

  if (!SD.begin(11)) {
    Serial.println("Initialization failed!");
    return;
  }
  Serial.println("Initialization done.");
  myFile = SD.open("data.csv");

}

void loop() {
  // Look for new cards
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Print card UID
  String content = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    content += String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : "");
    content += String(mfrc522.uid.uidByte[i], HEX);
  }
  content.toUpperCase();
  String uidno = content.substring(1)
  Serial.println(uidno);
  
  // Halt PICC
 // mfrc522.PICC_HaltA();

  if (myFile) {
    newFile = SD.open("latecomer.csv", FILE_WRITE);
     if (!newFile) {
      Serial.println("Error opening latecomer.csv");
      return;
    }
    Serial.println("data.csv:");
    
    while (myFile.available()) {
      line = myFile.readStringUntil('\n');  // Read a full line until newline
      //Serial.println(line);
      if (line.startsWith(uidno)) {  // Check if the line starts with "REVANTH"
        Serial.println("Match found:");
        Serial.println(line);  // Print the entire matching line

        Serial.println("Writing to latecomer.csv");
        newFile.print(line);
        Serial.println("done.");
      }
      
    }
    
    // Close the file
    myFile.close();
    newFile.close();

  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening data.csv");
  }

}