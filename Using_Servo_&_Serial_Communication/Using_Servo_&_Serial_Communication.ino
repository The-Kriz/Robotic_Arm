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

int incomingByte = 0;
int count = 0;
int data =0;

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
    // read the incoming byte:
    byte  incoming  = Serial.read();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(incoming);
    int incomingByte = (int(incoming)-48);
    Serial.println("incomingByte:"+String(incomingByte));
    data = data*10+incomingByte;
    Serial.println("data:"+String(data));
    count +=1;
    Serial.println("count:"+String(count));
  }
  if (count == 4)
{
  Serial.println("inside if");
  if( (incomingByte%10) == 1)
  {
      Serial.println(incomingByte);
      incomingByte = incomingByte/10;
      Serial.println(incomingByte);
      if(incomingByte > 1 && incomingByte < 180)
      { 
      myservo_1.write(incomingByte);
      Serial.println("SERVO 1 Location :"+String(incomingByte));
      }
      Serial.println(incomingByte);
      incomingByte = 0;
      Serial.println(incomingByte);
  }
  else if( (incomingByte%10) == 2)
  {
      incomingByte = incomingByte/10;
      if(incomingByte > 1 && incomingByte < 180)
      { 
      myservo_2.write(incomingByte);
      Serial.println("SERVO 2 Location :"+String(incomingByte));
      }
      incomingByte = 0;
  }
  else if( (incomingByte%10) == 3)
  {
      incomingByte = incomingByte/10;
      if(incomingByte > 1 && incomingByte < 180)
      { 
      myservo_3.write(incomingByte);
      Serial.println("SERVO 3 Location :"+String(incomingByte));
      }
      incomingByte = 0;
  }
  else if( (incomingByte%10) == 4)
  {
      incomingByte = incomingByte/10;
      if(incomingByte > 1 && incomingByte < 180)
      { 
      myservo_4.write(incomingByte);
      Serial.println("SERVO 4 Location :"+String(incomingByte));
      }
      incomingByte = 0;
  }  
//  Servo_val = map(analogRead(poten1),0, 1023, 0, 179);
//  myservo_1.write(Servo_val);
//  Servo_va2 = map(analogRead(poten2),0, 1023, 0, 179);
//  myservo_2.write(Servo_va2);
//  Servo_va3 = map(analogRead(poten3),0, 1023, 0, 179);
//  myservo_3.write(Servo_va3);
//  Servo_va4 = map(analogRead(poten4),0, 1023, 0, 179);
//  myservo_4.write(Servo_va4);
  

//  Serial.println("SERVO 2 Location :"+String(Servo_va2));
//  Serial.println("SERVO 3 Location :"+String(Servo_va3));
//  Serial.println("SERVO 4 Location :"+String(Servo_va4));
  count = 0;
  data = 0;
  delay(500);
  }
}
