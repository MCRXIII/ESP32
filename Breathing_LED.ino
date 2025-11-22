// Breathing_LED.ino 使用analogWrite实现板载呼吸灯效果
// 设置LED引脚
#define LED_BOARD   2

void setup() {
  //  设定引脚为输出模式
  pinMode(LED_BOARD, OUTPUT);
}

void loop() {
  // 渐亮
  for(int i = 0; i < 256; i++){
    analogWrite(LED_BOARD, i);
    delay(10);
  }
  // 渐暗
  for(int i = 255; i > 0; i--){
    analogWrite(LED_BOARD, i);
    delay(10);
  }
}
