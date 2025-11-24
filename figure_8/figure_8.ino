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
}
/*****************************/
void loop() {
  if (lineFinder.readSensor1()==0 && lineFinder.readSensor2()==0)
    {
      Serial.println("Sensor 1 on black and Sensor2 on black");
      motor1.run
    }
  else if (lineFinder.readSensor1()==1 && lineFinder.readSensor2()==0)
    {
     Serial.println("Sensor 1 on white and Sensor 2 on black");
    }
  else if (lineFinder.readSensor1()==0 && lineFinder.readSensor2()==1)
    {
    Serial.println("Sensor 1 on Black and Sensor 2 on White");
    }
  else //(lineFinder.readSensor1()==1 && lineFinder.readSensor2()==1)
    {
    Serial.println("Sensor 1 on White and Sensor 2 on White");
    }
delay(1000);
}
