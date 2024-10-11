const int sensor_d = 8;
const int sensor_a = A1;
const int led4 = 4;
const int led5 = 5;
const int led6 = 6;

int lautstaerke_d = 0;
int lautstaerke_a = 0;

void setup() {
  Serial.begin(9600);
  pinMode(sensor_d, INPUT);
  pinMode(sensor_a, INPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
}

void loop() {
  delay(100);

  lautstaerke_d = digitalRead(sensor_d);
  lautstaerke_a = analogRead(sensor_a);
  Serial.println(lautstaerke_a);

  if (lautstaerke_a > 80) {
    digitalWrite(led4, HIGH);
  }
  else {
    digitalWrite(led4, LOW);
  }

  if (lautstaerke_a > 100) {
    digitalWrite(led5, HIGH);
  }
  else {
    digitalWrite(led5, LOW);
  }
  
  if (lautstaerke_a > 120) {
    digitalWrite(led6, HIGH);
  }
  else {
    digitalWrite(led6, LOW);
  }
delay(1000);
}
