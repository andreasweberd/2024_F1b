int ledPin = 9; 

void setup() {
  pinMode(ledPin, OUTPUT); 
  blink(5); 
}

void loop() {
  
}


void blink(int times) {
  for (int x = 0; x < times; x++) 
    digitalWrite(ledPin, HIGH);  
    delay(500);                  
    digitalWrite(ledPin, LOW);   
    delay(5000);               
}
