  int my_array[10]= {B00000011,//0 B00000011 - B1111110
  
  B1001111, //1 B1001111 - B0110000
  B0010010, //2 B0010010 - B1101101
  B0000110, //3 B0000110 - B1111001
  B1001100, //4 B1001100 - B0110011
  B0100100, //5 B0100100 - B1011011
  B0100000, //6 B0100000 - B1011111
  B0001111, //7 B0001111 - B1110000
  B0000000, //8 B0000000 - B1111111
  B0001100};//9 B0001100 - B1110011

void setup() {
  // put your setup code here, to run once:
  DDRD = B10000000;
  delay(1000);
  
  DDRB = B11111111;//10000000
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  for(int i=0; i<=9; i++){
   PORTD = my_array[i];
  }

}

/*
a = d8 
b = d9
c = d10
d = d11
e = d12
f = d13
g = RELOJ
*/
