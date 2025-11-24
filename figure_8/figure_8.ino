#include <MeMCore.h>
MeLineFollower lineFinder(PORT_2);

void setup() {
  // put your setup code here, to run once:

}
void loop() {
  if (lineFinder.readSensor1()==0 && lineFinder.readSensor2()==0)
    {
      Serial.println("Sensor 1 on black and Sensor2 on black");
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
