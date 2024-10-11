int ergebnis = 0;

void setup() {
  Serial.begin(9600);
  pinMode(5, INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {

  if(digitalRead(5)==HIGH) {
    ledsAus();

    ergebnis = random(1,7);
    Serial.println(ergebnis);

    anzeigen(ergebnis);
  }

  delay(100);
}

void ledsAus(){
  for (int i = 6; i <= 12; i++) {
    digitalWrite(i, LOW);
  }
}

void anzeigen(int ergebnis){
  if(ergebnis == 1){
    digitalWrite(6, HIGH);
  }else if(ergebnis == 2){
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
  }else if(ergebnis == 3){
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
  }else if(ergebnis == 4){
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
  }else if(ergebnis == 5){
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
  }else if(ergebnis == 6){
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
  }else {
    Serial.println("Fehler!");
  }
}






/* void loop() {
  for (int i = 6; i <= 12; i++) {
    digitalWrite(i, HIGH);
    delay(1000); // 100 ms Verzögerung zwischen den Schleifendurchläufen
    digitalWrite(i, LOW);
  }
  
  
  digitalWrite(6, HIGH);
  delay(100);
  digitalWrite(6, LOW);
  
  digitalWrite(7, HIGH);
  delay(100);
  digitalWrite(7, LOW);

  digitalWrite(8, HIGH);
  delay(100);
  digitalWrite(8, LOW);

  digitalWrite(9, HIGH);
  delay(100);
  digitalWrite(9, LOW);

  digitalWrite(10, HIGH);
  delay(100);
  digitalWrite(10, LOW);

  digitalWrite(11, HIGH);
  delay(100);
  digitalWrite(11, LOW);

  digitalWrite(12, HIGH);
  delay(100);
  digitalWrite(12, LOW);
} */

