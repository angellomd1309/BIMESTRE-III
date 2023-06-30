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

#include <Servo.h> //Incluimos Libreria Servo.

#include <LiquidCrystal_I2C.h> //Incluimos Libreria Liquid Crystal.
LiquidCrystal_I2C crystal(0x27,20,4); //Declaramos el nombre y parametros de nuestro liquid crystal.


Servo SERVOS; //Iniciamos el Servo

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

int sensread (const int sensorPin); //Llamado de funciones.
void confpin (void);
void banda_trans (void);


void setup() {

  
  confpin(); // Llamado a la funcion de configuracion de pines.
  Serial.begin(9600); //Encendemos el monitor serial.
  BIENVENIDA(); //Llamado a la funcion de Bienvenida.



}

void loop() {

  banda_trans(); // Llamado a la funcion de la banda transportadora.


  }
  


int sensread (const int sensorPin) //Funcion de la lectura del sensor.
{
  int LECTURA; //Variable para lectura.
  LECTURA = digitalRead(sensorPin); //Lectura hacemos que lea el pin sensorPin (PIN3).
  return LECTURA; //Retorno.
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
      READING = 0;
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

else if (DETECCION == 1 && READING == 1)
{
  READING = 0;

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
  MOVIMENTO();

  




  
}
}

void SENSCOLOR(void) //Configuracion Del Sensor de color.
{
  digitalWrite(LR, HIGH); //Mapeo de led ROJO.
  delay(700);
  LUX = analogRead(A0);
  mapingR = map(LUX,0,1023,0,1023);
  Serial.print("ROJO DETECTADO:   ");
  Serial.println(LUX);
  digitalWrite(LR, LOW);


  digitalWrite(LG, HIGH); //Mapeo de Led VERDE.
  delay(700);
  LUX = analogRead(A0);
  mapingG = map(LUX,0,1023,0,1023);
  Serial.print("VERDE DETECTADO:   ");
  Serial.println(LUX);
  digitalWrite(LG, LOW);


  digitalWrite(LB, HIGH); //Mapeo de Led AZUL.
  delay(700);
  LUX = analogRead(A0);
  mapingB = map(LUX,0,1023,0,1023);
  Serial.print("AZUL DETECTADO:   ");
  Serial.println(LUX);
  digitalWrite(LB, LOW);
}

void MOVIMENTO (void)
{
  if (mapingR > mapingG && mapingR > mapingB) //Si LED ROJO es mayor a azul y verde, realizar lo siguiente.
  {
    crystal.clear();
    crystal.setCursor(0,0);
    crystal.print("COLOR DETECTADO:");
    crystal.setCursor(0,1);
    crystal.print("     ROJO      ");
    SERVOS.write(180);
    READING=1;    


    
  }
  else if(mapingG > mapingR && mapingG > mapingB) //Si LED VERDE es mayor a azul y verde, realizar lo siguiente.
  {
    crystal.clear();
    crystal.setCursor(0,0);
    crystal.print("COLOR DETECTADO:");
    crystal.setCursor(0,1);
    crystal.print("     VERDE      ");
    SERVOS.write(70);
    READING=1;
  }
  else if (mapingB > mapingR && mapingB > mapingG) //Si LED AZUL es mayor a azul y verde, realizar lo siguiente.
  {
    crystal.clear();
    crystal.setCursor(0,0);
    crystal.print("COLOR DETECTADO:");
    crystal.setCursor(0,1);
    crystal.print("     AZUL      ");
    SERVOS.write(100);
    READING=1;


  }
  else
  {
    SERVOS.write(180); 
    READING=1;
  }
  delay(1000);


  
}

void BIENVENIDA (void) //Funcion de BIenvenida... Es Opcional... la verdad jaja.
{
  SERVOS.write(90);
  crystal.init();
  crystal.backlight();
  crystal.setCursor(0,0);
  crystal.print(">>DETECCION DE<<");
  crystal.setCursor(0,1);
  crystal.print(">>COLORES RGB<<<");
  SERVOS.write(180);
  delay(500);
  SERVOS.write(160);
  delay(300);
  SERVOS.write(140);
  delay(300);
  SERVOS.write(160);
  delay(500);
  SERVOS.write(180);
  delay(670);
  SERVOS.write(140);
  delay(670);
  SERVOS.write(90);
  delay(1000);

  
  

  crystal.clear();
  crystal.setCursor(0,0);
  crystal.print("SIN DETECCIONES");
  crystal.setCursor(0,1);
  crystal.print("ESPERANDO COLOR"); 
  
  
  
}




  
