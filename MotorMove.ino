#define in1 8
#define in2 9
#define in3 10
#define in4 11
#define dll A3
#define dlr A2
#define ena 5
#define enb 6
float power = 110.0;
int counter = 0;
float med_grey = 0;
int left_enc = 0;
int right_enc = 0;

void turn_left(){
    delay(200);
    analogWrite(ena, power);
    analogWrite(enb, power);
    motor(0, 1);
    motor(1, 0);
    while(analogRead(dll) > 300){;}
    m_stop(1000);
}
void turn_right(){
    delay(200);
    analogWrite(ena, power);
    analogWrite(enb, power);
    motor(1, 1);
    motor(0, 0); 
    while(analogRead(dlr) > 300){;}
    m_stop(1000);
}

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(dll, INPUT);
  delay(1000);

}

void line_move() {
  motor(1, 1);
  analogWrite(ena, power + error());
  motor(0, 1);
  analogWrite(enb, power - error());
}

void loop() {
  line_move();
  if (cross()){ 
    m_stop(1000);
    counter++;
    if (counter == 1) {turn_left();}
    if (counter == 2) {turn_right();}
    if (counter == 6) {turn_right();}
    if (counter == 7) {turn_right();}
    if (counter == 11) {turn_left();}
    if (counter == 12) {turn_left();}
    if (counter == 16) {turn_left();}
    if (counter == 17) {turn_right();} 
    if (counter == 18) {m_stop(100000);}           
  }

}

void motor(bool m,bool dir) {
  if (m) {
    if (dir){
       digitalWrite(in1, 0);
       digitalWrite(in2, 1);
    }else {
       digitalWrite(in1, 1);
       digitalWrite(in2, 0);
    }
  } else {
    if (dir){
       digitalWrite(in3, 0);
       digitalWrite(in4, 1);
    } else {
       digitalWrite(in3, 1);
       digitalWrite(in4, 0);
    }
  }
}

void m_stop(int t) {
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
  analogWrite(ena, 0);
  analogWrite(enb, 0);
  delay(t);
}

float error() {
  return 0.1 * (analogRead(dll) - analogRead(dlr));
}

bool cross(){
  return ((analogRead(dll) < 400) and (analogRead(dlr) < 400));
}
