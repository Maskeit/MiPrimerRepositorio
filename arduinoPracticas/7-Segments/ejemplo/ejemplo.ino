void setup() {
  // put your setup code here, to run once:
DDRD = B10000000;

}

void loop() {
  // put your main code here, to run repeatedly:
  PORTD = B10000000;
  delay(10000);

  PORTD = B00000000;
  delay(10000);

}
