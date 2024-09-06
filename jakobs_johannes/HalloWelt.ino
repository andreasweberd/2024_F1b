void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("setup");
}

int meineVariable1 = 0;

void loop() {
  // put your main code here, to run repeatedly:

  int meineVariable1 = addOne(meineVariable1);

  Serial.println(meineVariable1);
  delay(1000);
}


int addOne(int meinParameter1){
  return meinParameter1+1;
}