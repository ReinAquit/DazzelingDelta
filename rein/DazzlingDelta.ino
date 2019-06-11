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

#define delay_step 10 //Delay between high and low
#define delay_pulse 10

void stepper_cal(byte stepper_mot); //a,b or c
void stepper_mov_steps(int stepper,int steps);

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

    digitalWrite

    stepper_cal(a);
    stepper_cal(b);
    stepper_cal(c);

}

void loop() 
{


}

void stepper_cal(char stepper_mot)
{

    int stepper = 0;
    int stopper = 0;

    switch (stepper_mot)
    {
    case 97:
    case 65:
        stepper = STEP_MOT_A;
        dir_step = DIR_MOT_A;
        stopper = END_STOP_A;
        break;
    case 98:
    case 66:
        stepper = STEP_MOT_B;
        dir_step = DIR_MOT_B;
        stopper = END_STOP_B;
        break;
    case 99:
    case 67:
        stepper = STEP_MOT_C;
        dir_step = DIR_MOT_C;
        stopper = END_STOP_C;
        break;
    default:
        return(0);
        break;
    }

    digitalWrite(, LOW);

    while(analogRead(stopper) > 50)
    {
        digitalWrite(stepper, HIGH);
        delay(delay_step);
        digitalWrite(stepper, LOW);
        delay(delay_pulse);
    }

}

void stepper_mov_steps(int stepper,int steps)
{
    for(i = steps, i == 0, i--)
    {
        digitalWrite(stepper, HIGH);
        delay(delay_step);
        digitalWrite(stepper, LOW);
        delay(delay_pulse);
    }
}
