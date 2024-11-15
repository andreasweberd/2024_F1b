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

// Melodie von "Freude schöner Götterfunken"
int melody[] = {
NOTE_E5, NOTE_E5, NOTE_F5, NOTE_G5,
NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5,
NOTE_C5, NOTE_C5, NOTE_D5, NOTE_E5,
NOTE_E5, NOTE_D5, NOTE_D5,

NOTE_E5, NOTE_E5, NOTE_F5, NOTE_G5,
NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5,
NOTE_C5, NOTE_C5, NOTE_D5, NOTE_E5,
NOTE_D5, NOTE_C5, NOTE_C5
};

// Notenlängen (4 = Viertelnote, 8 = Achtelnote, ...)
int noteDurations[] = {
8, 8, 8, 8,
8, 8, 8, 8,
8, 8, 8, 8,
8, 8, 4,

8, 8, 8, 8,
8, 8, 8, 8,
8, 8, 8, 8,
8, 8, 4
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
for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
int noteDuration = 1000 / noteDurations[i]; // Dauer der Note berechnen
tone(buzzerPin, melody[i], noteDuration); // Ton für die Note erzeugen
delay(noteDuration * 1.3); // Pause zwischen den Noten
noTone(buzzerPin); // Ton stoppen
}
}
