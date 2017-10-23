
  int valor = 0;
  int button2 = 2;
  int pin3 = 3;
  
void setup() {
  Serial.begin(9600);
  pinMode(button2, INPUT);// boton
  pinMode(pin3, OUTPUT); // luz verde
}

// the loop function runs over and over again forever
void loop() {
  valor = digitalRead(button2);
  if (valor == HIGH){
    digitalWrite(pin3, HIGH);   // turn the LED on (HIGH is the voltage level)
    Serial.println("Encendido");
  }
  else{
    digitalWrite(pin3, LOW); //turn the LED on LOW.
    Serial.println("Apagado");    
    }

 // delay(1000);
}
