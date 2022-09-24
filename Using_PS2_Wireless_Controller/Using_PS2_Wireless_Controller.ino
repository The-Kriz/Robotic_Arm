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

