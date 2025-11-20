#include <Arduino.h>
#include <MeMCore.h>

MeDCMotor motor1(M1);
MeDCMotor motor2(M2);
MeRGBLed led(0,30);
/*****************************/
void moveFar() {
    led.setColor(0,255,0);
    led.show();
    motor1.run(100);
    motor2.run(-107);
    delay(4750);
    motor1.stop();
    motor2.stop();
    led.setColor(0,0,0);
    led.show();
}
void moveClose() {
    led.setColor(0,255,0);
    led.show();
    motor1.run(100);
    motor2.run(-107);
    delay(3200);
    motor1.stop();
    motor2.stop();
    led.setColor(0,0,0);
    led.show();
}
void moveMed() {
    led.setColor(0,255,0);
    led.show();
    motor1.run(100);
    motor2.run(-110);
    delay(4000);
    motor1.stop();
    motor2.stop();
    led.setColor(0,0,0);
    led.show();
}
void turnLeft() {
    led.setColor(255,0,0);
    led.show();
    motor1.run(100);
    delay(1075);
    motor1.stop();
    led.setColor(0,0,0);
    led.show();
}
void turnRight() {
    led.setColor(255,0,0);
    led.show();
    motor2.run(-100);
    delay(1100);
    motor2.stop();
    led.setColor(0,0,0);
    led.show();
}
void spin180() {
    led.setColor(255,0,0);
    led.show();
    motor1.run(-100);
    motor2.run(-107);
    delay(1100);
    motor1.stop();
    motor2.stop();
    led.setColor(0,0,0);
    led.show();
}
void backward() {
    led.setColor(0,255,0);
    led.show();
    motor1.run(-100);
    motor2.run(100);
    delay(1000);
    motor1.stop();
    motor2.stop();
    led.setColor(0,0,0);
    led.show();
}
void forward() {
    led.setColor(0,255,0);
    led.show();
    motor1.run(100);
    motor2.run(-100);
    delay(1000);
    motor1.stop();
    motor2.stop();
    led.setColor(0,0,0);
    led.show();
}
void pause() {
    led.setColor(255,0,0);
    led.show();
    delay(1000);
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
   delay(3000);
   moveFar();
   pause();
   turnRight();
   pause();
   moveClose();
   pause();
   turnLeft();
   pause();
   moveMed();
   pause();
   spin180();
   forward();
   backward();
}