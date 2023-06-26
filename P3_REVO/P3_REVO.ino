/*                                                                                                                                                                                                                                    
FUNDACION KINAL
CENTRO EDUCATIVO TECNICO LABORAL KINAL
PERITO EN ELECTRONICA
QUINTO PERITO
SECCION: A
CURSO: TALLER DE ELECTRONICA DIGITAL Y REPARACION DE COMPUTADORAS
ALUMNOS: ANGELLO GABRIEL MANSILLA DIEGUEZ Y DAVID ALFREDO DEL CID RODRIGUEZ
CARNETS: 2022380 y 2022482
PRACTICA 3 BANDA TRANSPORTADORA
*/

#include <Servo.h>

Servo SERVOS;

#define LR 2  //PINES SIN PWM
#define LG 4
#define LB 7
#define LDR A0 //ANALOGICO

#define SERVO 3 //PWM

int mapingR, mapingG, mapingB; // Variables para almacenar el mapeo del LDR.
int LUX; //Variable que almacenara el analisis del reflejo en el LDR.

int IN1 = 8; //Pines del motor STEPPER.
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;

int READING=0; //Variable que almacena una lectura positiva del LDR, en este caso, Sera Verde.


void setup() {

  
  confpin(); // Llamado a la funcion de configuracion de pines.
  Serial.begin(9600); //Encendemos el monitor serieal.

  
}

void loop() {

  banda_trans(); // Llamado a la funcion de la banda transportadora.


  }
  


int sensread (const int sensorPin) //Funcion de la lectura del sensor.
{
  int LECTURA;
  LECTURA = digitalRead(sensorPin);
  return LECTURA;
}



void confpin (void) //Funcion de configuracion de pines.
{
  pinMode(LR,OUTPUT); //Salida.
  pinMode(LG,OUTPUT); //Salida.
  pinMode(LB,OUTPUT); //Salida.
  pinMode(LDR, INPUT); //Entrada.
  pinMode(SERVO, OUTPUT); //Salida.


  pinMode(IN1, OUTPUT); //Salida.
  pinMode(IN2, OUTPUT); //Salida.
  pinMode(IN3, OUTPUT); //Salida.
  pinMode(IN4, OUTPUT); //Salida.

  pinMode(5,INPUT); //Entrada.

  SERVOS.attach(3); //Salida.
  SERVOS.write(90);

  
}



void banda_trans (void) //Funcion de banda transportadora.
{
int demora = 2.0; //Variable para demora.
unsigned char DETECCION = sensread(5); //Variable para realizar las detecciones.
  if (DETECCION == 0 && READING == 1) //Si DETECCION es negativa y READING es positiva, se realizara lo siguiente.
  {
    //Si los pasos se ven raros, es por que estan en reversa, para que la banda este de forma invertida.

    
  digitalWrite(IN1, HIGH); //PASO 1
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(demora);

  digitalWrite(IN1, LOW); //PASO 2
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(demora);

  digitalWrite(IN1, LOW); //PASO 3
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  delay(demora);

  digitalWrite(IN1, LOW); //PASO 4
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(demora);

  digitalWrite(IN1, LOW); //PASO 5
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(demora);

  digitalWrite(IN1, LOW); //PASO 6
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(demora);

  digitalWrite(IN1, HIGH); //PASO 7
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(demora);

  digitalWrite(IN1, HIGH); //PASO 8
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(demora);
}
else if (DETECCION == 1 && READING == 0) //Si DETECCION es Positiva y READING es Negativa, se realizara lo siguiente.
{
  digitalWrite(IN1, HIGH); //PASO 1
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(demora);

  digitalWrite(IN1, LOW); //PASO 2
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(demora);

  digitalWrite(IN1, LOW); //PASO 3
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  delay(demora);

  digitalWrite(IN1, LOW); //PASO 4
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(demora);

  digitalWrite(IN1, LOW); //PASO 5
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(demora);

  digitalWrite(IN1, LOW); //PASO 6
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(demora);

  digitalWrite(IN1, HIGH); //PASO 7
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(demora);

  digitalWrite(IN1, HIGH); //PASO 8
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(demora);
}
else // SI NO...
{
  SENSCOLOR();
}
}

void SENSCOLOR(void) //Configuracion Del Sensor de color.
{
  digitalWrite(LR, HIGH);
  delay(500);
  LUX = analogRead(LDR);
  mapingR = map(LUX,0,1023,0,1023);
  Serial.print("ROJO DETECTADO:   ");
  Serial.println(LUX);
  digitalWrite(LR, LOW);

  digitalWrite(LG, HIGH);
  delay(500);
  LUX = analogRead(LDR);
  mapingG = map(LUX,0,1023,0,1023);
  Serial.print("VERDE DETECTADO:   ");
  Serial.println(LUX);
  digitalWrite(LG, LOW);

  digitalWrite(LB, HIGH);
  delay(500);
  LUX = analogRead(LDR);
  mapingB = map(LUX,0,1023,0,1023);
  Serial.print("AZUL DETECTADO:   ");
  Serial.println(LUX);
  digitalWrite(LB, LOW);


  if (mapingR > mapingG && mapingR > mapingB)
  {
    SERVOS.write(180);
    READING=0;
  }
  else if(mapingG < mapingR && mapingG > mapingB)
  {
    SERVOS.write(45);
    READING=1;
  }
  else if (mapingB > mapingR && mapingB > mapingG)
  {
    SERVOS.write(180);
    READING=0;
  }
  else
  {
    SERVOS.write(180);
    READING=0;
  }
  delay(5000);


  
}




  
