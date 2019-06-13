
//functies voor het veranderen van de servopositie in de berekening//
float BerekenHoek1()
{
  Larm2s1 = BerekenLengte1(PdoelX, PdoelY, PdoelZ);
  if ((Larm2s1 > 182) && (Larm2s1 < 188)) {
    Hoek1 = 115 - pos1 * 180 / PI;
    return (Hoek1);
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
    Hoek2 = 115 - pos2 * 180 / PI;
    pos2 = -1.1345;
    return (Hoek2);
  }
  else {
    pos2 = pos2 + 0.017453;
  }
}

float BerekenHoek3()
{
  Larm2s3 = BerekenLengte3(PdoelX, PdoelY, PdoelZ);
  if ((Larm2s3 > 182) && (Larm2s3 < 188)) {
    Hoek3 = 115 - pos3 * 180 / PI;
    //Servo3.write(Hoek3);
    return (Hoek3);
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

  Pelleboog1X = Pservo1X + Larm1 * cos(pos1);
  Pelleboog1Y = Pservo1Y;
  Pelleboog1Z = Pservo1Z + Larm1 * sin(pos1);

  Larm2s1 = sqrt(sq(Ppols1X - Pelleboog1X) + sq(Ppols1Y - Pelleboog1Y) + sq(Ppols1Z - Pelleboog1Z));
  return (Larm2s1);
}

float BerekenLengte2 (int A, int B, int C)
{
  Ppols2X = A - cos(graden60) * Ltop;
  Ppols2Y = B + sin(graden60) * Ltop;
  Ppols2Z = C;

  Pelleboog2X = Pservo2X - cos(graden60) * Larm1 * cos(pos2);
  Pelleboog2Y = Pservo2Y + sin(graden60) * Larm1 * cos(pos2);
  Pelleboog2Z = Pservo2Z + Larm1 * sin(pos2);

  Larm2s2 = sqrt(sq(Ppols2X - Pelleboog2X) + sq(Ppols2Y - Pelleboog2Y) + sq(Ppols2Z - Pelleboog2Z));
  return (Larm2s2);
}

float BerekenLengte3 (int A, int B, int C)
{
  Ppols3X = A - cos(graden60) * Ltop;
  Ppols3Y = B - sin(graden60) * Ltop;
  Ppols3Z = C;

  Pelleboog3X = Pservo3X - cos(graden60) * Larm1 * cos(pos3);
  Pelleboog3Y = Pservo3Y - sin(graden60) * Larm1 * cos(pos3);
  Pelleboog3Z = Pservo3Z + Larm1 * sin(pos3);

  Larm2s3 = sqrt(sq(Ppols3X - Pelleboog3X) + sq(Ppols3Y - Pelleboog3Y) + sq(Ppols3Z - Pelleboog3Z));
  return (Larm2s3);
}

/*Deze functie veranderd de doelposities naar de invoer in de functie en laat de
  servomotoren aansturen zodra er een benaderde hoek is gevonden*/
float Hoeken (int X, int Y, int Z) {
  PdoelX = 10;
  PdoelY = 70;
  PdoelZ = Z;
  Servo1.write(BerekenHoek1());
  Servo2.write(BerekenHoek2());
  Servo3.write(BerekenHoek3());
}
