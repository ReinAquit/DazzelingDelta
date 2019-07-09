#include <AccelStepper.h>

// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver:

void stepper_steps(int stepper,int steps);
void stepper_write(int motor, float des_angle);

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
#define STEP_MOT_B 10
#define STEP_MOT_C 11

#define MOT_SLEEP 7
#define MOT_RESET 8

#define motorInterfaceType1 1
#define motorInterfaceType2 1
#define motorInterfaceType3 1

#define MOT_speed 640
#define step_size 0.05625
  
// Create a new instance of the AccelStepper class:
AccelStepper stepper1 = AccelStepper(motorInterfaceType1, STEP_MOT_A, DIR_MOT_A);
AccelStepper stepper2 = AccelStepper(motorInterfaceType2, STEP_MOT_B, DIR_MOT_B);
AccelStepper stepper3 = AccelStepper(motorInterfaceType3, STEP_MOT_C, DIR_MOT_C);

float angle_A = 0;
float angle_B = 0;
float angle_C = 0;
  
void setup() 
{
  // Set the maximum speed in steps per second:
  stepper1.setMaxSpeed(1000);
  stepper2.setMaxSpeed(1000);
  stepper3.setMaxSpeed(1000);

  //sleep en reset high Arduino Nano
  digitalWrite(MOT_SLEEP, HIGH); 
  digitalWrite(MOT_RESET, HIGH);

  //Reset the position to 0:
  stepper1.setCurrentPosition(0);
  stepper2.setCurrentPosition(0);
  stepper3.setCurrentPosition(0);
}

void loop() 
{

  stepper_steps(STEP_MOT_B, 400, 0);
  delay(1000);
  stepper_steps(STEP_MOT_B, 120, 1);
  delay(1000);
  stepper_steps(STEP_MOT_B, 200, 0);
  delay(1000);
  stepper_steps(STEP_MOT_B, 480, 1);
  delay(1000);

}

void stepper_steps(int16_t stepper,int16_t steps,int dir)
{

  if(dir == 0) dir = -1;
  else dir = 1;

  switch (stepper)
  {
    case STEP_MOT_A:
      while (stepper1.currentPosition() != (steps * dir)) //motor 1 speed
      {
        stepper1.setSpeed(MOT_speed * dir);
        stepper1.runSpeed();
      }
      break;
    case STEP_MOT_B:
      while (stepper2.currentPosition() != (steps * dir)) //motor 1 speed
      {
        stepper2.setSpeed(MOT_speed * dir);
        stepper2.runSpeed();
      }
      break;
    case STEP_MOT_C:
      while (stepper3.currentPosition() != (steps * dir)) //motor 1 speed
      {
        stepper3.setSpeed(MOT_speed * dir);
        stepper3.runSpeed();
      }
      break; 
  }
  stepper1.setCurrentPosition(0);   
  stepper2.setCurrentPosition(0);
  stepper3.setCurrentPosition(0);
}


void stepper_write(int motor, float des_angle)
{  

  float mov_buffer;
  float angle = 0;
  int8_t dir = 0;

  switch(motor)
  {
    case STEP_MOT_A:
      if(des_angle == angle_A) break;  
      angle = angle_A;
      if(des_angle > angle_A)
      {   
        mov_buffer = (des_angle - angle_A);
        dir = 1;
      }
      else if(des_angle < angle_A)
      {   
        mov_buffer = (angle_A - des_angle);
        dir = 0;
      }  
      mov_buffer = (mov_buffer / step_size);
      stepper_steps(STEP_MOT_A, (int)mov_buffer, dir);
      angle_A = des_angle;
      break;    
    case STEP_MOT_B:
      angle = angle_B;
      if(des_angle > angle_B)
      {   
        mov_buffer = (des_angle - angle_B);
        dir = 1;
      }
      else if(des_angle < angle_B)
      {   
        mov_buffer = (angle_B - des_angle);
        dir = 0;
      }    
      mov_buffer = (mov_buffer / step_size);
      stepper_steps(STEP_MOT_B, (int)mov_buffer, dir);
      angle_B = des_angle;
      break;
    case STEP_MOT_C:
      angle = angle_C;
      if(des_angle > angle_C)
      {   
        mov_buffer = (des_angle - angle_C);
        dir = 1;
      }
      else if(des_angle < angle_C)
      {   
        mov_buffer = (angle_C - des_angle);
        dir = 0;
      }    
      mov_buffer = (mov_buffer / step_size);
      stepper_steps(STEP_MOT_C, (int)mov_buffer, dir);
      angle_C = des_angle;
      break;
  }
}  
