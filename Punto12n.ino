/*
 * Este programa sirve de plantilla para utilizar la librería
 * TaskScheduler en el curso IE0731: Sistemas en Tiempo discreto
 * 
 * Se recomienda revisar la documentación que está
 * en el sitio virtual del curso, junto con la librería.
 * El sitio donde el autor de la librería aloja el código es el siguiente:
 * https://github.com/arkhipenko/TaskScheduler
 */
#include "Arduino.h"
#include <TaskScheduler.h> //Se carga la librería del Scheduler
Scheduler RealTimeCore; //Esto crea un objeto del tipo Scheduler (definido por la librería). En este caso, el objeto se llama RealTimeCore, pero se puede poner cualquier nombre

// Se definen los pines para las luces
int pin03 = 3;
int pin05 = 5;
int pin06 = 6; 


// Se deben definir los prototipos de las funciones de cada una de las tareas, en este caso se definen tres funciones. En inglés es lo que se llaman Callbacks. Se puede poner el nombre que quiera.
void tarea01Fun();
void tarea02Fun();
void tarea03Fun();

// Acá se crean las tareas. Las tareas son objetos del tipo Task definidos por la librería:
Task tarea01(2000, TASK_FOREVER, &tarea01Fun, &RealTimeCore); //Tarea que se repite cada 1000 milisegundos indefinidamente
Task tarea02(3000, TASK_FOREVER, &tarea02Fun, &RealTimeCore); //Tarea que se repite cada 3000 milisegundos indefinidamente
Task tarea03(5000, TASK_FOREVER, &tarea03Fun, &RealTimeCore); //Tarea que se repite sólo tres veces cada 5000 milisegundos

// Ahora se deben definir explícitamente las funciones
void tarea01Fun(){
  digitalWrite(pin03,HIGH);
  delay(50);
  digitalWrite(pin03,LOW);  
}

void tarea02Fun(){
  digitalWrite(pin05,HIGH);
  delay(50);
  digitalWrite(pin05,LOW);
}

void tarea03Fun(){
  digitalWrite(pin06,HIGH);
  delay(50);
  digitalWrite(pin06,LOW);
}

void setup() {
  // El código que se ponga acá se ejecuta una única vez al inicio:
  Serial.begin(9600); //se inicia la comunicación serial a 9600 bauds

  // Se declaran el modo de los pines
  pinMode(pin03, OUTPUT); // luz verde
  pinMode(pin05, OUTPUT); // luz amarilla
  pinMode(pin06, OUTPUT); // luz roja 
  
  RealTimeCore.init(); //Inicializa el scheduler
  Serial.println("Se inicializo el Scheduler");
  RealTimeCore.addTask(tarea01); //Se agrega la tarea 01 al scheduler
  RealTimeCore.addTask(tarea02); //Se agrega la tarea 02 al scheduler
  RealTimeCore.addTask(tarea03); //Se agrega la tarea 03 al scheduler
  Serial.println("Se agregaron las tareas al Scheduler");
  tarea01.enable(); // Se pone el flag de enable para la tarea 01. Por default, las tareas están desabilitadas
  tarea02.enable(); // Se pone el flag de enable para la tarea 02. Por default, las tareas están desabilitadas
  tarea03.enable(); // Se pone el flag de enable para la tarea 03. Por default, las tareas están desabilitadas
}

void loop() {
  // Acá va el código que se repite indefinidamente:
  RealTimeCore.execute(); // Cuando se usa un scheduler, esta instrucción es la única que debería estar en el loop
}

