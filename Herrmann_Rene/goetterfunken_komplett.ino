const int buttonPin = 3; // Pin für den Button
const int buzzerPin = 4; // Pin für den Buzzer

// Frequenzen der Noten in Hertz
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_D5 587
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_G5 784
#define NOTE_A5 880
#define NOTE_B5 987
#define NOTE_C6 1047
#define NOTE_D6 1175

// Melodie und Notenlängen kombiniert in einem 2D-Array
int melody[][2] = {
  // Erste Strophe
  {NOTE_E5, 4}, {NOTE_E5, 4}, {NOTE_F5, 4}, {NOTE_G5, 4},
  {NOTE_G5, 4}, {NOTE_F5, 4}, {NOTE_E5, 4}, {NOTE_D5, 4},
  {NOTE_C5, 4}, {NOTE_C5, 4}, {NOTE_D5, 4}, {NOTE_E5, 4},
  {NOTE_E5, 4}, {NOTE_D5, 2},

  // Zweite Strophe
  {NOTE_E5, 4}, {NOTE_E5, 4}, {NOTE_F5, 4}, {NOTE_G5, 4},
  {NOTE_G5, 4}, {NOTE_F5, 4}, {NOTE_E5, 4}, {NOTE_D5, 4},
  {NOTE_C5, 4}, {NOTE_C5, 4}, {NOTE_D5, 4}, {NOTE_E5, 4},
  {NOTE_D5, 4}, {NOTE_C5, 2},

  // Dritte Strophe (Variante mit etwas veränderter Melodie)
  {NOTE_E5, 4}, {NOTE_E5, 4}, {NOTE_F5, 4}, {NOTE_G5, 4},
  {NOTE_G5, 4}, {NOTE_F5, 4}, {NOTE_E5, 4}, {NOTE_D5, 4},
  {NOTE_C5, 4}, {NOTE_C5, 4}, {NOTE_D5, 4}, {NOTE_E5, 4},
  {NOTE_E5, 4}, {NOTE_D5, 2},

  // Vierte Strophe (Fortsetzung des Motivs)
  {NOTE_E5, 4}, {NOTE_E5, 4}, {NOTE_F5, 4}, {NOTE_G5, 4},
  {NOTE_G5, 4}, {NOTE_F5, 4}, {NOTE_E5, 4}, {NOTE_D5, 4},
  {NOTE_C5, 4}, {NOTE_C5, 4}, {NOTE_D5, 4}, {NOTE_E5, 4},
  {NOTE_D5, 4}, {NOTE_C5, 2},

  // Weitere Strophen würden hier folgen
};

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Button mit Pull-Up-Widerstand
  pinMode(buzzerPin, OUTPUT); // Buzzer als OUTPUT
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  // Wenn der Button gedrückt wird (LOW wegen INPUT_PULLUP)
  if (buttonState == LOW) {
    playMelody(); // Melodie abspielen
  } else {
    noTone(buzzerPin); // Buzzer ausschalten
  }
}

// Funktion zum Abspielen der Melodie
void playMelody() {
  int melodyLength = sizeof(melody) / sizeof(melody[0]); // Anzahl der Noten in der Melodie

  for (int i = 0; i < melodyLength; i++) {
    int note = melody[i][0]; // Die Frequenz der Note
    int duration = 1000 / melody[i][1]; // Dauer der Note berechnen

    tone(buzzerPin, note, duration); // Ton für die Note erzeugen
    delay(duration * 1.3); // Pause zwischen den Noten
    noTone(buzzerPin); // Ton stoppen
  }
}
