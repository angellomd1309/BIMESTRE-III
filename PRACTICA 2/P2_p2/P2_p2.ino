/*
FUNDACION KINAL
CENTRO EDUCATIVO TECNICO LABORAL KINAL
PERITO EN ELECTRONICA
QUINTO PERITO
SECCION: A
CURSO: TALLER DE ELECTRONICA DIGITAL Y REPARACION DE COMPUTADORAS
ALUMNO: ANGELLO GABRIEL MANSILLA DIEGUEZ
CARNETS: 2022380
PRACTICA 2 LINEALIZACION DE SENSORES
*/

#define RED 3 //Definimos pines de leds y de el potenciometro.
#define GREEN 5
#define BLUE 6
#define POT A1


int I; //Incluimos unaa variable que funcionara como el mapeador.


void setup() {
  pinMode(RED,OUTPUT); //Configuramos los pines como entrada o salida.
  pinMode(GREEN,OUTPUT);
  pinMode(BLUE,OUTPUT);
  pinMode(POT,INPUT);
  POTCONFIG();
}
void loop() {
  SECUENCE();



}

void SECUENCE () //Funcion para la secuencia.
{
  analogWrite(RED,174);
  analogWrite(GREEN,92);
  analogWrite(BLUE,230);
  delay(I);

  analogWrite(RED,255);
  analogWrite(GREEN,255);
  analogWrite(BLUE,255);
  delay(I);

  analogWrite(RED,0);
  analogWrite(GREEN,255);
  analogWrite(BLUE,255);
  delay(I);

  analogWrite(RED,189);
  analogWrite(GREEN,174);
  analogWrite(BLUE,20);
  delay(I);

  analogWrite(RED,225);
  analogWrite(GREEN,87);
  analogWrite(BLUE,35);
  delay(I);
}

int POTCONFIG () //
{
  int READING=analogRead(POT);
  I=map(READING,0,1023,100,1000);
  return I;
}
