#define analogpin 24
void setup() {
  // put your setup code here, to run once:
  pinMode(analogpin,OUTPUT);
 

}

void loop() {
  // put your main code here, to run repeatedly:
  int current;
  current=analogRead(analogpin);
  Serial.print(current);
  Serial.println();
   
  
}
