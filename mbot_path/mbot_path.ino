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
    delay(1500);
    motor1.stop();
    led.setColor(0,0,0);
    led.show();
}
void turnRight() {
    delay(1000);
    led.setColor(255,0,0);
    led.show();
    motor2.run(100);
    delay(1500);
    motor2.stop();
    led.setColor(0,0,0);
    led.show();
}
void spinLeft() {
    delay(1000);
    led.setColor(255,0,0);
    led.show();
    motor1.run(100);
    motor2.run(100);
    delay(3000);
    motor1.stop();
    motor2.stop();
    led.setColor(0,0,0);
    led.show();
}
void spinRight() {
    delay(1000);
    led.setColor(255,0,0);
    led.show();
    motor1.run(-100);
    motor2.run(-100);
    delay(3000);
    motor1.stop();
    motor2.stop();
    led.setColor(0,0,0);
    led.show();
}
/*****************************/
void setup(){
    led.setpin(13);
    pinMode(A7,INPUT);
    while(analogRead(A7) !=0);
}
/*****************************/
void loop() {
   move();
   turnRight();
   turnLeft();
   spinRight();
   spinLeft();
}