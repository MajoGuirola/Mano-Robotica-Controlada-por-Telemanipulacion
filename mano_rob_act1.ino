#include <Servo.h>

// Declarar variables de cada dedo y su servomotor
int flex1 = A1, flex2 = A2, flex3 = A3, flex4 = A4, flex5 = A5;
int lectura1, lectura2, lectura3, lectura4, lectura5;
int grados1, grados2, grados3, grados4, grados5;
Servo dedo1, dedo2, dedo3, dedo4, dedo5;

void setup() {
  Serial.begin(9600);

  // Configuración de servos
  dedo1.attach(3);
  dedo2.attach(5);
  dedo3.attach(6);
  dedo4.attach(10);
  dedo5.attach(11);
}

void loop() {
  // Leer los valores analógicos
  lectura1 = analogRead(flex1);
  lectura2 = analogRead(flex2);
  lectura3 = analogRead(flex3);
  lectura4 = analogRead(flex4);
  lectura5 = analogRead(flex5);

  // Mapeo de los valores a grados
  grados1 = map(lectura1, 1000, 960, 180, 0);  // Ajustar estos valores según tus sensores
  grados2 = map(lectura2, 770, 450, 180, 0);
  grados3 = map(lectura3, 850, 650, 180, 0);
  grados4 = map(lectura4, 950, 800, 180, 0);
  grados5 = map(lectura5, 600, 200, 180, 0);  // Cambia este rango a algo válido

  // Imprimir los valores de los sensores y grados correspondientes
  Serial.print("Pulgar: ");
  Serial.print(lectura1);
  Serial.print("      ");
  Serial.print("Índice: ");
  Serial.print(lectura2);
  Serial.print("      ");
  Serial.print("Medio: ");
  Serial.print(lectura3);
  Serial.print("      ");
  Serial.print("Anular: ");
  Serial.print(lectura4);
  Serial.print("      ");
  Serial.print("Meñique: ");
  Serial.println(lectura5);

  // Mover los servos
  dedo1.write(grados5);
  dedo2.write(grados3);
  dedo3.write(grados1);
  dedo4.write(grados2);//***meñique
  dedo5.write(grados4);
}
