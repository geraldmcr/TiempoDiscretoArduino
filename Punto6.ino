//inicializa el pin del boton
int button2 = 2;
// inicializa el pin de los LED
int pin3 = 3;
// inicializa la variable donde guarda el valor del boton
int valor = 0;

void setup() {
  pinMode(button2, INPUT);// boton
  pinMode(pin3, OUTPUT); // luz verde
}

// the loop function runs over and over again forever
void loop() {
  valor = digitalRead(button2); // guarda el valor del boton
  if (valor == HIGH){ // si esta oprimido
    digitalWrite(pin3, HIGH);   // Enciende el LED
  }
  else{ // sino
    digitalWrite(pin3, LOW); // Apaga el LED  
  }
}
