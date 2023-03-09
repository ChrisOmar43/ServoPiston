int cm2 = 0;
int pos2 = 0;
int pos = 0;
String voz = "";
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
  movimiento(2,5,2540, 50);
}

void loop() {
  if (Serial.available()) {
    voz = Serial.readString();
    if(voz == "cero")
      pos = 0;
    else if(voz == "uno")
      pos = 1;
    else if(voz == "dos")
      pos = 2;
    else if(voz == "tres")
      pos = 3;
    else if(voz == "cuatro")
      pos = 4;
    else
    Serial.print("Por favor intoduzca un valor entre 0 y 4");
    if (pos == 0||pos == 1||pos == 2||pos == 3||pos == 4){
      cm2 = pos - pos2;
      pos2 = pos;
      Serial.println(cm2);
      ciclo(cm2);
    }
  }
}
