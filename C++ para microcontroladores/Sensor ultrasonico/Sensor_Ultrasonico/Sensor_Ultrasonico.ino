// Definindo os pinos do sensor ultrassônico
#define TRIG_PIN 9  // Pino de sinal do sensor ultrassônico
#define ECHO_PIN 6  // Pino de leitura do sensor ultrassônico

// Distância em centímetros para acionar o LED
#define DISTANCIA_LIMITE 20
#define ledpin1 13

void setup() {

  // Configurando os pinos do sensor ultrassônico
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(ledpin1, OUTPUT);

 
}

void loop() {

  float distancia = medirDistancia();
 

  if (distancia <= DISTANCIA_LIMITE) {
 digitalWrite(ledpin1, HIGH);
      
    }
   else {
    digitalWrite(ledpin1, LOW);
  }

}


float medirDistancia() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duracao = pulseIn(ECHO_PIN, HIGH);
  float distancia = (duracao * 0.034) / 2;
  return distancia;
}



