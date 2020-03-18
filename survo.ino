/*
  Ultrasonic Sensor HC-SR04 and Arduino Tutorial

  by Dejan Nedelkovski,
  www.HowToMechatronics.com

*/

#include <Servo.h>
Servo myservo; //ประกาศตัวแปรแทน Servo
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;

// defines variables
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  myservo.attach(11); // กำหนดขา 9 ควบคุม Servo
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = duration * 0.034 / 2;

  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  if (distance < 10) {
    rotate();
  }
  else {
    stopServo();
  }
}

void rotate() {
  myservo.write(0); // หมุน
  delay(100); // หน่วงเวลา 100ms
  myservo.write(90); // หยุดหมุน
  delay(1000); // หน่วงเวลา 1000ms
  myservo.write(180); // หมุนหลับทิศจากเดิม
  delay(100);
}

void stopServo() {
  myservo.write(90); // หยุดหมุน
}
