float linkLength_1;
float linkLength_2;

float pi = 3.14159265359;

float angle_1;
float angle_2;
float radAngle_1;
float radAngle_2;

int f = 2;

float endEffector_X;
float endEffector_Y;

void setup()
{
  Serial.begin(9600);
  linkLength_1 = 5;
  linkLength_2 = 5;

  angle_1 = 10;
  angle_2 = 20;

  radAngle_1 = (angle_1 * pi) / 180;
  radAngle_2 = (angle_2 * pi) / 180;
}

void loop()
{
  forwardKinematics();
  delay(500);
}
void forwardKinematics()
{
    if(f==1)
    {
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
      f = 0;
    }
}
