int cm = 0;
int p1, p2, d, v;
String pos = "inicio"; 
void movimiento(p1, p2, d, v);
void recursividad(cm);

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
 // movimiento(4,6,2540, 50);
  pos = pos + " ok";
  cm = 0;
}

void loop() {
   if (Serial.available()) {
    String pos = Serial.readString();
    if (pos == "inicio"||pos == "calibrar"||pos == "0"){
        movimiento(4,6,2540, 50);
        pos = pos + " ok";
        cm = 0;
    }
    else if (pos == "1"||pos == "2"||pos == "3"||pos == "4"){
      cm = int(pos) - cm;
      recursividad(cm);
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
void recursividad(cm){
  if(cm == -1){
    movimiento(4,6,635, 50);
    cm = cm+1;
    recursividad(cm);
  }
  else if (cm == -2){
    movimiento(4,6,635, 50);
    cm = cm+1;
    recursividad(cm);
  }
  else if (cm == -3){
    movimiento(4,6,635, 50);
    cm = cm+1;
    recursividad(cm);
  }
  else if (cm == -4){
    movimiento(4,6,635, 50);
    cm = cm+1;
    recursividad(cm);
  }

  if(cm == 1){
    movimiento(4,6,650, 70);
    cm = cm-1;
    recursividad(cm);
  }
  else if (cm == 2){
    movimiento(4,6,650, 70);
    cm = cm-1;
    recursividad(cm);
  }
  else if (cm == 3){
    movimiento(4,6,650, 70);
    cm = cm-1;
    recursividad(cm);
  }
  else if (cm == 4){
    movimiento(4,6,650, 70);
    cm = cm-1;
    recursividad(cm));
  }
}
