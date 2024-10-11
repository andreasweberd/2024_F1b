// Pin-Definitionen
const int soundSensorPin = A0;   // Sound-Sensor am analogen Pin A0 angeschlossen
const int lampPin = 4;           // Lampe oder LED am digitalen Pin 4 angeschlossen
int soundValue = 0;              // Variable zum Speichern des gelesenen analogen Werts

void setup() {
  pinMode(lampPin, OUTPUT);      // Lampen-Pin auf Output setzen
  digitalWrite(lampPin, LOW);    // Lampe/LED zunächst ausschalten
  
  Serial.begin(9600);            // Serielle Kommunikation starten
}

void loop() {
  // Sound-Wert vom analogen Pin lesen
  soundValue = analogRead(soundSensorPin);

  // Sound-Wert im seriellen Monitor ausgeben
  Serial.print("Sound Sensor Value: ");
  Serial.println(soundValue);

  // Wenn der Sound-Wert > 320 ist, Lampe einschalten
  if (soundValue > 320) {
    digitalWrite(lampPin, HIGH);  // Lampe/LED an
    Serial.println("Lampe AN");
  } else {
    digitalWrite(lampPin, LOW);   // Lampe/LED aus
    Serial.println("Lampe AUS");
  }

  // Kurze Verzögerung (optional)
  delay(100);
}
