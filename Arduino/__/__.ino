// 定义连接到模拟摇杆的引脚
const int xAxisPin = A0;  // 摇杆的 X 轴连接到 A0
const int yAxisPin = A1;  // 摇杆的 Y 轴连接到 A1
const int buttonPin = A2;  // 按钮连接到数字引脚 D2

void setup() {
  // 开启串行通信，设置波特率为 9600
  Serial.begin(9600);

  // 设置按钮引脚为输入
  pinMode(buttonPin, INPUT_PULLUP); // 使用内置上拉电阻
}

void loop() {
  // 读取模拟引脚的值
  int xValue = analogRead(xAxisPin);  // 读取 X 轴的模拟值
  int yValue = analogRead(yAxisPin);  // 读取 Y 轴的模拟值
  int buttonState = digitalRead(buttonPin); // 读取按钮状态

  // 发送数据，格式为 "<X值,Y值,按钮状态>"
  Serial.print(xValue);
  Serial.print(",");
  Serial.print(yValue);
  Serial.print(",");
  Serial.println(buttonState);

  delay(100);  // 每 100 毫秒发送一次数据，以避免发送数据过快
}
