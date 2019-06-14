#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Servo.h>

//standaardposities en afmetingen delta//
#define Pservo1X 100
#define Pservo1Y 0
#define Pservo1Z 0

#define Pservo2X -50
#define Pservo2Y 87
#define Pservo2Z 0

#define Pservo3X -50
#define Pservo3Y - 87
#define Pservo3Z 0

#define nulpuntX 0
#define nulpuntY 0
#define nulpuntZ 0

#define Lbase 100
#define Larm1 50
#define Larm2 185
#define Ltop 40
#define Larmmax 190
#define Larmmin 180

//variabelen voor berekening van gewrichtlocaties//
float Hoek1;
float Hoek2;
float Hoek3;

float Ppols1X;
float Ppols1Y;
float Ppols1Z;

float Ppols2X;
float Ppols2Y;
float Ppols2Z;

float Ppols3X;
float Ppols3Y;
float Ppols3Z;

float Pelleboog1X;
float Pelleboog1Y;
float Pelleboog1Z;

float Pelleboog2X;
float Pelleboog2Y;
float Pelleboog2Z;

float Pelleboog3X;
float Pelleboog3Y;
float Pelleboog3Z;

//berekende lengte arm2//
float Larm2s1;
float Larm2s2;
float Larm2s3;

//variabelen voor doelpositie//
int PdoelX = 0;
int PdoelY = 0;
int PdoelZ = 0;

//starthoeken servos//
float pos1 = -1.1345;
float pos2 = -1.1345;
float pos3 = -1.1345;

//60 graden in radialen//
#define graden60 1.04719

//definieer servos//
Servo Servo1;
Servo Servo2;
Servo Servo3;

//variabelen voor interface//
void interface(void);
char u_input(void);
int value_user_input(void);

int incomingByte = 0;   // for incoming serial data


void setup()
{
  
  Serial.begin(9600);
  
  Servo1.attach(9);
  Servo2.attach(10);
  Servo3.attach(11);
  
}

void loop()
{
  Hoeken(0,70,140);
  delay(1);
  
  interface();
}

void interface(void)
{
  int i = 1;
  int i_buffer = 0;

  char input = 0;

  int cX = 0;
  int cY = 0;
  int cZ = 0;

  while (i)
  {
    Serial.print("Coordinates:");

    Serial.print("\n[1] X = ");
    Serial.print(cX);
    Serial.print("\n[2] Y = ");
    Serial.print(cY);
    Serial.print("\n[3] Z = ");
    Serial.print(cZ);

    Serial.print("\n[4] set pos\n");

    input = u_input();

    switch (input) 
    {
      case 49:
        Serial.print("Enter a value for cor X\n");
        cX = value_user_input();
        break;
      case 50:
        Serial.print("Enter a value for cor Y\n");
        cY = value_user_input();
        break;
      case 51:
        Serial.print("Enter a value for cor Z\n");
        Serial.print("Prefferd between (100-140)\n");
        cZ = value_user_input();
        break;
      case 52:
        Serial.print("Setting servo's\n");
          Hoeken(cX,cY,cZ);
        Serial.print("servo's set\n");
        break;
       default:
        Serial.print("Bad input");
       
    }
    delay(10);
  }
}

char u_input(void)
{
  unsigned char i_buffer = -1;

  while (i_buffer == 255)
  {
    i_buffer = Serial.read();
    delay(10);
  }
  return (i_buffer);
}

int value_user_input(void)
{

  byte inChar;
  char inString[10];


  while(1)
  {
    while (Serial.available() > 0) 
    {
      inChar = Serial.readBytesUntil('\n', inString, 10);
      inString[inChar] = '\0';
      delay(10);
      return(atoi(inString));
    }
  }
}

float BerekenHoek1()
{
  Larm2s1 = BerekenLengte1(PdoelX, PdoelY, PdoelZ);
  if ((Larm2s1 > 182) && (Larm2s1 < 188)) {
   Hoek1 = 115-pos1*180/PI;
   return(Hoek1);
   pos1 = -1.1345;
  }
  else {
   pos1 = pos1 + 0.017453;
  }
}

float BerekenHoek2() 
{
  Larm2s2 = BerekenLengte2(PdoelX, PdoelY, PdoelZ);
  if (Larm2s2 > 182 && Larm2s2 < 188) {
   Hoek2 = 115-pos2*180/PI;
   pos2 = -1.1345;
   return(Hoek2);
  }
  else {
    pos2 = pos2 + 0.017453;
  }
}
  
float BerekenHoek3()
{
  Larm2s3 = BerekenLengte3(PdoelX, PdoelY, PdoelZ);
  if ((Larm2s3 > 182) && (Larm2s3 < 188)){
   Hoek3 = 115-pos3*180/PI;
   //Servo3.write(Hoek3);
   return(Hoek3);
   pos3 = -1.1345;
  }
  else {
   pos3 = pos3 + 0.017453;
  }
}

//Functies die 3 coordinaten omrekenen naar de bijbehorende servohoek//
float BerekenLengte1 (int A, int B, int C)
{
  Ppols1X = A + Ltop;
  Ppols1Y = B;
  Ppols1Z = C;
  
  Pelleboog1X = Pservo1X + Larm1*cos(pos1);
  Pelleboog1Y = Pservo1Y;
  Pelleboog1Z = Pservo1Z + Larm1*sin(pos1);

  Larm2s1 = sqrt(sq(Ppols1X-Pelleboog1X)+sq(Ppols1Y-Pelleboog1Y)+sq(Ppols1Z-Pelleboog1Z));
  return(Larm2s1);
}

float BerekenLengte2 (int A, int B, int C)
{
  Ppols2X = A - cos(graden60)* Ltop;
  Ppols2Y = B + sin(graden60)* Ltop;
  Ppols2Z = C;

  Pelleboog2X = Pservo2X - cos(graden60)*Larm1*cos(pos2);
  Pelleboog2Y = Pservo2Y + sin(graden60)*Larm1*cos(pos2);
  Pelleboog2Z = Pservo2Z + Larm1*sin(pos2);

  Larm2s2 = sqrt(sq(Ppols2X-Pelleboog2X)+sq(Ppols2Y-Pelleboog2Y)+sq(Ppols2Z-Pelleboog2Z));
  return(Larm2s2);
}

float BerekenLengte3 (int A, int B, int C)
{
  Ppols3X = A - cos(graden60)* Ltop;
  Ppols3Y = B - sin(graden60)* Ltop;
  Ppols3Z = C;

  Pelleboog3X = Pservo3X - cos(graden60)*Larm1*cos(pos3);
  Pelleboog3Y = Pservo3Y - sin(graden60)*Larm1*cos(pos3);
  Pelleboog3Z = Pservo3Z + Larm1*sin(pos3);
  
  Larm2s3 = sqrt(sq(Ppols3X-Pelleboog3X)+sq(Ppols3Y-Pelleboog3Y)+sq(Ppols3Z-Pelleboog3Z));
  return(Larm2s3);
}

/*Deze functie veranderd de doelposities naar de invoer in de functie en laat de 
servomotoren aansturen zodra er een benaderde hoek is gevonden*/
float Hoeken (int X, int Y, int Z){
  PdoelX = X;
  PdoelY = Y;
  PdoelZ = Z;
  Servo1.write(BerekenHoek1());
  Servo2.write(BerekenHoek2());
  Servo3.write(BerekenHoek3());
}
