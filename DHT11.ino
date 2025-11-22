#include <DHT.h>
#define DHT_PIN 4
#define LED_PIN 2

DHT dht(DHT_PIN, DHT11);

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  
  // 等待串口连接
  delay(2000);
  Serial.println();
  Serial.println("🌡️  ESP32环境监测仪启动");
  Serial.println("==========================");
  
  dht.begin();
  
  // 启动动画
  for(int i=0; i<3; i++){
    digitalWrite(LED_PIN, HIGH);
    delay(200);
    digitalWrite(LED_PIN, LOW); 
    delay(200);
  }
}

void loop() {
  // 读取传感器数据
  float temp = dht.readTemperature();
  float humi = dht.readHumidity();
  
  // LED状态指示
  if(temp > 28.0) {
    digitalWrite(LED_PIN, HIGH);  // 温度过高，LED常亮警告
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  
  // 检查读数是否有效
  if(isnan(temp) || isnan(humi)) {
    Serial.println("❌ 传感器读取失败，检查接线");
    digitalWrite(LED_PIN, HIGH);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    delay(500);
    return;
  }
  
  // 输出格式化的监测数据
  Serial.print("📊 采样时间: ");
  Serial.print(millis() / 1000);
  Serial.println("秒");
  
  Serial.print("🌡️  温度: ");
  Serial.print(temp);
  Serial.println("℃");
  
  Serial.print("💧 湿度: ");
  Serial.print(humi);
  Serial.println("%");
  
  // 环境评估
  Serial.print("📈 状态: ");
  if(temp < 10.0) {
    Serial.println("太冷了 ❄️");
  } else if(temp > 30.0) {
    Serial.println("太热了 🔥");
  } else if(humi > 80.0) {
    Serial.println("潮湿 🌧️");
  } else if(humi < 30.0) {
    Serial.println("干燥 🏜️");
  } else {
    Serial.println("舒适 😊");
  }
  
  Serial.println("------------------------");
  delay(3000);  // 3秒采样间隔
}