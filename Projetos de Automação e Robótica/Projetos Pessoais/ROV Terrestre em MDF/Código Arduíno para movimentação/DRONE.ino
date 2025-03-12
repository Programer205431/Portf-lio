#include <AFMotor.h>

// Definição dos motores conectados ao shield
AF_DCMotor motor1(1); // Motor 1 no canal M1
AF_DCMotor motor2(2); // Motor 2 no canal M2
AF_DCMotor motor3(3); // Motor 3 no canal M3
AF_DCMotor motor4(4); // Motor 4 no canal M4



void setup() {
  
  // Inicializa a comunicação serial para o HC-05
  Serial.begin(9600); 
  Serial.println("Controle Bluetooth inicializado. Aguardando comandos...");
}

void loop() {
  

  // Verifica se há dados recebidos via Bluetooth
  if (Serial.available()) {
    char comando = Serial.read(); // Lê o comando enviado pelo HC-05

    // Controle baseado nos comandos recebidos
    switch (comando) {
      case 'F': // Frente
        motor1.run(BACKWARD);
        motor2.run(FORWARD);
        motor3.run(FORWARD);
        motor4.run(FORWARD);
        Serial.println("Comando: Frente");
        break;

      case 'B': // Trás
        motor1.run(FORWARD);
        motor2.run(BACKWARD);
        motor3.run(BACKWARD);
        motor4.run(BACKWARD);
        Serial.println("Comando: Trás");
        break;

      case 'L': // Esquerda
        motor1.run(BACKWARD);
        motor2.run(BACKWARD);
        motor3.run(BACKWARD);
        motor4.run(FORWARD);
        Serial.println("Comando: Esquerda");
        break;

      case 'R': // Direita
        motor1.run(FORWARD);
        motor2.run(FORWARD);
        motor3.run(FORWARD);
        motor4.run(BACKWARD);
        Serial.println("Comando: Direita");
        break;

      case 'S': // Parar
        motor1.run(RELEASE);
        motor2.run(RELEASE);
        motor3.run(RELEASE);
        motor4.run(RELEASE);
        Serial.println("Comando: Parar");
        break;

      default:
        Serial.println("Comando inválido!");
        break;
    }
  }
}

