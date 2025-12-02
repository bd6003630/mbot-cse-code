#include <Arduino.h>
#include <MeMCore.h>

MeLineFollower lineFinder(PORT_2);
MeDCMotor motor1(M1);
MeDCMotor motor2(M2);
MeRGBLed led(0,30);
/*****************************/
void setup() {
    led.setpin(13);
    pinMode(A7,INPUT);
    while(analogRead(A7) !=0);
    Serial.begin(9600);
}
/*****************************/

void loop()
{
  int sensorState = lineFinder.readSensors();
  switch(sensorState)
  {
    case S1_IN_S2_IN: Serial.println("Sensor 1 and 2 are inside of black line");
    motor1.run(70);
    motor2.run(-70);
    delay(200);
    motor1.stop();
    motor2.stop();
    break;
    case S1_IN_S2_OUT: Serial.println("Sensor 2 is outside of black line");
    motor1.run(100);
    delay(200);
    motor1.stop();
    break;
    case S1_OUT_S2_IN: Serial.println("Sensor 1 is outside of black line");
    motor2.run(-100);
    delay(200);
    motor2.stop();
    break;
    case S1_OUT_S2_OUT: Serial.println("Sensor 1 and 2 are outside of black line");
    motor1.run(-50);
    motor2.run(55);
    delay(200);
    motor1.stop();
    motor2.stop();
    break;
    default: motor1.stop(); break; 
  }
  delay(200);
}

