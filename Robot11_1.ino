
#define in1 7
#define in2 6
#define in3 5
#define in4 4
#define ena A4
#define enb A5
int counter = 0;
long k = 200;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  attachInterrupt(1, increase, RISING);
  Serial.begin(9600);
  
  move(1, 12, 190);
  delay(1000);
  move(0, 20, 190);
}

void loop() {
  
  
}

void move(bool d, int cm, int power) {
  long count = cmToCount(cm);
  if (d){
    digitalWrite(in1, 1);
    digitalWrite(in2, 0);
    digitalWrite(in3, 1);
    digitalWrite(in4, 0);
    analogWrite(ena, power);
    analogWrite(enb, power);
  } else {
    digitalWrite(in1, 0);
    digitalWrite(in2, 1);
    digitalWrite(in3, 0);
    digitalWrite(in4, 1);
    analogWrite(ena, power);
    analogWrite(enb, power);
  }
  while (counter <= count) {
    Serial.println(counter);}
  stop();
  nullCounter();
}

void stop() {
    digitalWrite(in1, 0);
    digitalWrite(in2, 0);
    digitalWrite(in3, 0);
    digitalWrite(in4, 0);
}

void increase() {
  counter++;
}

void nullCounter() {
  counter = 0;
}

long cmToCount(int cm) {
  return cm * k;
}
