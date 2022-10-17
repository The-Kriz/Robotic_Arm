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


void loop()
{
  Serial.println("Enter the angle 1 in degree ");
  while (Serial.available() == 0) {}
  angle_1 = Serial.parseFloat();

  Serial.println("Enter the angle 2 in degree ");
  while (Serial.available() == 0) {}
  angle_2 = Serial.parseFloat();

  radAngle_1 = (angle_1 * pi) / 180;
  radAngle_2 = (angle_2 * pi) / 180;

  myservo_1.write(angle_1);
  myservo_2.write(angle_2);

  endEffector_X = linkLength_1 * cos(radAngle_1) + linkLength_2 * cos(radAngle_1 + radAngle_2);
  endEffector_Y = linkLength_1 * sin(radAngle_1) + linkLength_2 * sin(radAngle_1 + radAngle_2);
  delay(1000);
  Serial.print("L1 =  ");
  Serial.println(linkLength_1);
  Serial.print("L2 = ");
  Serial.println(linkLength_2);
  Serial.print("x = ");
  Serial.println(endEffector_X);
  Serial.print("y = ");
  Serial.println(endEffector_Y);
  Serial.print("angle1 is ");
  Serial.println(angle_1);
  Serial.print("angle2 is ");
  Serial.println(angle_2);
  
  delay(500);
}
