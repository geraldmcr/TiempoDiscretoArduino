// inicializa los pines de los LEDs
int pin3 = 3;
int pin5 = 5;
int pin6 = 6;
  
// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(pin3, OUTPUT); // luz verde
  pinMode(pin5, OUTPUT); // luz amarilla
  pinMode(pin6, OUTPUT); // luz roja
}

// the loop function runs over and over again forever
void loop() {
  // ENCIENDE EL LED DEL PIN 3
  digitalWrite(pin3, HIGH);   
  delay(1000);                      
  digitalWrite(pin3, LOW);  
  
  // ENCIENDE EL LED DEL PIN 5
  digitalWrite(pin5, HIGH);
  delay(1000);                       
  digitalWrite(pin5, LOW);  
  
  // ENCIENDE EL LED DEL PIN 6
  digitalWrite(pin6, HIGH);
  delay(1000);                     
  digitalWrite(pin6, LOW);  
}
