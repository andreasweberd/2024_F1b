int noise = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(4, OUTPUT);
  pinMode(A1, INPUT); 
}

void loop() {

  noise = analogRead(A1);

  Serial.println(noise);
  delay(80);

  if (noise > 60){
    digitalWrite(4, HIGH);
  }
  if (noise > 90){
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
  }
  if (noise > 120){
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
  }
  if (noise > 160){
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
  }
  
  else{
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }

}