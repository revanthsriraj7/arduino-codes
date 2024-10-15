#include <DHT.h>
//wifi headers
#include <ESP8266WiFi.h>
#include <ESP_Mail_Client.h>
#include <Wire.h>

//wifi creds
#define WIFI_SSID "Revanth"
#define WIFI_PASSWORD "revanthsriraj"
#define SMTP_HOST "smtp.gmail.com"
#define SMTP_PORT 465
#define AUTHOR_EMAIL "akshaybhawarkiti@gmail.com"
#define AUTHOR_PASSWORD "uabulpopoejyiyxk"
#define RECIPIENT_EMAIL "joshuamatthewjohn2004@gmail.com"
#define CC_RECIPIENT_EMAIL "raikupaiku@gmail.com"


#define DHTPIN D1  
#define DHTTYPE DHT11 
#define flame D3

DHT dht(DHTPIN, DHTTYPE);

float temp; // Stores temperature value
int flame_sense;

//smtp server define
SMTPSession smtp;
Session_Config config;
SMTP_Message message;

void setup() {
  Serial.begin(9600); // Initialize serial communication
  dht.begin();
  pinMode(flame, INPUT);
  pinMode(D5, OUTPUT);

  pinMode(10, OUTPUT);

  //wifi creds

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) 
  {
    Serial.println(" :-( ");
    delay(300);
  }


  // Initialize ESP Mail Client
  MailClient.networkReconnect(true);
  smtp.debug(0); // Disable SMTP debug output


  config.server.host_name = SMTP_HOST;
  config.server.port = SMTP_PORT;
  config.login.email = AUTHOR_EMAIL;
  config.login.password = AUTHOR_PASSWORD;

  config.time.ntp_server = F("pool.ntp.org,time.nist.gov");
  config.time.gmt_offset = 3;
  config.time.day_light_offset = 0;

  message.sender.name = F("HARMFUL ENVIRONMENT ALERT");
  message.sender.email = AUTHOR_EMAIL;
  message.subject = F("'SOS' EVACUVATE");
  message.addRecipient(F("Recipient"), RECIPIENT_EMAIL);
  message.addRecipient(F("CC Recipient"), CC_RECIPIENT_EMAIL);


  String textMsg = "Flames detected, harmful environment! EVACUVATE!";
  textMsg += "Please confirm to the owner.\n\n";
  textMsg += "Name: Revanth Sriraj\n";
  textMsg += "Location: Srishti 2024, Atria Institute\n";
  textMsg += "Contact No: 6361380037\n";
  textMsg += "Email: akshaybhawarkiti@gmail.com\n";
  textMsg += "Please contact the Fire Department\n";
  textMsg += "Name: Joshua John\n";
  textMsg += "Location: REVA University\n";
  textMsg += "Contact No: 88893459734\n";
  textMsg += "Email: bhavikap18@gmail.com\n";

  message.text.content = textMsg.c_str();
  message.text.charSet = "us-ascii";
  message.text.transfer_encoding = Content_Transfer_Encoding::enc_7bit;  
}

void loop() {

  if (Serial.available() > 0) {
    char command = Serial.read();
    Serial.println(command);
  }

  temp = dht.readTemperature();
  flame_sense = digitalRead(flame);

  Serial.print((int)temp);
  Serial.print("|");
  Serial.print(flame_sense);
  Serial.println("|");
  delay(500); 

  if(flame_sense == 0)
  {
    
    buzzer_alert();
    delay(3000);
    sendEmail();
    digitalWrite(10, HIGH);
  }
  else{
    digitalWrite(10,LOW);
  }

}

void sendEmail() {
  if (!smtp.connect(&config)) 
  {
    return;
  }

  if (!MailClient.sendMail(&smtp, &message)) 
  {
  
   return;
  }

}

void buzzer_alert()
{
  for(int i =0; i<50; i++)
  {  
  digitalWrite(D5,HIGH);
  delay(50);
  digitalWrite(D5, LOW);
  delay(50);
  }
}