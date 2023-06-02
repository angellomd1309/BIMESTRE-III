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


//Directivas de preprocesador
#define btn_rising  2     //pin 2 utilizado para una interrupción externa por rising
#define btn_falling 3     //pih 3 utilizado para una interrupción externa por falling


#define AL1 4 //Defiminos leds para el primer BCD
#define AL2 5
#define AL4 6
#define AL8 7

#define BL1 8 //Definimos leds para el segundo BCD
#define BL2 9
#define BL4 10
#define BL8 11

int UNIDAD=0;
int DECENA=0;
//Funciones ISR 
/*
 * ISR = interrupt services routine
 * Estas son las funciones que van a ser llamadas al dispararse una interrupcion externa
 * 
 * NOTA: las funciones deben de ser sin retorno y sin parametros
*/

void funcion_ISR_falling(void);
void funcion_ISR_rising(void);


void setup() {
  CONFIGPINS();


  attachInterrupt(digitalPinToInterrupt(btn_rising),funcion_ISR_rising,RISING);   //Anclar la interrupción del pin 2 a una funcion de ISR, disparada por el flanco ascendente
  attachInterrupt(digitalPinToInterrupt(btn_falling),funcion_ISR_falling,FALLING); //Anclar la interrupción del pin 3 a una funcion de ISR, disparada por el flanco descendente
}

void loop() {
    CCONT();
    LED_UNIDADES();
    LED_DECENAS();

}


//Funciones de ISR
void funcion_ISR_rising(void)
{
  UNIDAD=UNIDAD+1;
}

void funcion_ISR_falling(void)
{
  UNIDAD=UNIDAD-1;
}

void CONFIGPINS(void)
{
  pinMode(btn_rising, INPUT);  //pin 2 como entrada
  pinMode(btn_falling, INPUT); //pin 3 como entrada
  pinMode(AL1, OUTPUT);
  pinMode(AL2, OUTPUT);
  pinMode(AL4, OUTPUT);
  pinMode(AL8, OUTPUT);
  pinMode(BL1, OUTPUT);
  pinMode(BL2, OUTPUT);
  pinMode(BL4, OUTPUT);
  pinMode(BL8, OUTPUT);
}

void CCONT(void)
{
    if(UNIDAD > 9) {
    UNIDAD = 0;
    DECENA = DECENA+1;
  }
  if((DECENA == 5) && (UNIDAD >0)) {
    DECENA = 0;
    UNIDAD = 0;
  }
  if((DECENA == 0) && (UNIDAD <0)) {
    DECENA = 5;
    UNIDAD = 0;
  }
  if(UNIDAD < 0) {
    UNIDAD = 9;
    DECENA = DECENA-1;
  }

}

void LED_UNIDADES (void)
{
   switch (UNIDAD) {
    case 0:
    digitalWrite(AL1, LOW);
    digitalWrite(AL2, LOW);
    digitalWrite(AL4, LOW);
    digitalWrite(AL8, LOW);
    break;
    case 1:
    digitalWrite(AL1, HIGH);
    digitalWrite(AL2, LOW);
    digitalWrite(AL4, LOW);
    digitalWrite(AL8, LOW);
    break;
    case 2:
    digitalWrite(AL1, LOW);
    digitalWrite(AL2, HIGH);
    digitalWrite(AL4, LOW);
    digitalWrite(AL8, LOW);
    break;
    case 3:
    digitalWrite(AL1, HIGH);
    digitalWrite(AL2, HIGH);
    digitalWrite(AL4, LOW);
    digitalWrite(AL8, LOW);
    break;
    case 4:
    digitalWrite(AL1, LOW);
    digitalWrite(AL2, LOW);
    digitalWrite(AL4, HIGH);
    digitalWrite(AL8, LOW);
    break;     
    case 5:
    digitalWrite(AL1, HIGH);
    digitalWrite(AL2, LOW);
    digitalWrite(AL4, HIGH);
    digitalWrite(AL8, LOW);
    break;
    case 6:
    digitalWrite(AL1, LOW);
    digitalWrite(AL2, HIGH);
    digitalWrite(AL4, HIGH);
    digitalWrite(AL8, LOW);
    break;
    case 7:
    digitalWrite(AL1, HIGH);
    digitalWrite(AL2, HIGH);
    digitalWrite(AL4, HIGH);
    digitalWrite(AL8, LOW);
    break;
    case 8:
    digitalWrite(AL1, LOW);
    digitalWrite(AL2, LOW);
    digitalWrite(AL4, LOW);
    digitalWrite(AL8, HIGH);
    break;
    case 9:
    digitalWrite(AL1, HIGH);
    digitalWrite(AL2, LOW);
    digitalWrite(AL4, LOW);
    digitalWrite(AL8, HIGH);
    break;    
  }
}

void LED_DECENAS (void)
{
    switch (DECENA) {
    case 0:
    digitalWrite(BL1, LOW);
    digitalWrite(BL2, LOW);
    digitalWrite(BL4, LOW);
    digitalWrite(BL8, LOW);
    break;
    case 1:
    digitalWrite(BL1, HIGH);
    digitalWrite(BL2, LOW);
    digitalWrite(BL4, LOW);
    digitalWrite(BL8, LOW);
    break;
    case 2:
    digitalWrite(BL1, LOW);
    digitalWrite(BL2, HIGH);
    digitalWrite(BL4, LOW);
    digitalWrite(BL8, LOW);
    break;
    case 3:
    digitalWrite(BL1, HIGH);
    digitalWrite(BL2, HIGH);
    digitalWrite(BL4, LOW);
    digitalWrite(BL8, LOW);
    break;
    case 4:
    digitalWrite(BL1, LOW);
    digitalWrite(BL2, LOW);
    digitalWrite(BL4, HIGH);
    digitalWrite(BL8, LOW);
    break;     
    case 5:
    digitalWrite(BL1, HIGH);
    digitalWrite(BL2, LOW);
    digitalWrite(BL4, HIGH);
    digitalWrite(BL8, LOW);
    break;
  }
 

}
