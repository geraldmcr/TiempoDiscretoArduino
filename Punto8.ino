int pin3 = 3;
int pin5 = 5;
int pin6 = 6;

int val0 = 0;
int val1 = 0;
int val2 = 0;  

double brillo3 = 0;
double brillo5 = 0;
double brillo6 = 0;

int analogPin0 = 8;
int analogPin1 = 9;
int analogPin2 = 10;
  
// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(pin3, OUTPUT); // luz verde
  pinMode(pin5, OUTPUT); // luz amarilla
  pinMode(pin6, OUTPUT); // luz roja
}

// the loop function runs over and over again forever
void loop() {
  val0 = analogRead(analogPin0); // lee el 1er potenciometro
  brillo3 = val0/4;

  val1 = analogRead(analogPin1); // lee el 2do potenciometro
  brillo5 = val1/4;

  val2 = analogRead(analogPin2); // lee el 3er potenciometro
  brillo6 = val2/4;
  
  analogWrite(pin3,brillo3); // indica intensidad al led1
  
  analogWrite(pin5,brillo5); // indica intensidad al led2
  
  analogWrite(pin6,brillo6); // indica intensidad al led3

  delay(1000);
}
