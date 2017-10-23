/*
 
*/

  int button2 = 2;
  int pin3 = 3;
  int pin5 = 5;
  int pin6 = 6; 
  
  
// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  pinMode(button2, INPUT); // botón
  pinMode(pin3, OUTPUT); // luz verde
  pinMode(pin5, OUTPUT); // luz amarilla
  pinMode(pin6, OUTPUT); // luz roja 
}

int salidaLuces(int pin01, int pin02, int pin03, int a, int b, int c){
  if ((a==0)&&(b==0)&&(c==0)) { // CASO 1: NEGRO
    digitalWrite(pin01,LOW);
    digitalWrite(pin02,LOW);
    digitalWrite(pin03,LOW);
  }
    if ((a==0)&&(b==0)&&(c==1)) { // CASO 2: AZUL
    digitalWrite(pin01,HIGH);
    digitalWrite(pin02,LOW);
    digitalWrite(pin03,LOW);
  }
    if ((a==0)&&(b==1)&&(c==0)) { // CASO 3: VERDE
    digitalWrite(pin01,LOW);
    digitalWrite(pin02,HIGH);
    digitalWrite(pin03,LOW);
  }
    if ((a==0)&&(b==1)&&(c==1)) { // CASO 4: VERDE + AZUL
    digitalWrite(pin01,HIGH);
    digitalWrite(pin02,HIGH);
    digitalWrite(pin03,LOW);
  }
    if ((a==1)&&(b==0)&&(c==0)) { // CASO 5: ROJO
    digitalWrite(pin01,LOW);
    digitalWrite(pin02,LOW);
    digitalWrite(pin03,HIGH);
  }
    if ((a==1)&&(b==0)&&(c==1)) { // CASO 6: ROJO + AZUL
    digitalWrite(pin01,HIGH);
    digitalWrite(pin02,LOW);
    digitalWrite(pin03,HIGH);
  }
    if ((a==1)&&(b==1)&&(c==0)) { // CASO 7; ROJO + VERDE
    digitalWrite(pin01,LOW);
    digitalWrite(pin02,HIGH);
    digitalWrite(pin03,HIGH);
  }
    if ((a==1)&&(b==1)&&(c==1)) { // CASO 8: BLANCO
    digitalWrite(pin01,HIGH);
    digitalWrite(pin02,HIGH);
    digitalWrite(pin03,HIGH);
  }

  return 0;
}

// the loop function runs over and over again forever
void loop() {

        salidaLuces(pin3,pin5,pin6,0,0,0); //NEGRO
        delay(1000); 
           
      if (digitalRead(button2) == HIGH){
        salidaLuces(pin3,pin5,pin6,0,0,1); //AZUL
        delay(1000);
        salidaLuces(pin3,pin5,pin6,0,1,0); //VERDE
        delay(1000);
        salidaLuces(pin3,pin5,pin6,0,1,1); //AZUL + VERDE
        delay(1000);
        salidaLuces(pin3,pin5,pin6,1,0,0); //ROJO
        delay(1000);
        salidaLuces(pin3,pin5,pin6,1,0,1); //ROJO + AZUL
        delay(1000);
        salidaLuces(pin3,pin5,pin6,1,1,0); //ROJO + VERDE
        delay(1000);
        salidaLuces(pin3,pin5,pin6,1,1,1); //BLANCO
        delay(1000);
      }
      

}
