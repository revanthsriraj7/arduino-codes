#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN D4
#define RST_PIN D3

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

void setup() {
  Serial.begin(9600);  // Initialize serial communications
  SPI.begin();           // Init SPI bus
  mfrc522.PCD_Init();    // Init MFRC522

  Serial.println("Scan RFID card...");
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
  //Serial.print("UID tag: ");
  String content = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    content += String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : "");
    content += String(mfrc522.uid.uidByte[i], HEX);
  }
  content.toUpperCase();
  String uidno = content.substring(1);
  Serial.println(uidno);
  
  // Halt PICC
  mfrc522.PICC_HaltA();
}
