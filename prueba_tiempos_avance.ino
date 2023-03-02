int velocidad = 70;
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

  if (Serial.available()) {  // verifica si hay datos disponibles en el monitor serieo

    char command = Serial.read();  // lee el comando enviado desde el monitor serie
    if (command == 'o') {  // si el comando es 'on'
      digitalWrite(6, HIGH);
      digitalWrite(4, HIGH);
      delay(650);
      digitalWrite(6,LOW);
      digitalWrite(4, LOW);
      delay(200);
      command = "f";
      Serial.println("H");
    }
  }
}
