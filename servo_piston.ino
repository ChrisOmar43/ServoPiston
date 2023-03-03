int cm2 = 0;
int pos2 = 0;  
void movimiento(int p1, int p2, int d, int v){
      analogWrite(3, v);
      digitalWrite(p1,HIGH);
      digitalWrite(p2, HIGH);
      delay(d);
      digitalWrite(p1, LOW);
      digitalWrite(p2, LOW);
}
void ciclo(int cm){
  for (int i = cm; i <= -1; i++) {
    movimiento(2, 5, 500, 30);
  }
  for (int i = cm; i >= 1; i--) {
    movimiento(6, 4, 620, 50);
  }
}

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}

void loop() {
   if (Serial.available()) {
    int pos = Serial.parseInt();
    if (pos == 404){
        movimiento(2,5,2540, 50);
        pos = 0;
        pos2 = 0;
        cm2 = 0;
    }
     if (pos == 1||pos == 2||pos == 3||pos == 4){
      cm2 = pos - pos2;
      pos2 = pos;
      Serial.println(cm2);
      ciclo(cm2);
    }
   }
}
