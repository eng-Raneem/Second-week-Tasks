//servo motor simulation code 

#include <Servo.h>

int angle = 0;

int i = 0;

Servo servo_10;

void setup()
{
  servo_10.attach(10, 500, 2500);
}

void loop()
{
  angle = 0;
  for (angle = 0; angle <= 180; angle += 1) {
    servo_10.write(angle);
    delay(20); // Wait for 20 millisecond(s)
  }
  for (angle = 180; angle >= 0; angle -= 1) {
    servo_10.write(angle);
  }
}