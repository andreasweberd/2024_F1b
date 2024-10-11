const int ledPin = 4;
const int soundSensorPin = 8;
const int soundSensorAnalogPin = A1;
int soundThreshold = 200;

void setup() {
  pinMode(soundSensorAnalogPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(soundSensorPin, INPUT);
  Serial.begin (9600);
}

void loop() {
  int soundDetected = digitalRead(soundSensorPin);
  int soundDetectedAnalog = analogRead(soundSensorAnalogPin);
  Serial.println (soundDetectedAnalog);

  if (soundDetected == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  if (soundDetectedAnalog > 130) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay (80);
}
