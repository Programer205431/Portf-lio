#define RED_PIN 5
#define GREEN_PIN 10
#define BLUE_PIN 11
bool isCommonAnode = true;
void setup(){
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}
  void loop(){
    setColor( 255, 0, 0),//azul
    delay(1000);
    setColor(0, 255, 0);//vermelho
    delay(1000);
    setColor( 0, 0, 255);//verde
    delay(1000);
  }
  
  
  
void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(RED_PIN, isCommonAnode ? 255 - redValue : redValue);
  analogWrite(GREEN_PIN, isCommonAnode ? 255 - greenValue : greenValue);
  analogWrite(BLUE_PIN, isCommonAnode ? 255 - blueValue : blueValue);
}