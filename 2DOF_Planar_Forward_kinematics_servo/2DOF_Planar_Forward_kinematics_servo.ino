#include <Servo.h>

//Servo
#define Servo1 3
#define Servo2 5

Servo myservo_1, myservo_2;

float linkLength_1;
float linkLength_2;

float pi = 3.14159265359;

float angle_1;
float angle_2;
float radAngle_1;
float radAngle_2;

float endEffector_X;
float endEffector_Y;

void setup()
{
  Serial.begin(9600);
  myservo_1.attach(Servo1);
  myservo_2.attach(Servo2);

  Serial.println("Enter the length of first arm ");
  while (Serial.available() == 0) {}
  linkLength_1 = Serial.parseFloat();

  Serial.println("Enter the length of second arm ");
  while (Serial.available() == 0) {}
  linkLength_2 = Serial.parseFloat();

}
