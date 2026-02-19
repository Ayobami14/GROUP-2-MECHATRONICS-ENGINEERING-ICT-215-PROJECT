#include <Servo.h> // to iclude the servo library
Servo myservo; // to create the servo motor object
int servopos=0; // to put the servo motor at the origin
// declaration of pins used
int servopin=8;
int trigpin=2; // for ultrasonic sensor
int echopin=4; // for ultrasonic sensor
int redledpin=6;
int greenledpin=7;
int trigpin2=3;
int echopin2=4;
int buzzpin=9;

// declaration of variables
int ptt;
int ptt2;
int dt=250;
float distance;
float distance2;
void setup() {
  // put your setup code here, to run once:
// setting up of pins
pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);
pinMode(trigpin2, OUTPUT);
pinMode(echopin2, INPUT);
myservo.attach(servopin);
pinMode(redledpin, OUTPUT);
pinMode(greenledpin, OUTPUT);
pinMode(buzzpin, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
// to get distance from the ultrasonic sensor
digitalWrite(trigpin, LOW);
delayMicroseconds(10);
digitalWrite(trigpin, HIGH);
delayMicroseconds(10);
digitalWrite(trigpin, LOW);
delayMicroseconds(10);
ptt=pulseIn(echopin, HIGH);
distance=(0.03*ptt)/2;
Serial.println(distance);
delay(dt);
// to open bin if distance is less than 10cm
if(distance<=10){
  servopos=90;
  myservo.write(servopos);
  digitalWrite(redledpin, HIGH);
  digitalWrite(greenledpin, LOW);
  Serial.print(distance);
  Serial.print();
  Serial.println(distance2);
  delay(dt);
}
// to close bin if distance is greater than 10cm
if(distance>=10){
  servopos=0;
  myservo.write(servopos);
  digitalWrite(redledpin, LOW);
  digitalWrite(greenledpin, HIGH);
  Serial.print(distance);
  Serial.print( );
  Serial.println(distance)
  delay(dt);
}
digitalWrite(trigpin2, LOW);
delayMicroseconds(10);
digitalWrite(trigpin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigpin2, LOW);
delayMicroseconds(10);
ptt2=pulseIn(echopin2, HIGH);
distance2=(0.03*ptt)/2;
if(distance2>=5){
  digitalWrite(buzzpin, HIGH);
  delay(500);
  digitalWrite(buzzpin, LOW);
}
}