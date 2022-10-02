//Contrlling Robotic Arm using PS2 Controller

//Importing library
#include <Servo.h>
#include <Stepper.h>
#include <PS2X_lib.h>    

//Servo
#define Stepper1_1 10
#define Stepper1_2 10
#define Stepper1_3 10
#define Stepper1_4 10

#define Stepper2_1 10
#define Stepper2_2 10
#define Stepper2_3 10
#define Stepper2_4 10

#define Stepper3_1 10
#define Stepper3_2 10
#define Stepper3_3 10
#define Stepper3_4 10

#define Stepper4_1 10
#define Stepper4_2 10
#define Stepper4_3 10
#define Stepper4_4 10

int Stepper1_total_step  = 2048 ; 
int Stepper2_total_step = 2048 ;
int Stepper3_total_step = 2048 ;
int Stepper4_total_step = 2048 ;

int Stepper_val1 = Stepper1_total_step/2 ; 
int Stepper_val2 = Stepper2_total_step/2 ;
int Stepper_val3 = Stepper3_total_step/2 ;
int Stepper_val4 = Stepper4_total_step/2 ;

int Stepper_speed1 = 10;
int Stepper_speed2 = 10;
int Stepper_speed3 = 10;
int Stepper_speed4 = 10;


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

Stepper mystepper_1( Stepper1_total_step, Stepper1_1, Stepper1_2, Stepper1_3, Stepper1_4);
Stepper mystepper_2( Stepper2_total_step, Stepper2_1, Stepper2_2, Stepper2_3, Stepper2_4);
Stepper mystepper_3( Stepper3_total_step, Stepper3_1, Stepper3_2, Stepper3_3, Stepper3_4);
Stepper mystepper_4( Stepper4_total_step, Stepper4_1, Stepper4_2, Stepper4_3, Stepper4_4);

void setup() 
{
  
  Serial.begin(57600);
  mystepper_1.setSpeed(Stepper_speed1);
  mystepper_2.setSpeed(Stepper_speed2);
  mystepper_3.setSpeed(Stepper_speed3);
  mystepper_4.setSpeed(Stepper_speed4);
  
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
    if ( lJoyX > 50 )
    { 
      Stepper_val1 += 1;
      mystepper_1.step(Stepper_val1);
    }
    if ( lJoyX < -50 )
    { 
      Stepper_val1 -= 1;
      mystepper_1.step(Stepper_val1);
    }
  }

  if (ps2x.Button(PSB_L2))
  {
    if ( lJoyX > 50 )
    { 
      Stepper_val2 += 1;
      mystepper_2.step(Stepper_val2);
    }
    if ( lJoyX < -50 )
    { 
      Stepper_val2 -= 1;
      mystepper_2.step(Stepper_val2);
    }
  }
  
  //right joystick
  
  if (ps2x.Button(PSB_R1))
  {
    if ( rJoyX > 50 )
    { 
      Stepper_val3 += 1;
      mystepper_3.step(Stepper_val3);
    }
    if ( rJoyX < -50 )
    { 
      Stepper_val3 -= 1;
      mystepper_3.step(Stepper_val3);
    }
  }
  
  if (ps2x.Button(PSB_R2)) 
  {
    if ( rJoyX > 50 )
    {
      mystepper_4.step(Stepper_val4);
    }
    if ( rJoyX < -50 )
    { 
      Stepper_val4 -= 1;
      mystepper_4.step(Stepper_val4);
    }
  }

  if (ps2x.Button(PSB_CROSS)) // RESET TO 90*
  {
    Stepper_val1 = Stepper1_total_step/2 ; 
    Stepper_val2 = Stepper2_total_step/2 ;
    Stepper_val3 = Stepper3_total_step/2 ;
    Stepper_val4 = Stepper4_total_step/2 ;
    mystepper_1.step(Stepper_val1);
    mystepper_2.step(Stepper_val2);
    mystepper_3.step(Stepper_val3);
    mystepper_4.step(Stepper_val4);
   }
    
  Serial.println("STEPPER 1 Location :"+String(Stepper_val1));
  Serial.println("STEPPER 2 Location :"+String(Stepper_val2));
  Serial.println("STEPPER 3 Location :"+String(Stepper_val3));
  Serial.println("STEPPER 4 Location :"+String(Stepper_val4));
  
  delay(500);
  
}
