void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 Serial.println("setup");
}

void loop() {

  // put your main code here, to run repeatedly:

 int meineVariable1 = hallo(1);

 Serial.println(meineVariable1);
 delay(1000);
}

int hallo (int meinParameter1){

  Serial.println(meinParameter1);

  return meinParameter1+1;
}