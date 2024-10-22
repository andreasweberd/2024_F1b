int LED_element = 9;

void setup() {
  // put your setup code here, to run once:
pinMode(LED_element, OUTPUT);
blinkLED(5, 1000);

}

void loop() {

}

void blinkLED(int Blink, int delaytime){

for (int i=0; i < Blink; i++) {

digitalWrite(LED_element, HIGH);
delay(delaytime);

digitalWrite(LED_element, LOW);
delay(delaytime);
}
}