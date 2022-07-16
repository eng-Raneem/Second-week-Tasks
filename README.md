# second-week-tasks
This repository include the second week tasks
_I used tinkercad to build and simulate the required circuits._

For **the servo motor**, it was quite easy to connect it directly to the Arduino, I made it twice, for the first time the motor was receiving the signal from the Arduino directly the I useed the following code to run the circuit.

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


Unlike that, in the second time the motor was controlled by the potentiometer, and to avoid unused values I mapped the potentiometer values with the motor degrees(0-180), and the following code was used for the simulation.

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


For **the stepper motor**, I used a DC motor with an Encoder as stepper motor then I connected the motor to the Arduino through the H-bridge motor driver(L293D) to run the motor with the following code.
#include <Stepper.h>:

const int stepsPerRevolution = 200;

Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
  
int stepCount = 0;
void setup() {}

void loop() {
  int sensorReading = analogRead(A0);
  int motorSpeed = map(sensorReading, 0, 1023, 0, 250);
  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed);
    myStepper.step(stepsPerRevolution / 100);
  }
}
