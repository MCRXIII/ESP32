// 配置单个数码管的输出
// 定义输出引脚并把所有引脚存到数组中
int pin_a = 4;
int pin_b = 5;
int pin_c = 19;
int pin_d = 21;
int pin_e = 22;
int pin_f = 2;
int pin_g = 15;
int pin_dp = 18;

int pin_array[8] = {pin_a, pin_b, pin_c, pin_d, pin_e, pin_f, pin_g, pin_dp};

// 定义数字显示逻辑的二维数组
int number_array[][8] = {
    {1, 1, 1, 1, 1, 1, 0, 0}, // 1
    {0, 1, 1, 0, 0, 0, 0, 0}, // 0
    {1, 1, 0, 1, 1, 0, 1, 0}, // 2
    {1, 1, 1, 1, 0, 0, 1, 0}, // 3
    {0, 1, 1, 0, 0, 1, 1, 0}, // 4
    {1, 0, 1, 1, 0, 1, 1, 0}, // 5
    {1, 0, 1, 1, 1, 1, 1, 0}, // 6
    {1, 1, 1, 0, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1, 0}, // 8
    {1, 1, 1, 1, 0, 1, 1, 0}, // 9

};

void display_number(int num){
  // 清屏
  for (int i=0;i<8;i++){
    digitalWrite(pin_array[i], HIGH);
    }

  // 改变对应引脚的电平;
  for (int i=0;i<8;i++){
      digitalWrite(pin_array[i], number_array[num][i]);
      }
  }

void setup() {
  // 设置所有引脚为输出模式，初始化所有引脚为高电平
  for (int i=0;i<8;i++){
    pinMode(pin_array[i], OUTPUT);
    digitalWrite(pin_array[i], HIGH);
    }
}

void loop() {
  // 显示数字
  for (int i=0;i<10;i++){
    display_number(i);
    delay(500);
    }
}
