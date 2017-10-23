/*
 
*/
  int pin3 = 3;
  int pin5 = 5;
  int pin6 = 6;
  
  int val0 = 0;
  int val1 = 0;
  int val2 = 0;  

  double brillo3 = 0;
  double brillo5 = 0;
  double brillo6 = 0;

  double porcentaje3 = 0;
  double porcentaje5 = 0;
  double porcentaje6 = 0; 
  
  int analogPin0 = 8;
  int analogPin1 = 9;
  int analogPin2 = 10;
  
// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);

  pinMode(pin3, OUTPUT); // luz verde
  pinMode(pin5, OUTPUT); // luz amarilla
  pinMode(pin6, OUTPUT); // luz roja
  
}

// the loop function runs over and over again forever
void loop() {
   val0 = analogRead(analogPin0);
   brillo3 = val0/4;
   porcentaje3 = (brillo3/255)*100;
   
   val1 = analogRead(analogPin1);
   brillo5 = val1/4;
   porcentaje5 = (brillo5/255)*100;
   
   val2 = analogRead(analogPin2);
   brillo6 = val2/4;
   porcentaje6 = (brillo6/255)*100;
   
  analogWrite(analogPin0, brillo3);
  analogWrite(pin3,brillo3);
  String s1 = "Porcentaje de Azul: ";
  Serial.println(s1 + porcentaje3 + "%"); 
  
  analogWrite(analogPin1, brillo5);   
  analogWrite(pin5,brillo5);
  String s2 = "Porcentaje de Verde: ";
  Serial.println(s2 + porcentaje5 + "%");

  analogWrite(analogPin2, brillo6);
  analogWrite(pin6,brillo6);
  String s3 = "Porcentaje de Rojo: "; 
  Serial.println(s3 + porcentaje6 + "%");

  delay(1000);
}
