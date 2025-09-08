#include <BluetoothSerial.h>
// Definindo os pinos para os motores
#define IN1 26  // Motor A - Pino IN1
#define IN2 25  // Motor A - Pino IN2
#define ENA 14  // Motor A - Pino ENA (Controle de velocidade)

#define IN3 33  // Motor B - Pino IN3
#define IN4 32  // Motor B - Pino IN4
#define ENB 13  // Motor B - Pino ENB (Controle de velocidade)
BluetoothSerial SerialBT;
void setup() {
  // Iniciando o Bluetooth
  SerialBT.begin("ESP32_Motor_Controller"); // Nome do dispositivo Bluetooth

  // Configurando os pinos como saídas
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  // Inicializando os motores parados
  stopMotors();
}

void loop() {
  if (SerialBT.available() > 0) {
    char comando = SerialBT.read();
    
    switch (comando) {
      case 'R':  // Frente
        moveForward();
        break;
      case 'L':  //  Trás
        moveBackward();
        break;
      case 'F':  //  Esquerda
        turnLeft();
        break;
      case 'B':  // Direita
        turnRight();
        break;
      case 'S':  // Parar
        stopMotors();
        break;
    }
  }
}

// Funções para controle dos motores

void moveBackward() {
  // Motor A para trás
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(ENA, HIGH);  // Habilita o motor A

  // Motor B para trás
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(ENB, HIGH);  // Habilita o motor B
}

void moveForward() {
  // Motor A para Frente
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(ENA, HIGH);  // Habilita o motor A

  // Motor B para Frente 
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(ENB, HIGH);  // Habilita o motor B
}

void turnRight() {
  // Motor A para trás
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(ENA, HIGH);

  // Motor B para frente
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(ENB, HIGH);
}

void turnLeft()  {
  // Motor A para frente
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(ENA, HIGH);

  // Motor B para trás
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(ENB, HIGH);
}

void stopMotors() {
  // Parando o Motor A
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(ENA, LOW);

  // Parando o Motor B
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(ENB, LOW);
}

