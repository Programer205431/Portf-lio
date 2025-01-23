#include <Motorcontroller.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

// Definindo os pinos
#define IN1 26
#define IN2 25
#define ENA 14
#define IN3 33
#define IN4 32
#define ENB 13

// Criando o objeto da classe MotorController
MotorController motor(IN1, IN2, ENA, IN3, IN4, ENB);

void setup() {
  // Inicializando o Bluetooth
  SerialBT.begin("ESP32_Motor_Controller");
  
  // Inicializando o motor
  motor.begin();
}

void loop() {
  if (SerialBT.available() > 0) {
    char comando = SerialBT.read();

    switch (comando) {
      case 'F':
        motor.moveForward();
        break;
      case 'B':
        motor.moveBackward();
        break;
      case 'L':
        motor.turnLeft();
        break;
      case 'R':
        motor.turnRight();
        break;
      case 'S':
        motor.stopMotors();
        break;
    }
  }
}
