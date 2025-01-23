
#include <Servo.h>
Servo myServo;  // Definição do objeto Servo

void setup() {
  // Inicializando o servo
  myServo.attach(3);  // Defina o pino de controle do servo (ajuste conforme necessário)
  myServo.write(90);
  delay(500);
}

void loop() {
  


    moveServoTo90();
    delay(1000);
    moveServoTo0();
    delay(1000);
  }


void moveServoTo90() {
  myServo.write(90);
  delay(500);
}

void moveServoTo0() {
  myServo.write(0);
  delay(500);
}