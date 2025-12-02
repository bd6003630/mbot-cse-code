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
/* void loop() {
  delay(3000);
  if (lineFinder.readSensor1()==0 && lineFinder.readSensor2()==0)
    {
      Serial.println("Sensor 1 on black and Sensor2 on black");
      motor1.run(50);
      motor2.run(-54);
      delay(1000);
    }
  else if (lineFinder.readSensor1()==1 && lineFinder.readSensor2()==0)
    {
     Serial.println("Sensor 1 on white and Sensor 2 on black");
     motor2.run(-54);
     delay(1000);
    }
  else if (lineFinder.readSensor1()==0 && lineFinder.readSensor2()==1)
    {
    Serial.println("Sensor 1 on Black and Sensor 2 on White");
    motor1.run(50);
    delay(1000);
    }
  else //(lineFinder.readSensor1()==1 && lineFinder.readSensor2()==1)
    {
    Serial.println("Sensor 1 on White and Sensor 2 on White");
    motor1.stop();
    motor2.stop();
    delay(1000);
    }
delay(1000);
}
*/

void loop()

{

  int sensorState = lineFinder.readSensors();

  switch(sensorState)

  {

    case S1_IN_S2_IN: Serial.println("Sensor 1 and 2 are inside of black line"); break;

    case S1_IN_S2_OUT: Serial.println("Sensor 2 is outside of black line"); break;

    case S1_OUT_S2_IN: Serial.println("Sensor 1 is outside of black line"); break;

    case S1_OUT_S2_OUT: Serial.println("Sensor 1 and 2 are outside of black line"); break;

    default: break;

  }

  delay(200);

}