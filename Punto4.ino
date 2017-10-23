int pin3 = 3; //inicializa el LED externo conectado al pin 3
// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(pin3, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(pin3, HIGH);   // Enciende el LED
  delay(5000);                // lo enciende por 5 segundos
  digitalWrite(pin3, LOW);    // Apaga el LED
  delay(1000);                // wait for a second
}
