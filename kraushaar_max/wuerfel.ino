int red1 = 6;
int red2 = 7;
int red3 = 8;
int red4 = 9;
int red5 = 10;
int red6 = 11;
int red7 = 12;
int taster = 5;

int tasterzustand = 0;
int ergebnis = 0;

void setup() {

Serial.begin(9600);

pinMode(red1, OUTPUT);
pinMode(red2, OUTPUT);
pinMode(red3, OUTPUT);
pinMode(red4, OUTPUT);
pinMode(red5, OUTPUT);
pinMode(red6, OUTPUT);
pinMode(red7, OUTPUT);
pinMode(taster, INPUT);
}

void loop() {

  tasterzustand = digitalRead(taster);

if (tasterzustand == HIGH){
  ledAus();
  ergebnis = random(1,7);
  Serial.println(ergebnis);
  anzeigen(ergebnis);
  }

delay(100);
}

void ledAus(){
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
}

void anzeigen(int ergebnis){
  if (ergebnis = 1){
    digitalWrite(red1, HIGH);
  }
  if (ergebnis = 2){
    digitalWrite(red4, HIGH);
    digitalWrite(red7, HIGH);
  }
  if (ergebnis = 3){
    digitalWrite(red1, HIGH);
    digitalWrite(red4, HIGH);
    digitalWrite(red7, HIGH);
  }
  if (ergebnis = 4){
    digitalWrite(red2, HIGH);
    digitalWrite(red4, HIGH);
    digitalWrite(red5, HIGH);
    digitalWrite(red7, HIGH);
  }
  if (ergebnis = 5){
    digitalWrite(red1, HIGH);
    digitalWrite(red2, HIGH);
    digitalWrite(red4, HIGH);
    digitalWrite(red5, HIGH);
    digitalWrite(red6, HIGH);
  }
  if (ergebnis = 6){
    digitalWrite(red2, HIGH);
    digitalWrite(red3, HIGH);
    digitalWrite(red4, HIGH);
    digitalWrite(red5, HIGH);
    digitalWrite(red6, HIGH);
    digitalWrite(red7, HIGH);
  } else {
    Serial.println("wtf!?");
  }
}

