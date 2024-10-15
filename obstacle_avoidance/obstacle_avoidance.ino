int trigPin = 12; // trig pin of HC-SR04
int echoPin = 13; // Echo pin of HC-SR04
int in1 = 8;
int in2 = 9;
int in3 = 10;
int in4 = 11;
long duration, distance;

void setup() {
  delay(random(500,2000)); // delay for random time
  Serial.begin(9600);
  pinMode(in1, OUTPUT); // set Motor pins as output
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(trigPin, OUTPUT); // set trig pin as output
  pinMode(echoPin, INPUT); //set echo pin as input to capture
//reflected waves
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // send waves for 10 us
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH); // receive reflected waves
  distance = duration / 58.2; // convert to distance
  delay(10);
// If you dont get proper movements of your robot then alter the pin
//numbers
if (distance >5)
{
  digitalWrite(in1, HIGH); // move forward
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
if (distance < 4)
{
digitalWrite(in1, LOW); //Stop
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
delay(500);
digitalWrite(in1, LOW); //movebackword
digitalWrite(in2, HIGH);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
delay(500);
digitalWrite(in1, LOW); //Stop
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
delay(200);
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
delay(500);
}
}

