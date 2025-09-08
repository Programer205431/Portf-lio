#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

// Pinos do leitor RFID
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);

// UID autorizado
byte autorizadoUID[4] = {0x23, 0xE1, 0x2C, 0xDA};

// Pinos do projeto
const int ledVerde = 4;
const int ledVermelho = 5;
const int buzzer = 6;       // Buzzer no pino 6
const int pinoServo = 3;    // Pino do servo motor

Servo servoTrava;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);

  servoTrava.attach(pinoServo);
  travaPorta();

  // Mantém LED vermelho sempre aceso enquanto está travado
  digitalWrite(ledVermelho, HIGH);

  Serial.println("Sistema de Controle de Acesso Iniciado...");
}

void loop() {
  // Verifica se há cartão presente
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  Serial.print("UID lido: ");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    Serial.print(i < mfrc522.uid.size - 1 ? " " : "\n");
  }

  // Verifica se o cartão é autorizado
  if (verificaAcesso()) {
    Serial.println("Acesso Liberado!");
    acessoLiberado();
  } else {
    Serial.println("Acesso Negado!");
  }

  // Finaliza leitura
  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
}

bool verificaAcesso() {
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    if (mfrc522.uid.uidByte[i] != autorizadoUID[i]) return false;
  }
  return true;
}

void acessoLiberado() {
  // Desliga LED vermelho, liga verde e toca buzzer uma vez
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledVerde, HIGH);
  tocarBuzzer(); // Toca o buzzer uma vez

  Serial.println("Abrindo a porta...");

  abrePorta(); // Abre a tranca
  delay(10000); // Mantém aberta por 10 segundos

  // Volta ao estado inicial
  travaPorta();
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledVermelho, HIGH);

  Serial.println("Porta fechada. Acesso bloqueado.");
}

void abrePorta() {
  servoTrava.write(180); // Ângulo para destravar
  Serial.println("Tranca aberta.");
}

void travaPorta() {
  servoTrava.write(0); // Ângulo para travar
  Serial.println("Tranca travada.");
}

void tocarBuzzer() {
  // Se for buzzer passivo, utilizamos a função tone()
  tone(buzzer, 1000, 200);  // Frequência 1000 Hz por 200ms
  delay(250);                // Espera 250ms antes de continuar
  noTone(buzzer);            // Desliga o buzzer após o som
}
