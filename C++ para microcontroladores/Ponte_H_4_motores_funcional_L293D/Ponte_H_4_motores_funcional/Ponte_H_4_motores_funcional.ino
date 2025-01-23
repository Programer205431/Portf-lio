//MODO DE COMBATE ATIVADO APENAS POR DETECÇÃO DO SENSOR
//SÃO USADOS PINOS 4,7,8,12, 5V e GND PARA PONTE H 4 MOTORES
#include <AFMotor.h> // Biblioteca da Adafruit Motor Shield





// Inicializando os motores DC
AF_DCMotor motor1(1); // Motor 1 (CI 1)
AF_DCMotor motor2(2); // Motor 2 (CI 1)
AF_DCMotor motor3(3); // Motor 3 (CI 2)
AF_DCMotor motor4(4); // Motor 4 (CI 2)

void setup() {
  // Configuração da velocidade dos motores
  motor1.setSpeed(255); // Velocidade máxima
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);

  // Inicializando a comunicação serial para monitoramento
  Serial.begin(9600);
  Serial.println("Testando controle de motores via monitor serial.");
  Serial.println("Digite a letra para o movimento que deseja realizar:");
  Serial.println("F - Todos os motores para frente");
  Serial.println("B - Todos os motores para trás");
  Serial.println("L - Todos os motores para esquerda");
  Serial.println("R - Todos os motores para direita");
  Serial.println("1 - Diagonal frente esquerda");
  Serial.println("2 - Diagonal frente direita");
  Serial.println("3 - Diagonal trás esquerda");
  Serial.println("4 - Diagonal trás direita");

}

void loop() {
  if (Serial.available() > 0) {
    char comando = Serial.read(); // Lê o caractere do monitor serial
    
    switch (comando) {
      case 'F':
        moverParaFrente(); // Movimenta todos os motores para frente
        break;
      case 'B':
        moverParaTras(); // Movimenta todos os motores para trás
        break;
      case 'L':
        moverParaEsquerda(); // Movimenta todos os motores para esquerda
        break;
      case 'R':
        moverParaDireita(); // Movimenta todos os motores para direita
        break;
      case 'S':
        pararMotores(); // Movimenta todos os motores para direita
        break;

      
    }
  }


    

  
}



// Função para mover todos os motores para frente
void moverParaFrente() {
  Serial.println("Movendo todos os motores para frente");
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);

}

// Função para mover todos os motores para trás
void moverParaTras() {
  Serial.println("Movendo todos os motores para trás");
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);

}

// Função para mover todos os motores para a esquerda
void moverParaEsquerda() {
  Serial.println("Movendo todos os motores para esquerda");
  motor1.run(BACKWARD); // Motor 1 vai para trás
  motor2.run(BACKWARD);  // Motor 2 vai para frente
  motor3.run(FORWARD);  // Motor 3 vai para frente
  motor4.run(FORWARD); // Motor 4 vai para trás

}

// Função para mover todos os motores para a direita
void moverParaDireita() {
  Serial.println("Movendo todos os motores para direita");
  motor1.run(FORWARD);  // Motor 1 vai para frente
  motor2.run(FORWARD); // Motor 2 vai para trás
  motor3.run(BACKWARD); // Motor 3 vai para trás
  motor4.run(BACKWARD);  // Motor 4 vai para frente
  
}
// Função para parar todos os motores
void pararMotores() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  Serial.println("Todos os motores pararam.");
  delay(1000); // Espera 1 segundo antes de receber outro comando
}
