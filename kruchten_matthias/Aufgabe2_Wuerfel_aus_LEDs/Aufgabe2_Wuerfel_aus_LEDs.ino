int ergebnis = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(5, INPUT);
  pinMode(6, OUTPUT); //Mitte Gelb
  pinMode(7, OUTPUT); //Unten Rechts
  pinMode(8, OUTPUT); //Unten Links
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(5)==HIGH){
    ledsAus();
    ergebnis = random(1, 7);
    Serial.println(ergebnis);
    
    delay(1000); //delay fühlt besser an.
    //eins
    if(ergebnis == 1){
    digitalWrite(6, HIGH);

    }
    //zwei
    else if(ergebnis == 2){
    digitalWrite(12, HIGH);
    digitalWrite(7, HIGH);

    }
    //drei
    else if(ergebnis == 3){
    digitalWrite(12, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);

    }
    //vier
    else if(ergebnis == 4){
    digitalWrite(12, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(8, HIGH);

    }
    //fünf
    else if(ergebnis == 5){
    digitalWrite(12, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(6, HIGH);

    }
    //sechs
    else if(ergebnis == 6){
    digitalWrite(12, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    }

    else {
      Serial.println("Hä");
    }

    
  }
  delay(300);

}

void ledsAus(){
  digitalWrite(6, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  digitalWrite(12, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(11, LOW);
}
