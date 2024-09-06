void setup() {
  Serial.begin(9600);
  Serial.println("Setup");
}

void loop() {

  int meineVariable1 = addOne(1);
  Serial.println(meineVariable1);
  delay(1000);
}

int addOne(int meinParameter1){
  Serial.println(meinParameter1);
  return meinParameter1+1;
}