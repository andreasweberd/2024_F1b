#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Display-Konfiguration
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Arraygröße
#define ARRAY_SIZE 100

// Das Array mit 100 zufälligen Ganzzahlen
int arr[ARRAY_SIZE];

unsigned long lastTime = 0; // Letzte Zeit für die Sortierung

// Pin für den Buzzer
#define BUZZER_PIN 9

void setup() {
  // Starte die serielle Kommunikation
  Serial.begin(9600);
  randomSeed(analogRead(0)); // Zufallsgenerator initialisieren

  // Initialisiere den Buzzer Pin
  pinMode(BUZZER_PIN, OUTPUT);

  // Initialisiere das Display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Fehler beim Initialisieren des Displays"));
    while (1); // Stopp, wenn das Display nicht gefunden wird
  }

  // Initialisiere das Array mit Zufallszahlen
  for (int i = 0; i < ARRAY_SIZE; i++) {
    arr[i] = random(0, 9999); // Zufallszahlen im Bereich 0-9999
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print(F("Starte"));
  display.setCursor(0, 20);
  display.print("Sortieren!");
  display.display();
}

void loop() {
  // Wenn 5 Sekunden vergangen sind, starte das Sortieren
  if (millis() - lastTime >= 5000) {
    // Messen der Zeit, die der Sortierprozess dauert
    unsigned long startTime = millis(); // Startzeitpunkt


    // Buzzer piept einmal beim Start der Sortierung (leise)
    tone(BUZZER_PIN, 500, 100); // Frequenz 500Hz, Dauer 100ms (leise)

    // BubbleSort Algorithmus
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
      for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
          // Tausche die Elemente
          int temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
        }
      }
    }

    unsigned long endTime = millis(); // Endzeitpunkt
    unsigned long duration = endTime - startTime; // Berechne die Dauer

    // Gib die Dauer der Sortierung im seriellen Monitor aus
    Serial.print("Dauer des BubbleSort: ");
    Serial.print(duration);
    Serial.println(" Millisekunden");

    // Zeige die Dauer auf dem Display an
    display.setTextSize(2);
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print(F("Dauer:"));
    display.setCursor(0, 20);
    display.print(duration);
    display.print(F(" ms"));
    display.display();

    // Buzzer piept zweimal am Ende der Sortierung (leise)
    tone(BUZZER_PIN, 500, 100); // Erstes leises Piepen
    delay(200); // kurze Pause
    tone(BUZZER_PIN, 500, 100); // Zweites leises Piepen

    // Setze die Zeit für die nächste Sortierung
    lastTime = millis();

    // 3 Sekunden Pause zwischen den Sortierungen
    delay(3000); // 3000ms = 3 Sekunden
  }
}
