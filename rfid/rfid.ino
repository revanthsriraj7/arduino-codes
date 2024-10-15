#include <SPI.h>
#include <MFRC522.h>

// RFID setup
#define SS_PIN 15
#define RST_PIN 16
MFRC522 mfrc522(SS_PIN, RST_PIN);

bool cardProcessed = false;

void setup() {
  // Setup serial communication
  Serial.begin(9600);
  // Setup RFID
  SPI.begin();
  mfrc522.PCD_Init();

}

void loop() {
  // Check if a card has been processed recently and reset the flag after some time
  if (cardProcessed) 
  {
    delay(10);  // Delay after processing to avoid multiple detections
    cardProcessed = false;  // Reset the flag
    return;
  }

  // Check for new RFID card
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Get the card UID
  String content = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    content += String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
    content += String(mfrc522.uid.uidByte[i], HEX);
  }
  content.toUpperCase();
  Serial.println("Card UID: " + content.substring(1));

  
}
