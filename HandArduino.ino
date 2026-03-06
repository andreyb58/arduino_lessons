#include <Servo.h>
Servo s1 = Servo();
Servo s2 = Servo();


void setup() {
  s1.attach(6);
  s2.attach(7);
  s2.write(140);
}

void loop() {
  rotate();
}

void rotate(){
  s1.writeMicroseconds(1700);
  delay(1000);
  s1.writeMicroseconds(1500);
  delay(1000);
  s2.write(20);
  delay(2000);
  s2.write(140);
  delay(1000);
  s1.writeMicroseconds(1300);
  delay(1000);
  s1.writeMicroseconds(1500);
  delay(1000);
}
