#include <Servo.h> //Nombramiento de Libreria.

Servo hombro; // Creación del objeto "hombro".
Servo codo; // Creación del objeto "codo".
Servo brazo; // Creación del objeto "brazo".
Servo mano; // Creación del objeto "mano".

int X1 = A1; // variable para lectura del eje x del joystick 1
int Y1 = A2; // variable para lectura del eje y del joystick 1
int X2 = A3; // variable para lectura del eje x del joystick 2
int Y2 = A4; // variable para lectura del eje y del joystick 2

int angulo1 = 90; // angulo de inicio para el "hombro".
int angulo2 = 90; // angulo de inicio para el "codo".
int angulo3 = 50; // angulo de inicio para el "brazo".
int angulo4 = 0; // angulo de inicio para el "mano".           
int salto = 2; // variación del angulo.

int joyX1 = 0; // Inicializando la variable de lectura.
int joyY1 = 0; // Inicializando la variable de lectura.
int joyX2 = 0; // Inicializando la variable de lectura.
int joyY2 = 0; // Inicializando la variable de lectura.

void setup() {
  
  Serial.begin (9600); //Puerto serial
  
  hombro.attach(11,600,1500); // Se usará "hombro" a traves del pin digital 11(pwm) del arduino.
  codo.attach(6,600,1500); // Se usará "codo" a traves del pin digital 6(pwm) del arduino.
  brazo.attach(9,600,1500); // Se usará "brazo" a traves del pin digital 9(pwm) del arduino.
  mano.attach(3,600,1500); // Se usará "mano" a traves del pin digital 3(pwm) del arduino.
}

void loop() {
  
  int joyX1 = analogRead(X1);
  Serial.println(joyX1);
  
            if ( joyX1 < 400 )                    // Si la lectura es menor de 400
                 angulo1 = angulo1 - salto ;    // disminuimos el angulo
            else if ( joyX1 > 600 )                   // Si mayor de 600
                 angulo1 = angulo1 + salto ;    // Aumentamos el angulo
            hombro.write(angulo1);             // Y este es el que mueve el servo
            delay (10); 
                      
  int joyY1 = analogRead(Y1);
  
            if ( joyY1 < 400 )                    // Si la lectura es menor de 400
                 angulo2 = angulo2 + salto ;    // disminuimos el angulo
            else if ( joyY1 > 600 )                   // Si mayor de 600
                 angulo2 = angulo2 - salto ;    // Aumentamos el angulo
            codo.write(angulo2);             // Y este es el que mueve el servo
            delay (10); 

  int joyX2 = analogRead(X2);
  
            if ( joyX2 < 400 )                    // Si la lectura es menor de 400
                 angulo3 = angulo3 + salto ;    // disminuimos el angulo
            else if ( joyX2 > 600 )                   // Si mayor de 600
                 angulo3 = angulo3 - salto ;    // Aumentamos el angulo
            brazo.write(angulo3);             // Y este es el que mueve el servo
            delay (10); 
            
  int joyY2 = analogRead(Y2);
  
            if ( joyY2 < 400 )                    // Si la lectura es menor de 400
                 angulo4 = angulo4 - salto ;    // disminuimos el angulo
            else if ( joyY2 > 600 )                   // Si mayor de 600
                 angulo4 = angulo4 + salto ;    // Aumentamos el angulo
            mano.write(angulo4);             // Y este es el que mueve el servo
            delay (10); 
  }
