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

#define LED 3 //Definimos pines de leds y de el potenciometro.
#define POT A1
int Strenght; //Incluimos unaa variable que funcionara como el mapeador.    

void setup() {
  pinMode(LED, OUTPUT); //Configuramos los pines como entrada o salida.
  pinMode(POT, INPUT);
}

void loop() {
  STLED();


}

void STLED ()
{
  int STATEREAD = analogRead(POT);
  Strenght = map(STATEREAD, 0, 1023, 0, 255);
  analogWrite(LED, Strenght); 

}
