#include <Arduino.h>
#include <MeMCore.h>

MeUltrasonicSensor ultraSonic(PORT_3);
MeLineFollower lineFinder(PORT_2);
MeDCMotor motor1(M1);
MeDCMotor motor2(M2);
MeRGBLed led(0,30);
/*****************************/
void right() {
  motor1.run(100);
  motor2.run(100);
  delay(550);
  motor1.stop();
  motor2.stop();
}
void fullTurn() {
  motor1.run(100);
  motor2.run(100);
  delay(1000);
  motor1.stop();
  motor2.stop();
}
void move() {
  if (ultraSonic.distanceCm() > 10) {
    motor1.run(100);
    motor2.run(-100);
  }
}
/*****************************/
void turn() {
  if (ultraSonic.distanceCm() < 10) {
    right();
    if (ultraSonic.distanceCm() < 10) {
      fullTurn();
    }
  }
}
void check() {
  delay(1000);
  right();
  if (ultraSonic.distanceCm() < 10) {
    fullTurn();
    if (ultraSonic.distanceCm() < 10) {
    right();
    }
  } else {
    move();
  }
}
/*****************************/
void setup() {
  led.setpin(13);
  pinMode(A7,INPUT);
  while(analogRead(A7) !=0);
  Serial.begin(9600);
}
/*****************************/
void loop() {
  Serial.print("Distance: ");
  Serial.print(ultraSonic.distanceCm());
  Serial.println(" cm");
  delay(300);
  move();
  turn();
  check();
  }
}