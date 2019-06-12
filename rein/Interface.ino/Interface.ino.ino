
void interface(void);

int incomingByte = 0;   // for incoming serial data

void setup()
{
  Serial.begin(9600);

  
}

void loop()
{

  interface();
    
  if (Serial.available() > 0) 
  {
                Serial.print("Vul ff een lekker nummertje in");
                // read the incoming byte:
                incomingByte = Serial.read();

                // say what you got:
                Serial.print("I received: ");
                Serial.print(incomingByte);
                Serial.println(incomingByte,DEC);
  }
  
}

void interface(void)
{
  int i_buffer = 0;

  int cX = 0;
  int cY = 0;
  int cZ = 0;
  
  Serial.print("Coördinates:");
  
  Serial.print("\n[1] X = ");
  Serial.print(cX);
  Serial.print("\n[2] Y = ");
  Serial.print(cY);
  Serial.print("\n[3] Z = ");
  Serial.print(cZ);

  Serial.print("\n[4] set pos\n");

  input = u_input();

  switch(input){
    case (char)1:
      Serial.print("Enter a Value\n");
      
      break;
    case (char)2:
      break;
    case (char)3:
      break;
  {
}

char u_input(void)
{
  char i_buffer = 0;

  while(i_buffer =! 0)
  {
    i_buffer = Serial.read();
  }
  return(i_buffer);
}
