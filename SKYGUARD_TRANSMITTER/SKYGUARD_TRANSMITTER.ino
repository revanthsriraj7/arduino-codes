#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>
#include <ESP32Servo.h>
#include <FastLED.h>

#define DATA_PIN 35
#define NUM_LEDS 8
CRGB leds[NUM_LEDS];

Servo servo;
Servo servor;
Servo servol;

#define ss 5
#define rst 14
#define dio0 2

int pos = 45;


void setup()
{
  Serial.begin(9600);
  Serial.println("Attachment");
  pinMode(25, INPUT);
  pinMode(26, INPUT);
  LoRa.setPins(ss, rst, dio0);
  LoRa.begin(433E6);
  
  servo.attach(33); 
  servol.attach(32);
  servor.attach(13); 
  
  servo.write(pos);
  servor.write(180);
  servol.write(0);

  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(50);

}

void loop()
{
  int value = digitalRead(25);
  int value1 = digitalRead(26);
  int packetSize = LoRa.parsePacket();
  
  if (packetSize)
  {
    String received = LoRa.readString();
    Serial.println(received);
    alert();
    delay(3000);
    
   if (received == "up") 
  {
    Serial.println("Servo Up");
    pos = pos + 5;
    servo.write(pos);
    if(pos >= 90)
     {
      pos = 90;
     }
  }
  else if (received == "down") 
  {
    Serial.println("Servo Down");
    pos = pos - 5;
    servo.write(pos);
     
     if(pos <= 0)
     {
      pos = 0;
     }
  }
   
   
   else if (received == "hold") 
  {
   servor.write(70); 
   servol.write(110); 
  }

   else if (received == "leave") 
  {
   servor.write(180);
   servol.write(0); 
  }
  else{
    stable();
  }
  
  }
   if (value == HIGH) 
  {
    LoRa.beginPacket();
    LoRa.print("12.894794,");
    LoRa.print("77.675774");
    Serial.println("cordinates sent!");
    LoRa.endPacket();
    sent();
    delay(2000);
  }

    else if (value1 == HIGH) 
  {
    LoRa.beginPacket();
    LoRa.print("13.116727,");
    LoRa.print("77.634764");
    Serial.println("cordinates sent!");
    LoRa.endPacket();
    sent();
    delay(2000);
  }
  else{
    stable();
  }
  
}

void sent()
{
  for(int i = 0 ; i <= 16; ++i)
   {
    leds[i] = CRGB(0, 200, 0);
    FastLED.show();
   }
}

void alert()
{
  for(int i = 0 ; i <= 16; ++i)
   {
    leds[i] = CRGB(200, 0, 0);
    FastLED.show();
   }
}

void stable()
{
  for(int i = 0 ; i <= 16; ++i)
   {
    leds[i] = CRGB(200, 200, 200);
    FastLED.show();
   }
}