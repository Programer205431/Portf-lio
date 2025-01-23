#include <AFMotor.h> // Biblioteca da Adafruit Motor Shield

// Inicializando os motores DC
AF_DCMotor motor1(1); // Motor 1 (CI 1)
AF_DCMotor motor2(2); // Motor 2 (CI 1)
AF_DCMotor motor3(3); // Motor 3 (CI 2)
AF_DCMotor motor4(4); // Motor 4 (CI 2)

// Definição dos pinos do sensor ultrassônico
const int trigPin = 6; // Pino trig
const int echoPin = 9; // Pino echo

// Definição dos pinos do LED RGB
const int redPin = 5;   // Pino do LED vermelho
const int greenPin = 11; // Pino do LED verde
const int bluePin = 3;  // Pino do LED azul

void setup() {
  // Configuração dos pinos do LED RGB como saída
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Configuração dos pinos do sensor ultrassônico
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Configuração da velocidade dos motores
  motor1.setSpeed(255); // Velocidade máxima
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);

  // Inicializando a comunicação serial para receber comandos da ESP32
  Serial.begin(9600);
  Serial.println("Arduino pronto para receber comandos via ESP32.");
}

void loop() {
  // Verifica a distância do sensor ultrassônico
  long distancia = medirDistancia();

  // Lógica para o LED RGB
  if (distancia <= 20) {
    // Objeto detectado, LED vermelho
    setLedColor(255, 0, 0); // Vermelho
  } else {
    // Sem objeto, LED branco
    setLedColor(255, 255, 255); // Branco
  }

  // Verifica comandos via serial
  if (Serial.available() > 0) {
    char comando = Serial.read(); // Lê o caractere recebido via ESP32
    
    switch (comando) {
      case 'F':
        moverParaFrente();
        break;
      case 'B':
        moverParaTras();
        break;
      case 'L':
        moverParaEsquerda();
        break;
      case 'R':
        moverParaDireita();
        break;
      case 'S':
        pararMotores();
        break;
      default:
        Serial.println("Comando inválido.");
        break;
    }
  }
}

// Funções do sensor ultrassônico
long medirDistancia() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duracao = pulseIn(echoPin, HIGH);
  long distancia = duracao * 0.034 / 2; // Conversão para centímetros
  return distancia;
}

// Função para definir a cor do LED RGB
void setLedColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

// Funções de movimento
void moverParaFrente() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void moverParaTras() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void moverParaEsquerda() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void moverParaDireita() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void pararMotores() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
