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


void setup() 
{
  
  Serial.begin(9600);
  myservo_1.attach(Servo1);
  myservo_2.attach(Servo2);
  myservo_3.attach(Servo3);
  myservo_4.attach(Servo4);

}


void loop() 
{
  
  Servo_val = map(analogRead(poten1),0, 1023, 0, 179);
  myservo_1.write(Servo_val);
  Servo_va2 = map(analogRead(poten2),0, 1023, 0, 179);
  myservo_2.write(Servo_va2);
  Servo_va3 = map(analogRead(poten3),0, 1023, 0, 179);
  myservo_3.write(Servo_va3);
  Servo_va4 = map(analogRead(poten4),0, 1023, 0, 179);
  myservo_4.write(Servo_va4);
  
  Serial.println("SERVO 1 Location :"+String(Servo_val));
  Serial.println("SERVO 2 Location :"+String(Servo_va2));
  Serial.println("SERVO 3 Location :"+String(Servo_va3));
  Serial.println("SERVO 4 Location :"+String(Servo_va4));
  
  delay(500);
  
}
