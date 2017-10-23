// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // Enciende el LED
  delay(5000);                       // lo enciende por 5 segundos
  digitalWrite(LED_BUILTIN, LOW);    // Apaga el LED
  delay(1000);                       // wait for a second
}
