const int ledPin = 4;
const int ledPin2 = 5;
const int ledPin3 = 2;
const int ledPin4 = 3;
const int soundSensorPin = 8;
const int soundSensorAnalogPin = A1;
int soundThreshold = 200;

void setup() {
  pinMode(soundSensorAnalogPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(soundSensorPin, INPUT);
  Serial.begin (9600);
}

void loop() {
  int soundDetected = digitalRead(soundSensorPin);
  int soundDetectedAnalog = analogRead(soundSensorAnalogPin);
  Serial.println (soundDetectedAnalog);

  if (soundDetectedAnalog > 80) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  if (soundDetectedAnalog > 100) {
    digitalWrite(ledPin2, HIGH);
  } else {
    digitalWrite(ledPin2, LOW);
  }

  if (soundDetectedAnalog > 120) {
    digitalWrite(ledPin3, HIGH);
  } else {
    digitalWrite(ledPin3, LOW);
  }
  
  if (soundDetectedAnalog > 140) {
    digitalWrite(ledPin4, HIGH);
  } else {
    digitalWrite(ledPin4, LOW);
  }

  delay (80);
}
