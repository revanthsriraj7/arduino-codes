#include <Wire.h>           
#include <LiquidCrystal_I2C.h>      
#include <Servo.h>
Servo myservo; 
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() 
{
  myservo.attach(9);
  lcd.begin();    
  lcd.backlight();  
  pinMode(7,INPUT);
  pinMode(6,INPUT);
  Serial.begin(9600);

   lcd.setCursor(0,0);  
   lcd.print("PARKING SYSTEM");  
   lcd.setCursor(0,1);  
   lcd.print("ARJUN"); 
   delay(2000);
   lcd.clear();
}

void loop() 
{
   int value = digitalRead(7);
   int value1 = digitalRead(6);
   
   Serial.println(value1);
   Serial.println(value);
   

 if(value == 0)
 {
   lcd.setCursor(0,0);  
   lcd.print("PARKING FULL");  
   lcd.setCursor(0,1);  
   lcd.print("GATE CLOSED"); 
   delay(800);
   lcd.clear();
    for (int pos = 0; pos <= 0; pos += 1) 
  { 
    myservo.write(pos);              
    delay(15);                       
  }
 }

 
 else if(value == 1)
 {
   lcd.setCursor(0,0);  
   lcd.print("Slot Empty");  
   lcd.setCursor(0,1);  
   lcd.print("Welcome"); 
   
   if(value1 == 0)
   {
     for (int pos = 0; pos <= 90; pos += 1) 
     { 
     myservo.write(pos);              
     delay(15);                       
     }
     delay(2500);
     
     for (int pos = 90; pos >= 0; pos -= 1) 
     { 
     myservo.write(pos);              
     delay(15);                       
     }  
   }
   else
   {
    for (int pos = 0; pos <= 0; pos += 1) 
     { 
     myservo.write(pos);              
     delay(15);                       
     }
   }
  }
}