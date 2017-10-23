// se inicializan los pines y variables requeridos
int button2 = 2;
int pin3 = 3;
int pin5 = 5;
int pin6 = 6; 
int counter = 0;

// the setup function runs once when you press reset or power the board
void setup() {
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
  WAIT:
    while (digitalRead(button2) == LOW){
      salidaLuces(pin3,pin5,pin6,0,0,0); //NEGRO
    }

  goto N;

  N: 
    salidaLuces(pin3,pin5,pin6,0,0,0); //NEGRO
    delay(500);
    if (digitalRead(button2) == HIGH) {
      goto A;
    }
    else{
      goto WAIT;
    }

  A: 
    salidaLuces(pin3,pin5,pin6,0,0,1); //AZUL
    delay(500);
    if (digitalRead(button2) == HIGH){
      goto V;
    }
    else{
      goto WAIT;
    }

  V: 
    salidaLuces(pin3,pin5,pin6,0,1,0); //VERDE
    delay(500);
    if (digitalRead(button2) == HIGH){
      goto AV;
    }
    else{
      goto WAIT;
    }

  AV: 
    salidaLuces(pin3,pin5,pin6,0,1,1); //AZUL + VERDE
    delay(500);
    if (digitalRead(button2) == HIGH){
      goto R;
    }
    else{
      goto WAIT;
    }

  R: 
    salidaLuces(pin3,pin5,pin6,1,0,0); //ROJO
    delay(500);
    if (digitalRead(button2) == HIGH){
      goto RA;
    }
    else{
      goto WAIT;
    }

  RA: 
    salidaLuces(pin3,pin5,pin6,1,0,1); //ROJO + AZUL
    delay(500);
    if (digitalRead(button2) == HIGH){
      goto RV;
    }
    else{
      goto WAIT;
    }

  RV: 
    salidaLuces(pin3,pin5,pin6,1,1,0); //ROJO + VERDE
    delay(500);
    if (digitalRead(button2) == HIGH){
      goto B;
    }
    else{
      goto WAIT;
    }

  B: 
    salidaLuces(pin3,pin5,pin6,1,1,1); //BLANCO
    delay(500);
    if (digitalRead(button2) == HIGH){
      goto N;
    }
    else{
      goto WAIT;
    } 
}
