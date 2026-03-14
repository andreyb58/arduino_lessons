#include <Servo.h>

#define IN1 13
#define IN2 12
#define IN3 9
#define IN4 8
#define in1 7
#define in2 6
#define in3 5
#define in4 4
#define enb 10
#define ena 11
#define dline A1
#define servo_port A0
int counter1 = 0;
int counter2 = 0;
float k_y = 3000 / 20.5;
float k_x = 1000 / 6.4;
float power = 240;
int dl = 2.5;
Servo servo;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(dl, INPUT);
  servo.attach(servo_port);
  attachInterrupt(1, increase1, RISING);
  attachInterrupt(0, increase2, RISING);
  Serial.begin(9600);
  delay(1000);
  //move_y(1, 12);
  //move(0, 12);
  //start();
}

void loop() {
  digitalWrite(in1, 1);
    digitalWrite(in2, 0);
    digitalWrite(in3, 1);
    digitalWrite(in4, 0);

    analogWrite(ena, power);
    analogWrite(enb, power);
}

void move_y(bool d, int cm) {
  int count = cmToCount_y(cm);
  if (d){
    digitalWrite(in1, 1);
    digitalWrite(in2, 0);
    digitalWrite(in3, 1);
    digitalWrite(in4, 0);
  } else {
    digitalWrite(in1, 0);
    digitalWrite(in2, 1);
    digitalWrite(in3, 0);
    digitalWrite(in4, 1);
  }
  while (counter1 <= count and counter2 <= count) {
    float error = 0.1 * (counter1 - counter2);
    analogWrite(ena, power + error);
    analogWrite(enb, power);
    Serial.print(counter1);
    Serial.print(' ');
    Serial.print(counter2);
    Serial.print(' ');
    Serial.print(power + error);
    Serial.print(' ');
    Serial.println(power - error);
  }
  stop();
  nullCounter();
}

void move_x(bool d, int cm) {
  int count = cmToCount_y(cm);
  if (d) {
    for (int i = 0; i < count; i++){
      step_r();
    }
  } else {
    for (int i = 0; i < count; i++){
      step_l();
    }
  }
}

void stop() {
    digitalWrite(in1, 0);
    digitalWrite(in2, 0);
    digitalWrite(in3, 0);
    digitalWrite(in4, 0);
}

void servo_down() {
  servo.write(0);
  delay(1000);
}

void servo_up() {
  servo.write(80);
  delay(1000);
}

void increase1() {
  counter1++;
}

void increase2() {
  counter2++;
}

void nullCounter() {
  counter1 = 0;
  counter2 = 0;
}

int cmToCount_y(int cm) {
  return cm * k_y;
}

int cmToCount_x(int cm) {
  return cm * k_x;
}

void start() {
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
  while(analogRead(dline) > 600) {
    float error = 0.1 * (counter1 - counter2);
    analogWrite(ena, power + error);
    analogWrite(enb, power - error);
    Serial.print(counter1);
    Serial.print(' ');
    Serial.print(counter2);
    Serial.print(' ');
    Serial.print(power + error);
    Serial.print(' ');
    Serial.println(power - error);
  }
  while(analogRead(dline) < 900) {
    float error = 0.1 * (counter1 - counter2);
    analogWrite(ena, power + error);
    analogWrite(enb, power - error);
  }
  stop();
  nullCounter();
}

void step_r() {
  digitalWrite(IN1, HIGH); 
    digitalWrite(IN2, LOW); 
    digitalWrite(IN3, LOW); 
    digitalWrite(IN4, HIGH);
    delay(dl);

    digitalWrite(IN1, HIGH); 
    digitalWrite(IN2, HIGH); 
    digitalWrite(IN3, LOW); 
    digitalWrite(IN4, LOW);
    delay(dl);

    digitalWrite(IN1, LOW); 
    digitalWrite(IN2, HIGH); 
    digitalWrite(IN3, HIGH); 
    digitalWrite(IN4, LOW);
    delay(dl);

    digitalWrite(IN1, LOW); 
    digitalWrite(IN2, LOW); 
    digitalWrite(IN3, HIGH); 
    digitalWrite(IN4, HIGH);
    delay(dl);
}

void step_l() {
    digitalWrite(IN1, LOW); 
    digitalWrite(IN2, LOW); 
    digitalWrite(IN3, HIGH); 
    digitalWrite(IN4, HIGH);
    delay(dl);

    digitalWrite(IN1, LOW); 
    digitalWrite(IN2, HIGH); 
    digitalWrite(IN3, HIGH); 
    digitalWrite(IN4, LOW);
    delay(dl);

    digitalWrite(IN1, HIGH); 
    digitalWrite(IN2, HIGH); 
    digitalWrite(IN3, LOW); 
    digitalWrite(IN4, LOW);
    delay(dl);

    digitalWrite(IN1, HIGH); 
    digitalWrite(IN2, LOW); 
    digitalWrite(IN3, LOW); 
    digitalWrite(IN4, HIGH);
    delay(dl);
}
