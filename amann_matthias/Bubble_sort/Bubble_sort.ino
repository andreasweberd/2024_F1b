const int ARRAY_SIZE = 1000;
int numbers[ARRAY_SIZE];
int buzzer = 13;

void bubbleSort(int arr[], int size) {

    digitalWrite(buzzer,HIGH);
    delay(10);
    digitalWrite(buzzer,LOW);

  
    unsigned long startTime = millis();
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
        digitalWrite(buzzer,HIGH);
    delay(500);
    digitalWrite(buzzer,LOW);

    unsigned long endTime = millis();
    Serial.print("Sortierzeit: ");
    Serial.print(endTime - startTime);
    Serial.println(" ms");
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        Serial.print(arr[i]);
        Serial.print(" ");
    }
    Serial.println();
}

void setup() {
  
    pinMode(buzzer,OUTPUT);

    Serial.begin(9600);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        numbers[i] = i + 1;
    }
    for (int i = 0; i < ARRAY_SIZE; i++) {
        int j = random(0, ARRAY_SIZE);
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }
    
    Serial.println("Unsortiertes Array:");
    printArray(numbers, ARRAY_SIZE);
    
    bubbleSort(numbers, ARRAY_SIZE);
    
    Serial.println("Sortiertes Array:");
    printArray(numbers, ARRAY_SIZE);

    
}


void loop() {
}
