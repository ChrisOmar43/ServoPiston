int cm2 = 0;	//Variable que guardara el numero de veces que se requiere ejecutar el ciclo de la funcion 'ciclo'
int pos = 0;	//Variable en la que se almacenara la distancia en la que se desea mover el servo piston
int pos2 = 0;  	//Variable donde se guardara la posicion real de el Servo piston
void movimiento(int p1, int p2, int d, int v){	
      analogWrite(3, v);			//
      digitalWrite(p1,HIGH);			//
      digitalWrite(p2, HIGH);			// Funcion que se encargara de hacer el
      delay(d);					// movimiento de 1 cm
      digitalWrite(p1, LOW);			//
      digitalWrite(p2, LOW);			//
}
void ciclo(int cm){
  for (int i = cm; i <= -1; i++) {		//
    movimiento(2, 5, 500, 30);			// Funcion que ejecutara un ciclo con la funcion
  }						// movimiento para hacer movimientos de mas de
  for (int i = cm; i >= 1; i--) {		// un cm, este identificara cuando el movimiento
    movimiento(6, 4, 620, 50);			// necesario es hacia la derecha o izquierda
  }
}

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
  movimiento(2,5,2540, 50);	// Se ejecuta la funcion movimiento una vez con el valor maximo de cm para moverlo a su origen
}

void loop() {
   if (Serial.available()) {	// Se ejecutara el codigo, solo cuando este recibiendo algo por el monitor serial
   pos = Serial.parseInt();       
     if (pos >= 0|| pos <= 4){	// Si el valor recibido esta entre las distancias posibles del servo, se ejecuta lo siguiente 
      cm2 = pos - pos2;		// La variable gusrdara la distancia que hay entre la posicion actual y la deseada
      pos2 = pos;		// Se actualiza la nueva posicion del servo piston
      Serial.println(cm2);	// Se confirma por el monitor serial cual es la distancia seleccionada
      ciclo(cm2);		// Se llama a la funcion ciclo con el argumento de la distancia a desplazarse
    }
    else
      Serial.println("Escriba un valor entre 0 y 4"); // Mensaje de instrucciones
  }
}
