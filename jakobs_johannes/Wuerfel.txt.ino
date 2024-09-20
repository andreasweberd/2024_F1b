void setup() {
  // put your setup code here, to run once:
  pinMode(5, INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
}

int ergebnis = 0;

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(5)==HIGH){
    ledsAus();
    ergebnis = random(1,7);
    Serial.println(ergebnis);
    
    anzeigen(ergebnis);
    }

  delay(100);
}

void ledsAus(){
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
}

void anzeigen(int ergebnis){
  if(ergebnis == 1){
    digitalWrite(6, HIGH);
  }
  else if(ergebnis == 2){
    digitalWrite(9, HIGH);
    digitalWrite(12, HIGH);
  }
  else if(ergebnis == 3){
    digitalWrite(6, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(12, HIGH);
  }
  else if(ergebnis == 4){
    digitalWrite(7, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(12, HIGH);
  }
  else if(ergebnis == 5){
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(12, HIGH);
  }
  else if(ergebnis == 6){
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
  }
  
}
