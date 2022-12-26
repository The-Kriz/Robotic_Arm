float Angle_1 = 0;
float Angle_2 = 0;

float linkLength_1;
float linkLength_2;

float A;
float B;
float C;
float theta;

float endEffector_X;
float endEffector_Y;
float Hypotenuse;
const float pi = M_PI;

int flag = 0;


void setup() {
  Serial.begin(9600);
  linkLength_1 = 5;
  linkLength_2 = 5;
  endEffector_X = 0;
  endEffector_Y = 10;

}

void loop() {
  if ( flag = 0) {
    backwardKinematics();
    delay(500);
    flag = 1;
  }
  delay(500);
}

void backwardKinematics()
{
  Hypotenuse = sqrt( sq(endEffector_X) + sq(endEffector_Y) );
  B = (acos( (sq(linkLength_2) - sq(linkLength_1) - sq(Hypotenuse)) / (-2 * linkLength_1 * Hypotenuse) )) * (180 / pi);
  C = (acos( (sq(Hypotenuse) - sq(linkLength_2) - sq(linkLength_1)) / (-2 * linkLength_1 * linkLength_2) )) * (180 / pi);
  theta = (asin( endEffector_Y / Hypotenuse )) * (180 / pi);
  Angle_1 = B + theta  ;
  Angle_2 = C;
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
  Serial.println(Angle_1);
  Serial.print("angle2 is ");
  Serial.println(Angle_2);
}
