int counter = 0;  // переменная-счётчик
int intFlag = false;

void btnIsr() {
  intFlag = true;
}

void setup() {
  Serial.begin(115200);

  pinMode(3, INPUT_PULLUP);

  attachInterrupt(1, btnIsr, FALLING);
}

void loop() {
  if (intFlag) {
    intFlag = false;
    counter++;
    Serial.println(counter);
  }       
}
