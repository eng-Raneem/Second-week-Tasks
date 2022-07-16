//servo motor with potentiometer simulation code
#include <Servo.h>

int angle = 0;

int i = 0;

int output = 0;

Servo servo_9;

void setup()
{
  pinMode(A0, INPUT);
  servo_9.attach(9, 500, 2500);
}

void loop()
{
  angle = analogRead(A0);
  output = map(angle, 0, 1023, 0, 180);
  servo_9.write(output);

  analogRead(A0);
  delay(10); // Delay a little bit to improve simulation performance
}