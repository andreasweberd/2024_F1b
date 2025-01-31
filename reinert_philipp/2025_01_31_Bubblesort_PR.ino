#define ARRAY_SIZE 24

int arr[ARRAY_SIZE];

void setup() {
    Serial.begin(9600);
    while (!Serial) {
        ; // Warte, bis die serielle Verbindung hergestellt ist (nur nötig für native USB-Boards)
    }
    
    // A0 als Zufallsquelle nutzen (offen lassen für beste Ergebnisse)
    randomSeed(analogRead(A0));
    
    // Array mit Zufallswerten füllen
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = random(0, 100); // Zahlen zwischen 0 und 9999
    }
    
    Serial.println("Unsortiertes Array erstellt. Startet Bubble Sort...");
    
    unsigned long startTime = millis(); // Startzeit erfassen
    bubbleSort(arr, ARRAY_SIZE);
    unsigned long endTime = millis(); // Endzeit erfassen
    
    Serial.print("Sortieren abgeschlossen in: ");
    Serial.print(endTime - startTime);
    Serial.println(" ms");

    // Optional: Sortiertes Array anzeigen
    Serial.println("Sortiertes Array:");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        Serial.println(arr[i]);
    }
}

void loop() {
    // Leerlauf
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break; // Falls keine Vertauschung mehr nötig ist, abbrechen
    }
}