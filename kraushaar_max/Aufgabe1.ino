int LED = 9;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {

  //analogWrite(LED, 100);
  //delay(1000);
  //analogWrite(LED, 0);
  //delay(1000);
  blink(5);
}


int blink(int a){
  if (a >= 1) {
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
    a = a - 1;
  }
}