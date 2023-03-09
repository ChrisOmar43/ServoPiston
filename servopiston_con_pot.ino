//Declaracion de variables
int cm2 = 0;
int pos2 = 0;  
int pos = 0;
int potValue = 0;

//Funcion para desplazarse 1cm
void movimiento(int p1, int p2, int d, int v){
      analogWrite(3, v);
      digitalWrite(p1,HIGH);
      digitalWrite(p2, HIGH);
      delay(d);
      digitalWrite(p1, LOW);
      digitalWrite(p2, LOW);
}
//Funcion para ejecutar el movimiento dependiendo de la posición deseada
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
  movimiento(2,5,2540, 50); //Inicio con posición 0
}

void loop() {
  potValue = analogRead(A0); //Lectura del valor del pot
  //Asignacion de posiciónes dependiendo del valor del pot
  if (potValue <= 204)
    pos = 0;
  else if (potValue <= 408)
    pos = 1;
  else if (potValue <= 612)
    pos = 2;
  else if (potValue <= 816)
    pos = 3;
  else if (potValue <= 1023)
    pos = 4;
  //Calculo de la diferencia entre distancias para el movimiento en cm
  if (pos != pos2){
    cm2 = pos - pos2;
    pos2 = pos;
    ciclo(cm2);
  }
}
