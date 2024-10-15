int in1 = 8;
int in2 = 9;
int in3 = 10;
int in4 = 11;
int duration, distance;
int echopin = 2;
int trigpin = 3;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);

  Serial.begin(9600);

}

void loop() {

  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigpin, LOW);

  duration = pulseIn(echopin, HIGH);
  distance = duration*0.034/2;
  Serial.println(distance);

  if(distance<10){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);

    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  else{
    
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);

    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }


}
