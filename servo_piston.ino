int cm = 0;
int p1, p2, d, v;
String pos = "inicio";
Stirng pos2 = "";  
void movimiento(p1, p2, d, v);
void recursividad(cm);

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
    String pos = Serial.readString();
    if (pos == "inicio"||pos == "calibrar"||pos == "0"){
        movimiento(4,6,2540, 50);
        pos = "0";
        pos2 = "0";
        cm = 0;
    }
    else if (pos == "1"||pos == "2"||pos == "3"||pos == "4"){
      cm = int(pos) - int(pos2);
      pos2 = pos;
      ciclo(cm);
    }
   }
}

void movimiento(p1, p2, d, v){
      analogWrite(3, v);
      digitalWrite(p1,HIGH);
      digitalWrite(p2, HIGH);
      delay(d);
      digitalWrite(p1, LOW);
      digitalWrite(p2, LOW);
}
void ciclo(cm){
  for (int i = cm; i >=  -1; i++) {
    movimiento(4, 6, 635, 50);
  }
  for (int i = cm; i <=  1; i--) {
    movimiento(2, 5, 650, 70);
  }
}
