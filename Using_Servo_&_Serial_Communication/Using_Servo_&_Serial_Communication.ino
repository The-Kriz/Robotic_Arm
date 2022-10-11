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
int unit =0;

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
if (Serial.available() > 0) {
    // read the incoming data:
    int  val = Serial.parseInt();

    // Print and process the data for next step:
    Serial.print("received input: ");
    Serial.println(val);
    unit = val%10;
    val = val/10;
    Serial.println(unit);
    Serial.println(val);
    
if (unit != 0 && val != 0) //Enter only if any data received
{
  if( unit == 1) //Enter if data received is for Servo 1
  {
      Serial.println("unit 1 if");
      if(val >= 1 && val <= 179)
      { 
      myservo_1.write(val);
      Serial.println("SERVO 1 Location :"+String(val));
      }
      else
      {
      Serial.println("Enter a position value between 0 and 180");
      }
  }
  else if( unit == 2) //Enter if data received is for Servo 2
  {
    Serial.println("unit 2 if");
      if(val >= 1 && val <= 179)
      { 
      myservo_2.write(val);
      Serial.println("SERVO 2 Location :"+String(val));
      }
      else
      {
      Serial.println("Enter a position value between 0 and 180");
      }
  }
  else if( unit == 3) //Enter if data received is for Servo 3
  {
    Serial.println("unit 3 if");
      if(val >= 1 && val <= 179)
      { 
      myservo_3.write(val);
      Serial.println("SERVO 3 Location :"+String(val));
      }
      else
      {
      Serial.println("Enter a position value between 0 and 180");
      }
  }
  else if( (unit) == 4) //Enter if data received is for Servo 4
  {
    Serial.println("unit 4 if");
      if(val >= 1 && val <= 179)
      { 
      myservo_4.write(val);
      Serial.println("SERVO 4 Location :"+String(val));
      }
      else
      {
      Serial.println("Enter a position value between 0 and 180");
      }
  }
  else //Enter if any data received is not addressed to any of the servo defined 
  {
    Serial.println("SERVO '"+String(unit)+"' Not Found");
  }
  val = 0;
  Serial.println("Val :"+String(val));
  unit = 0;
  Serial.println("Unit :"+String(unit));
}}
  delay(500);
  }
