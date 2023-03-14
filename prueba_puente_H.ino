int velocidad = 255;
void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6, OUTPUT);
  analogWrite(3, velocidad);
}

void loop() {
  digitalWrite(2, HIGH);	//
  digitalWrite(5, HIGH);	//
  delay(250);			//Movimiento de piston der
  digitalWrite(2,LOW);		//
  digitalWrite(5, LOW);		//
  delay(200);			
  digitalWrite(4,HIGH);		//
  digitalWrite(6, HIGH);	//
  delay(250);			//Movimiento de piston izq
  digitalWrite(4, LOW);		//
  digitalWrite(6, LOW);		//
  delay(200);
}
