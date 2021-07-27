#include <Servo.h>

Servo base, spalla1, spalla2, gomito1, gomito2, polso, mano;
int p_base, p_spalla1, p_spalla2, p_gomito1, p_gomito2, p_polso, p_mano;
int sfasatura_base=8;
int a,b,c;

void setup()
{
  Serial.begin(9600);
  
  spalla1.attach(2);
  spalla2.attach(3);
  gomito1.attach(4);
  gomito2.attach(5);

  reset();

  delay (1000);
 }

void loop()
{
  muovi_spalla(p_spalla1,p_spalla1+50,10);
  delay(1000);
  muovi_spalla(p_spalla1,p_spalla1-100,10);
  delay(1000);
  muovi_spalla(p_spalla1,p_spalla1+50,10);
  delay(1000);
  muovi_gomito(p_gomito1,p_gomito1+50,10);
  delay(1000);
  muovi_gomito(p_gomito1,p_gomito1-100,10);
  delay(1000);
  muovi_gomito(p_gomito1,p_gomito1+50,10);
  delay(1000);
}

void  muovi_spalla(int pos_iniz, int pos_fin, int rit)
{
  int i,j=p_spalla2;
  //Serial.println("");
  if (pos_iniz<pos_fin)
  {
      for(i=pos_iniz;i<pos_fin;i++)
      {
        spalla1.write(i); 
        j--;
        spalla2.write(j);
        delay(rit);
        //Serial.print(i);Serial.print(" ");
      }
  }

  if (pos_iniz>pos_fin)
  {
      for(i=pos_iniz;i>pos_fin;i--)
      {
        spalla1.write(i); 
        j++;
        spalla2.write(j);
        delay(rit);
        //Serial.print(".");
      }
  }    
  Serial.println("");
  p_spalla1=i;
  p_spalla2=j;
    Serial.println(i);
    Serial.println(j);
}


void  muovi_gomito(int pos_iniz, int pos_fin, int rit)
{
  int i,j=p_gomito2;
  //Serial.println("");
  if (pos_iniz<pos_fin)
  {
      for(i=pos_iniz;i<pos_fin;i++)
      {
        gomito1.write(i); 
        j--;
        gomito2.write(j);
        delay(rit);
        //Serial.print(i);Serial.print(" ");
      }
  }

  if (pos_iniz>pos_fin)
  {
      for(i=pos_iniz;i>pos_fin;i--)
      {
        gomito1.write(i); 
        j++;
        gomito2.write(j);
        delay(rit);
        //Serial.print(".");
      }
  }    
  Serial.println("");
  p_gomito1=i;
  p_gomito2=j;
    Serial.println(i);
    Serial.println(j);
}


   void reset()
   {
      p_base=90;
      p_spalla1=99;
      p_spalla2=90;
      p_gomito1=90;
      p_gomito2=90;
      p_polso=90;
      p_mano=90;

      spalla1.write(p_spalla1);
      spalla2.write(p_spalla2);
      gomito1.write(p_gomito1);
      gomito2.write(p_gomito2);
   }

