#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup() {
  // Inicializando Bluetooth
  SerialBT.begin("ESP32-Robot"); // Nome do dispositivo Bluetooth
  Serial.begin(9600); // Comunicação serial com o Arduino via RX2 e TX2
  Serial2.begin(9600, SERIAL_8N1, 16, 17); // Comunicação serial (TX2 = GPIO17, RX2 = GPIO16)
  
  Serial.println("ESP32 pronto para receber comandos via Bluetooth.");
}

void loop() {
  // Receber comando do Bluetooth
  if (SerialBT.available()) {
    char comando = SerialBT.read(); // Lê comando enviado pelo celular
    Serial2.write(comando); // Envia comando para o Arduino
    Serial.print("Comando enviado ao Arduino: ");
    Serial.println(comando);
  }
}
