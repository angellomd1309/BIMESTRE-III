/*
FUNDACION KINAL
CENTRO EDUCATIVO TECNICO LABORAL KINAL
PERITO EN ELECTRONICA
QUINTO PERITO
SECCION: A
CURSO: TALLER DE ELECTRONICA DIGITAL Y REPARACION DE COMPUTADORAS
ALUMNO: ANGELLO GABRIEL MANSILLA DIEGUEZ
CARNETS: 2022380
PRACTICA 1 ISR
*/

#include <Ticker.h> //Incluimos librerias correspondientes.
#include <OneWire.h>                
#include <DallasTemperature.h>


#define BT 3 //Definimos el boton.

void TEMP(void); //Hacemos llamado a las funciones.
void BTN(void);

OneWire ourWire(2); //Creamos nuestro One WIre en el pin 2.
DallasTemperature TempSens(&ourWire); //Creamos el sensor.

Ticker TempState(TEMP,3000); //Ticker de temperatura.
Ticker BtnState(BTN,6000); //Ticker de boton.

volatile static bool BTNSTATE; // Bool para boton.



void setup() { //Iniciamos todo.
  Serial.begin(9600);
  TempSens.begin();
  TempState.start();
  BtnState.start();
}
void loop() {
  TempState.update(); //Actualizacion constantes del Ticker.
  BtnState.update();

}

void BTN(void) // FUNCION PARA LECTURA DE BOTON
{
  BTNSTATE = digitalRead(BT); 
  if (BTNSTATE == HIGH) {
    Serial.println("Boton Presionado");
  }
  else if (BTNSTATE == LOW) {
    Serial.println("No Se Ha Presionado El Boton");
  }
    
  }
void TEMP(void) //FUNCION PARA IMPRESION DE TEMPERATURA.
{
    TempSens.requestTemperatures();
  int GRADOS = TempSens.getTempCByIndex(0);
  if (GRADOS < -127) {
    Serial.println(GRADOS);
  } else if(GRADOS == -127) {
    Serial.println("ERROR");
  }
}
