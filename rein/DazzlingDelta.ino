//--------------------------------------------------------------
// File     : DazzlingDelta.ino
// Datum    : 10.06.2019
// Version  : 1.0
// Autor    : Rein Lenting
// CPU      : ATmega328
// IDE      : Visual Ctudio Code
// Module   : Arduino Nano
// Function : Stepper driver control (DRV8825)
//--------------------------------------------------------------

#include "main.h"

//Pin Define'setup
//Analog
#define END_STOP_A 0
#define END_STOP_B 1
#define END_STOP_C 2

//Digital
#define DIR_MOT_A 2
#define DIR_MOT_B 3
#define DIR_MOT_C 4

#define STEP_MOT_A 9
#define STEP_MOT_A 10
#define STEP_MOT_A 11

#define MOT_SLEEP 7
#define MOT_RESET 8

stepper_cal(byte stepper_mot);

void setup() 
{
    //Input
    pinMode(END_STOP_A, INPUT);
    pinMode(END_STOP_B, INPUT);
    pinMode(END_STOP_C, INPUT);
    
    //Output
    pinMode(DIR_MOT_A, OUTPUT);
    pinMode(DIR_MOT_B, OUTPUT);
    pinMode(DIR_MOT_C, OUTPUT);

    pinMode(STEP_MOT_A, OUTPUT);
    pinMode(STEP_MOT_B, OUTPUT);
    pinMode(STEP_MOT_C, OUTPUT);

    pinMode(MOT_SLEEP, OUTPUT);
    pinMode(MOT_RESET, OUTPUT);

    stepper_cal(a);
    stepper_cal(a);
    stepper_cal(a);
}


void loop() 
{



}

int stepper_cal(char stepper_mot)
{

    int stepper = 0;
    int stopper = 0;

    switch (stepper_mot)
    {
    case 97:
    case 65:
        stepper = DIR_MOT_A;
        stopper = END_STOP_A;
        stop
        break;
    case 98:
    case 66:
        stepper = DIR_MOT_B;
        stopper = END_STOP_B;
        break;
    case 99:
    case 67:
        stepper = DIR_MOT_C;
        stopper = END_STOP_C;
        break;
    default:
        return(0);
        break;
    }

    digitalWrite(servo, LOW);

    while(analogRead())


}