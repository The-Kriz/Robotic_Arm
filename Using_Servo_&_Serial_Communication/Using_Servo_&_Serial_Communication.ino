//Contrlling Robotic Arm using Potentiometer

//Importing library
#include <Servo.h>

//Servo
#define Servo1 3
#define Servo2 5
#define Servo3 6
#define Servo4 9
Servo myservo_1,myservo_2,myservo_3,myservo_4;

//Potentiometer pins
#define poten1 A1
#define poten2 A2
#define poten3 A3
#define poten4 A4

// Potentiometer values
int Servo_val; 
int Servo_va2;
int Servo_va3;
int Servo_va4;

int val = 0;
int count = 0;
int data =0;
int unit =0;

void setup() 
{
  
  Serial.begin(9600);
  myservo_1.attach(Servo1);
  myservo_2.attach(Servo2);
  myservo_3.attach(Servo3);
  myservo_4.attach(Servo4);

}
