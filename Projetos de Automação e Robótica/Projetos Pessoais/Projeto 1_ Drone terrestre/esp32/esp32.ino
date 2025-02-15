#include <LiquidCrystal.h>
#include "DHT.h"

#define DHTPIN 13        // Pino do DHT11
#define DHTTYPE DHT11    // Tipo do sensor DHT11
#define TRIG_PIN 27      // Pino TRIG do sensor ultrassônico
#define ECHO_PIN 26      // Pino ECHO do sensor ultrassônico
#define LED_PIN 14       // Pino do LED
#define BUZZER_PIN 25    // Pino do Buzzer
#define RS 5             // Pino RS do LCD
#define ENABLE 4         // Pino ENABLE do LCD
#define D4 16            // Pino D4 do LCD
#define D5 17            // Pino D5 do LCD
#define D6 18            // Pino D6 do LCD
#define D7 19            // Pino D7 do LCD

LiquidCrystal lcd(RS, ENABLE, D4, D5, D6, D7);
DHT dht(DHTPIN, DHTTYPE);

bool buzzerActivated = false; // Variável de estado do buzzer

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  lcd.begin(16, 2);
  dht.begin();

  lcd.print("Iniciando...");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Leitura do ultrassônico
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = (duration * 0.034) / 2; // Calcula a distância em cm

  // Leitura do DHT11
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Exibição no LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(temperature, 1);
  lcd.print("C ");
  lcd.print("Umid:");
  lcd.print(humidity, 1);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("Dist:");
  lcd.print(distance, 1);
  lcd.print(" cm");

  // Controle do LED e do Buzzer
  if (distance <= 10 && distance > 0) { // Objeto detectado a 10 cm ou menos
    digitalWrite(LED_PIN, HIGH);
    if (!buzzerActivated) {
      tone(BUZZER_PIN, 1000, 500); // Toca o buzzer por 500ms
      buzzerActivated = true;      // Marca como já ativado
    }
  } else {
    digitalWrite(LED_PIN, LOW);
    buzzerActivated = false;       // Reseta o estado do buzzer
  }

  delay(1000); // Atualização a cada segundo
}
