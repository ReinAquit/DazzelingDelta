

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Servo.h>

//standaardposities en afmetingen delta//
#define Pservo1X -40
#define Pservo1Y 0
#define Pservo1Z 0

#define Pservo2X -50
#define Pservo2Y 17
#define Pservo2Z 0

#define Pservo3X -80
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

void setup()
{
  
  Serial.begin(9600);
  
  Servo1.attach(9);
  Servo2.attach(10);
  Servo3.attach(11);
  
}

void loop()
{
  interface();
}
