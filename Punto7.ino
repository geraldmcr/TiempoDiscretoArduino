/*
  Blink
*/

  int pin3 = 3;
  int pin5 = 5;
  int pin6 = 6;
  int valor = 0;
  int button2 = 2;
  
// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  pinMode(button2, INPUT);// boton
  pinMode(pin3, OUTPUT); // luz verde
  pinMode(pin5, OUTPUT); // luz amarilla
  pinMode(pin6, OUTPUT); // luz roja
  
}

// the loop function runs over and over again forever
void loop() {
   valor = digitalRead(button2);
  if (valor == HIGH){
  // ENCIENDE EL LED DEL PIN 3
  digitalWrite(pin3, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(pin3, LOW);  
  
  // ENCIENDE EL LED DEL PIN 5
  digitalWrite(pin5, HIGH);
  delay(1000);                       // wait for a second
  digitalWrite(pin5, LOW);  
  
  // ENCIENDE EL LED DEL PIN 6
  digitalWrite(pin6, HIGH);
  delay(1000);                       // wait for a second
  digitalWrite(pin6, LOW);  
    }
  else{
    Serial.println("Apagado");    
    }
}
