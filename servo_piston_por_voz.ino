						//Se recicara el codigo del servopiston manual con algunas excepciones
//Declaracion de variables
int cm2 = 0;
int pos2 = 0;
int pos = 0;
String voz = "";
//Funcion para desplazarse 1cm
void movimiento(int p1, int p2, int d, int v){
      analogWrite(3, v);
      digitalWrite(p1,HIGH);
      digitalWrite(p2, HIGH);
      delay(d);
      digitalWrite(p1, LOW);
      digitalWrite(p2, LOW);
}
//Funcion de movimiento entre 1 y 4 cm
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
  movimiento(2,5,2540, 50); //Movimiento a el origen
}

void loop() {
  if (Serial.available()) {
    voz = Serial.readString();		// El valor sera guardado como una variable de tipo 'String'
    if(voz == "cero")			
      pos = 0;				//
    else if(voz == "uno")		//
      pos = 1;				// Se transforma el valor de tipo 'String' en uno de tipo
    else if(voz == "dos")		// 'int' para que sea compatible con el codigo anterior
      pos = 2;				//
    else if(voz == "tres")		//
      pos = 3;				//
    else if(voz == "cuatro")		//
      pos = 4;				//
    else
      Serial.print("Por favor intoduzca un valor entre 0 y 4");	//Mensaje de precaucion con instrucciones
    //Evaluacion de distancia a recorrer y ejecucion del movimiento
    if (pos == 0||pos == 1||pos == 2||pos == 3||pos == 4){
      cm2 = pos - pos2;
      pos2 = pos;
      Serial.println(cm2);
      ciclo(cm2);
    }
  }
}
