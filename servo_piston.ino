velocidad = 100;
int cm = 0;
String pos = "inicio"; 
void movimiento(p1, p2, d);

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
  analogWrite(3, velocidad);
}

void loop() {
  if (pos == "inicio"){
      movimiento(4,6,500);
      pos = pos + " ok";
      cm = 0;
  }
  if (pos == "mas 1"){
    movimiento(2,5, )
  }
}

void movimiento(p1, p2, d){
      digitalWrite(p1,HIGH);
      digitalWrite(p2, HIGH);
      delay(d);
      digitalWrite(p1, LOW);
      digitalWrite(p2, LOW);
}
