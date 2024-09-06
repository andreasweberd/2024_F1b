// Pin, an dem die LED angeschlossen ist
int ledPin = 9; 

void setup() {
  // Initialisierung des LED-Pins als Ausgang
  pinMode(ledPin, OUTPUT);
  
  // 5 Mal blinken lassen
  blinkLED(5, 1000);  // 5 Blinks, mit einer Pause von 1000ms zwischen Ein/Aus
}

void loop() {
  // Hier bleibt es leer, da wir die LED nur einmal blinken lassen wollen
}

// Funktion, um die LED x Mal blinken zu lassen
void blinkLED(int numberOfBlinks, int delayTime) {
  for (int i = 0; i < numberOfBlinks; i++) {
    digitalWrite(ledPin, HIGH);  // LED einschalten
    delay(delayTime);            // Warten
    digitalWrite(ledPin, LOW);   // LED ausschalten
    delay(delayTime);            // Warten
  }
}

