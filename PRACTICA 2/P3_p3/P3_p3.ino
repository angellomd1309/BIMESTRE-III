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



#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C Ohmnimetro(0x27, 16, 2);

#define PUNTALOGICA A0




void setup() {
  pinMode(PUNTALOGICA, INPUT);
  Ohmnimetro.init();
  Ohmnimetro.backlight();


  
}
void loop() {

  RES();
  VT();


}

void RES ()
{

  float Read0 = analogRead(PUNTALOGICA);
  float Read01 = map(Read0, 0, 1023, 0, 500000);
  float vout = Read01 / 100000;
  float V1 = 50000 / vout;
  float resistor = V1 - 10000;
  resistor = resistor + 10;
  Ohmnimetro.setCursor(0, 0);
  Ohmnimetro.print("Ohms: ");
  Ohmnimetro.print(resistor);
  Ohmnimetro.print(" Oh");
}

void VT ()
{
  float Read0 = analogRead(PUNTALOGICA);
  float Read01 = map(Read0, 0, 1023, 0, 500000);
  float vout = Read01 / 100000;
  float V1 = 50000 / vout;
  float resistor = V1 - 10000;
  Ohmnimetro.setCursor(0, 1);
  Ohmnimetro.print("Vout: ");
  Ohmnimetro.print(vout);
  if (vout > 0) {
    Ohmnimetro.print(" V+");
  }
  else {
      Ohmnimetro.print(" V-");
  }
}
