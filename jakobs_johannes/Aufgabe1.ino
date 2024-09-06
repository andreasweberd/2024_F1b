void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
}

int x=0;

void loop() {
  x=x+1;
  if (x<=5)
  {
    blink();
  }
  analogWrite(9, 0);
  delay(5000);
}

int blink() {
  analogWrite(9, 255);
  delay(1000);
}