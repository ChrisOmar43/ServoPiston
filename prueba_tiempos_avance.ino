//Este codigo servira para encontrar la potencia y velocidad necesarios para lograr que el servo se mueva 1 cm
int velocidad = 70; 		//Potencia de motor
void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
  analogWrite(3, velocidad);	//Iniciando el pin con la respectiva potencia
}

void loop() {

  if (Serial.available()) {  	// verifica si hay datos disponibles en el monitor serieo

    char command = Serial.read();  // lee el comando enviado desde el monitor serie
    if (command == 'o') {  	
      digitalWrite(6, HIGH);	//
      digitalWrite(4, HIGH);	//
      delay(650);		// Si recibe una 'o' por el monitor serial
      digitalWrite(6,LOW);	// hara un movimiento hacia la izq, el valor de entrada 
      digitalWrite(4, LOW);	// cambiara a otro caracter para que no quede en bucle, 
      delay(200);		// despues enviara una 'H' al monitor serial
      command = "f";		// para confirmar que el proceso ha terminado
      Serial.println("H");	//
    }
  }
}
