#include <Arduino.h>
#include <MeMCore.h>

MeDCMotor motor1(M1);
MeDCMotor motor2(M2);
MeRGBLed led(0,30);
/*****************************/
void move() {
    delay(1000);
    led.setColor(0,255,0);
    led.show();
    motor1.run(100);
    motor2.run(-100);
    delay(5000);
    motor1.stop();
    motor2.stop();
    led.setColor(0,0,0);
    led.show();
}
void turnLeft() {
    delay(1000);
    led.setColor(255,0,0);
    led.show();
    motor1.run(100);
    delay(1100);
    motor1.stop();
    led.setColor(0,0,0);
    led.show();
}
void turnRight() {
    delay(1000);
    led.setColor(255,0,0);
    led.show();
    motor2.run(-100);
    delay(1100);
    motor2.stop();
    led.setColor(0,0,0);
    led.show();
}
void spinLeft() {
    delay(1000);
    led.setColor(255,0,0);
    led.show();
    motor1.run(100);
    delay(4000);
    motor1.stop();
    led.setColor(0,0,0);
    led.show();
}
void spinRight() {
    delay(1000);
    led.setColor(255,0,0);
    led.show();
    motor2.run(-100);
    delay(4000);
    motor2.stop();
    led.setColor(0,0,0);
    led.show();
}
void pause() {
    delay(5000);
}
/*****************************/
void setup(){
    led.setpin(13);
    pinMode(A7,INPUT);
    while(analogRead(A7) !=0);
}
/*****************************/
void loop() {
   delay(2000);
   move();
   turnRight();
   move();
   turnLeft();
   move();
}