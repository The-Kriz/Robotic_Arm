//Contrlling Robotic Arm using PS2 Controller

//Importing library
#include <Servo.h>
#include <PS2X_lib.h>    

//Servo
#define Servo1 3
#define Servo2 5
#define Servo3 6
#define Servo4 9
Servo myservo_1,myservo_2,myservo_3,myservo_4;

//PS2 pins
PS2X ps2x; 
#define  ps2_clock 13
#define  ps2_command 11
#define  ps2_attention 10
#define  ps2_data 12
#define  ps2_Pressures true
#define  ps2_Rumble true

// variables 
int error = 0; 
byte type = 0;
byte vibrate = 0;

int Servo_val1 = 90 ; 
int Servo_val2 = 90 ;
int Servo_val3 = 90 ;
int Servo_val4 = 90 ;

int pss_val_high_high = 255;
int pss_val_high_low = 170;
int pss_val_low_high = 85;
int pss_val_low_low = 0;

void setup() 
{
  
  Serial.begin(57600);
  myservo_1.attach(Servo1);
  myservo_2.attach(Servo2);
  myservo_3.attach(Servo3);
  myservo_4.attach(Servo4);


  error = ps2x.config_gamepad(ps2_clock,ps2_command,ps2_attention,ps2_data,ps2_Pressures,ps2_Rumble);
  if(error == 0)
  {
    Serial.println("Found Controller, configured successful");
    Serial.println("Try out all the buttons, X will vibrate the controller, faster as you press harder;");
    Serial.println("holding L1 or R1 will print out the analog stick values.");
  }
   else if(error == 1)
    Serial.println("No controller found");
   else if(error == 2)
    Serial.println("Controller found but not accepting commands");
   else if(error == 3)
    Serial.println("Controller refusing to enter Pressures mode, may not support it. ");
    type = ps2x.readType(); 
      switch(type) 
      {
        case 0:
         Serial.println("Unknown Controller type");
        break;
        case 1:
         Serial.println("DualShock Controller Found");
        break;
        case 2:
          Serial.println("GuitarHero Controller Found");
        break;
      }
}


void loop() 
{
  
  int lJoyY = ps2x.Analog(PSS_LY);
  int lJoyX = ps2x.Analog(PSS_LX);
  int rJoyY = ps2x.Analog(PSS_RY);
  int rJoyX = ps2x.Analog(PSS_RX);
  
  //left joystick
  
  if (ps2x.Button(PSB_L1))
  {
    if ( lJoyX >=pss_val_high_low && lJoyX <= pss_val_high_high )
    { 
      Servo_val1 += 1;
      myservo_1.write(Servo_val1);
    }
    if ( lJoyX >= pss_val_low_low && lJoyX <= pss_val_low_high )
    { 
      Servo_val1 -= 1;
      myservo_1.write(Servo_val1);
    }
  }

  if (ps2x.Button(PSB_L2))
  {
    if ( lJoyX >=pss_val_high_low && lJoyX <= pss_val_high_high )
    { 
      Servo_val2 += 1;
      myservo_2.write(Servo_val2);
    }
    if ( lJoyX >= pss_val_low_low && lJoyX <= pss_val_low_high )
    { 
      Servo_val2 -= 1;
      myservo_2.write(Servo_val2);
    }
  }
  
  //right joystick
  
  if (ps2x.Button(PSB_R1))
  {
    if ( lJoyX >=pss_val_high_low && lJoyX <= pss_val_high_high )
    { 
      Servo_val3 += 1;
      myservo_3.write(Servo_val3);
    }
    if ( lJoyX >= pss_val_low_low && lJoyX <= pss_val_low_high )
    { 
      Servo_val3 -= 1;
      myservo_3.write(Servo_val3);
    }
  }
  
  if (ps2x.Button(PSB_R2)) // RESET TO 90*
  {
    if ( lJoyX >=pss_val_high_low && lJoyX <= pss_val_high_high )
    { 
      myservo_4.write(Servo_val4);
    }
    if ( lJoyX >= pss_val_low_low && lJoyX <= pss_val_low_high )
    { 
      Servo_val4 -= 1;
      myservo_4.write(Servo_val4);
    }
  }

  if (ps2x.Button(PSB_CROSS))
  {
    Servo_val1 = 90 ; 
    Servo_val2 = 90 ;
    Servo_val3 = 90 ;
    Servo_val4 = 90 ;
    myservo_1.write(Servo_val1);
    myservo_2.write(Servo_val2);
    myservo_3.write(Servo_val3);
    myservo_4.write(Servo_val4);
   }
    
  Serial.println("SERVO 1 Location :"+String(Servo_val1));
  Serial.println("SERVO 2 Location :"+String(Servo_val2));
  Serial.println("SERVO 3 Location :"+String(Servo_val3));
  Serial.println("SERVO 4 Location :"+String(Servo_val4));
  
  delay(500);
  
}
