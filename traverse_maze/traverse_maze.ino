#include <Arduino.h>
#include <MeMCore.h>

MeUltrasonicSensor ultraSonic(PORT_3);

void setup() {
  Serial.begin(9600);

}

void loop() {
  Serial.print("Distance: ");
  Serial.print(ultraSonic.distanceCm());
  Serial.println(" cm");
  delay(100);
}