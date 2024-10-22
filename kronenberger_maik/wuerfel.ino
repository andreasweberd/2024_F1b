int erg = 0;
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

void loop() {
  if(digitalRead(5) == HIGH){
    erg = random(1,6);
    aus();
    Serial.println(erg);
    ergebnisFinden(erg);
    


  }
  delay(500);
}

void ergebnisFinden(int erg){
  if(erg == 1){
    digitalWrite(6, HIGH);
  }
  if(erg == 2){
    digitalWrite(12, HIGH);
    digitalWrite(9, HIGH);
  }
  if(erg == 3){
    digitalWrite(12, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(6, HIGH);
  }
  if(erg == 4){
    digitalWrite(12, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(9, HIGH);

  }
  if(erg == 5){
    digitalWrite(12, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
  }
  if(erg == 6){
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
  }

}



void aus(){
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);

}
