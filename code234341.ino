// Khai báo chân kết nối tới 74HC595
int dataPin = 2;   // DS
int latchPin = 4;  // ST_CP
int clockPin = 3;  // SH_CP

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  // Chạy LED sang phải
  for (int i = 0; i < 8; i++) {
    byte data = 1 << i;
    shiftOutData(data);
    delay(1000);
  }

  // Chạy LED sang trái
  for (int i = 6; i > 0; i--) {
    byte data = 1 << i;
    shiftOutData(data);
    delay(1000);
  }
}

// Hàm gửi dữ liệu ra 74HC595
void shiftOutData(byte data) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, data);
  digitalWrite(latchPin, HIGH);
}
