#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void interface(void);
char u_input(void);
int value_user_input(void);

int incomingByte = 0;   // for incoming serial data

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
        cZ = value_user_input();
        break;
      case 52:
        Serial.print("Setting servo's\n");
        Hoeken(cX, cY, cZ);
        Serial.print("servo's set\n");
        break;
       default:
        Serial.print("Bad input");
    }
  }
}

char u_input(void)
{
  unsigned char i_buffer = -1;

  while (i_buffer == 255)
  {
    i_buffer = Serial.read();
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
      return(atoi(inString));
    }
  }
}
