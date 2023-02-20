#include <EEPROM.h>
int i = 0;
int value; 


int outPin[] = {2,3,4,5,6,7,8,9};
 
int delayValue = 500;
 
void setup()
{
    Serial.begin(9600);
  int i = 0;
  for ( i = 0; i < 8; i++)//5
    pinMode(outPin[i], OUTPUT);
}
 
void loop()
{

  int i = 0, j=0;
 
  for ( i = 0; i < 255; i++)
  {
       value = EEPROM.read(i);

  Serial.print(i);
  Serial.print("\t");
  Serial.print(value);  
  Serial.println();

    i =  + 1;

     for ( j = 0; j < 8; j++)//5
     {
       if ( ( (i >> j) & 1 )  == 1 )
           digitalWrite(outPin[j], HIGH);
       else digitalWrite(outPin[j], LOW);
     }
     delay(delayValue);
  }
}
/*
int a = 0;
int value; 

void setup() {
  Serial.begin(9600);
}

void loop() {
  value = EEPROM.read
    (a);

  Serial.print(a);
  Serial.print("\t");
  Serial.print(value);  
  Serial.println();

  a = a + 1;

  if(a==512)
  a = 0;
  delay(500);
}
*/