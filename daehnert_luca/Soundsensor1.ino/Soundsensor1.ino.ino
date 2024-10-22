// Pin-Definitionen
const int Pin = A0;   
const int lampPin = 4;           
int soundValue = 0;              

void setup() {
  pinMode(lampPin, OUTPUT);      
  digitalWrite(lampPin, LOW);    
  
  Serial.begin(9600);            
}

void loop() {
  // Sound-Wert vom analogen Pin lesen
  soundValue = analogRead(Pin);

  // Sound-Wert im seriellen Monitor ausgeben
  Serial.print("Sound Sensor Value: ");
  Serial.println(soundValue);

  // Wenn der Sound-Wert > 360 ist, Lampe einschalten
  if (soundValue > 320) {
    digitalWrite(lampPin, HIGH);  // Lampe/LED an
    Serial.println("Lampe AN");
  } else {
    digitalWrite(lampPin, LOW);   // Lampe/LED aus
    Serial.println("Lampe AUS");
  }

  
  delay(100);
}
