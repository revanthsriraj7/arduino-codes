#include <SPI.h>
#include <ESP8266WiFi.h>
#include <ESP_Mail_Client.h>
#include <MFRC522.h>

// WiFi and Email credentials
#define WIFI_SSID "akshay"
#define WIFI_PASSWORD "aks142004"
#define SMTP_HOST "smtp.gmail.com"
#define SMTP_PORT 465
#define AUTHOR_EMAIL "akshaybhawarkiti@gmail.com"
#define AUTHOR_PASSWORD "negxnogspplkhhqw"

// RFID setup
#define SS_PIN D4
#define RST_PIN D3
MFRC522 mfrc522(SS_PIN, RST_PIN);

// SMTP session
SMTPSession smtp;
Session_Config config;
SMTP_Message message;

String recipientEmail;
String name;
String srn;
bool cardProcessed = false;

void setup() {
  // Setup serial communication
  Serial.begin(9600);
  pinMode(D2, OUTPUT);
  // Setup RFID
  SPI.begin();
  mfrc522.PCD_Init();

  // Setup LED indicator
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  // Connect to WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Connecting to WiFi...");
    delay(1);
  }
  Serial.print("Connected to WiFi! IP: ");
  Serial.println(WiFi.localIP());
  digitalWrite(LED_BUILTIN, HIGH);
  for (int i = 0; i < 5; i++) 
  {
    digitalWrite(D2, HIGH);
    delay(200);
    digitalWrite(D2, LOW);
    delay(200);
  }
  // SMTP configuration
  MailClient.networkReconnect(true);
  smtp.debug(1);

  config.server.host_name = SMTP_HOST;
  config.server.port = SMTP_PORT;
  config.login.email = AUTHOR_EMAIL;
  config.login.password = AUTHOR_PASSWORD;
  config.time.ntp_server = F("pool.ntp.org,time.nist.gov");
  config.time.gmt_offset = 3;
  config.time.day_light_offset = 0;

  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D8, OUTPUT);
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

  if (!cardProcessed) {
    
    if (content.substring(1) == "0D B1 B8 71") 
    {
      name = "Revanth Sriraj";
      srn = "R22EO013";
      recipientEmail = "raikupaiku@gmail.com";
      grant();
      digitalWrite(D2, HIGH);
      sendEmail();
      digitalWrite(D2, LOW);
      check();
      cardProcessed = true;  
    } 
    
    else if (content.substring(1) == "9D 83 A3 72") 
    { 
      name = "Joshua John";
      srn = "R22EO012";
      recipientEmail = "joshuamatthewjohn2004@gmail.com";
      grant();
      digitalWrite(D2, HIGH);
      sendEmail(); // Call sendEmail without parameters
      digitalWrite(D2, LOW);
      check();
      cardProcessed = true;  // Mark this card as processed
    } 

    else if (content.substring(1) == "BD CB 42 72") 
    {
      name = "Srinidhi M";
      srn = "R22EN217";
      recipientEmail = "srinidhim384@gmail.com";
      grant();
      digitalWrite(D2, HIGH);
      sendEmail(); // Call sendEmail without parameters
      digitalWrite(D2, LOW);
      check();
      cardProcessed = true;  // Mark this card as processed
    } 
    
    else 
    {
      Serial.println("Access Denied!");
      denyAccess();
      cardProcessed = true;  // Mark this card as processed
    }
  }
}

void sendEmail() {
  // Compose email body
  String textMsg = "Alert! Mentee Arrived Late To the University.\n";
  textMsg += "{Name: " + name + "}\n";
  textMsg += "{Srn: " + srn + "}\n";
  textMsg += "{Course: ECE R&A 5th Sem }\n";
  textMsg += "{No: 6361380037}";

  // Setup email details
  message.sender.name = "ALERT! Late Comer " + name + "!";
  message.sender.email = AUTHOR_EMAIL;
  message.subject = "ALERT! Late Comer " + name + "!";

  // Clear previous recipients
  message.clearRecipients(); 
  message.addRecipient("Recipient", recipientEmail); // Send to specific recipient

  message.text.content = textMsg.c_str();
  message.text.charSet = "us-ascii";
  message.text.transfer_encoding = Content_Transfer_Encoding::enc_7bit;

  // Send email
  if (!smtp.connect(&config)) {
    Serial.println("Failed to connect to the mail server");
    return;
  }

  if (!MailClient.sendMail(&smtp, &message)) {
    Serial.println("Error sending Email: " + String(smtp.errorReason().c_str()));
    return;
  }

  Serial.println("Email sent successfully!");
}

void smtpCallback(SMTP_Status status) {
  if (status.success()) {
    Serial.println("Callback: Email sent successfully!");
  } else {
    Serial.println("Callback: Email sending failed: " + String(smtp.errorReason().c_str()));
  }
}

void check() {
  Serial.println("OK");
  digitalWrite(D2, HIGH);
  delay(400);
  digitalWrite(D2, LOW);
}

void grant() {
  Serial.print("Access Granted! ,");
  digitalWrite(D0, HIGH);     
  digitalWrite(D8, HIGH);
  delay(300);
  digitalWrite(D8, LOW);
  delay(300); 
  digitalWrite(D0, LOW); 
}

void denyAccess() {
  digitalWrite(D1, HIGH);
  digitalWrite(D8, LOW);
  for (int i = 0; i < 5; i++) {
    digitalWrite(D8, HIGH);
    delay(500);
    digitalWrite(D8, LOW);
    delay(500);
  }
  digitalWrite(D1, LOW);
}
