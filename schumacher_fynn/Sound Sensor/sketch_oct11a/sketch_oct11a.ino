void setup () 
{
  // put your 
  pinMode(A1,INPUT);

Serial.begin(9600);

}


void loop()
{
 Serial.println(analogRead(A1));//aktuellen Wert von Pin A1 ausgeben 
 delay(80);//80ms warten
}
