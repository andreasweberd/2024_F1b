#include <LiquidCrystal.h>

// Pinbelegung für das LCD
#define PIN_LCD_RS 6              // Pin für LCD-Pin RS (Register Select)
#define PIN_LCD_E 7               // Pin für LCD-Pin E  (Enable)
#define PIN_LCD_D4 8              // Pin für LCD-Pin D4 (Datenbit 4)
#define PIN_LCD_D5 9              // Pin für LCD-Pin D5 (Datenbit 5)
#define PIN_LCD_D6 10             // Pin für LCD-Pin D6 (Datenbit 6)
#define PIN_LCD_D7 11             // Pin für LCD-Pin D7 (Datenbit 7)

// Ultraschall Sensor Pins
#define TRIG_PIN 3                // Pin für Trigger des Ultraschallsensors
#define ECHO_PIN 4                // Pin für Echo des Ultraschallsensors

#define LCD_ROWS 2                // Anzahl der Zeilen des Displays
#define LCD_COLS 16               // Anzahl der Spalten des Displays

LiquidCrystal lcd(PIN_LCD_RS, PIN_LCD_E, PIN_LCD_D4, PIN_LCD_D5, PIN_LCD_D6, PIN_LCD_D7);

void setup() {
  lcd.begin(LCD_COLS, LCD_ROWS);  // Die Größe des Displays festlegen und das Display initialisieren.
  pinMode(TRIG_PIN, OUTPUT);       // Setze TRIG_PIN als Ausgang
  pinMode(ECHO_PIN, INPUT);        // Setze ECHO_PIN als Eingang
  lcd.print("Parksensor Ready");   // Begrüßungstext auf dem LCD
  delay(2000);
  lcd.clear();                     // LCD reinigen
}

void loop() {
  long duration, distance;

  // Trigger für 10 Mikrosekunden aktivieren
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Dauer des Echos lesen
  duration = pulseIn(ECHO_PIN, HIGH);

  // Berechne die Entfernung in cm
  distance = duration * 0.034 / 2; // Zeit in cm umrechnen

  // Zeige die Entfernung auf dem LCD an
  lcd.setCursor(0, 0); // Cursor auf die erste Zeile setzen
  lcd.print("Distanz: ");
  lcd.print(distance);
  lcd.print(" cm   "); // Leerzeichen zur Bereinigung

  // Überprüfen, ob das Objekt näher als 30 cm ist
  if (distance < 30) {
    lcd.setCursor(0, 1); // Cursor auf die zweite Zeile setzen
    lcd.print("Objekt NAHE! "); // Warnung anzeigen
  } else {
    lcd.setCursor(0, 1); // Cursor auf die zweite Zeile setzen
    lcd.print("              "); // Leerzeile, um vorherige Warnung zu löschen
  }

  delay(500); // Warte 0,5 Sekunden bevor die nächste Messung erfolgt
}
