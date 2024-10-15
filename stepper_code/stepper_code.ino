
const int step1 = 13;
const int dir1 = 12;

int count = 0;

void setup() 
{
pinMode(step1,OUTPUT);
pinMode(dir1,OUTPUT);

Serial.begin(9600);

}

void loop() 
{
  digitalWrite(dir1, HIGH);          //Base
  digitalWrite(step1, HIGH);
  delay(3);  
  digitalWrite(step1, LOW);
  delay(3);   
  count = count + 1;
  Serial.println(count);
  count = 0;
}