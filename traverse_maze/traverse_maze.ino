#include <Arduino.h>
#include <MeMCore.h>

MeUltrasonicSensor ultraSonic(PORT_3);
MeLineFollower lineFinder(PORT_2);
MeDCMotor motor1(M1);
MeDCMotor motor2(M2);
MeRGBLed led(0,30);

void setup() {
  led.setpin(13);
  pinMode(A7,INPUT);
  while(analogRead(A7) !=0);
  Serial.begin(9600);
}

void loop() {
  Serial.print("Distance: ");
  Serial.print(ultraSonic.distanceCm());
  Serial.println(" cm");
  delay(300);
}