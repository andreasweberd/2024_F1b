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


}