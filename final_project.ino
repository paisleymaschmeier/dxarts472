//Includes the Arduino Stepper Library
#include <Stepper.h>

// Defines the number of steps per rotation
const int stepsPerRevolution = 2038;

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

#include <Servo.h>
Servo myservo;
const int threshValue = 300;

void setup()
{
  Serial.begin (9600);
  myservo.attach(3);
}

void loop()
{
  int value = analogRead(A3);
  Serial.println(value);

  if (value < threshValue)
  {
    myservo.writeMicroseconds(800);
  }
  else
  {
    myservo.writeMicroseconds(2250);
  }

	// Rotate CW slowly at 5 RPM
	myStepper.setSpeed(5);
	myStepper.step(stepsPerRevolution);
}


