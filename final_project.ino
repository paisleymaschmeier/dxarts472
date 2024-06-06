// Resources:
  // https://forum.arduino.cc/t/28byj-48-4-phase-stepper-motor/1162926
  // https://www.youtube.com/watch?v=LHvXPeT2gws
  // https://www.youtube.com/watch?v=STCctT6JyPg
  // https://www.youtube.com/watch?v=-JYi08WKe6c&t=108s
  

//Includes the Arduino Stepper Library
#include <Stepper.h>

// Defines the number of steps per rotation
const int stepsPerRevolution = 2038;

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

#include <Servo.h>
Servo myservo;
const int threshValue = 400;

int sensorValue=0;
int value_average = 0;

unsigned long previousStepperTime = millis();
long stepperInterval = 0;

void setup()
{
  Serial.begin (9600);
  myservo.attach(3);
  myStepper.setSpeed(3);
}

void loop() {
  int value = analogRead(A3);

  Serial.println(value);

  if (value < threshValue)
  {
    int positionLower = map(value, 200, threshValue, 1200, 1599);
    myservo.writeMicroseconds(positionLower);
    //myStepper.setSpeed(1);
	  //myStepper.step(stepsPerRevolution);
  }
  else
  {
    int positionHigher = map(value, threshValue+1, 1000, 1600, 1700);
    myservo.writeMicroseconds(positionHigher);
    //myStepper.setSpeed(1);
	  //myStepper.step(stepsPerRevolution);
  }

	myStepper.step(-6);
}


