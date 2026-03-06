#define dr_left A2
#define dr_right A3



float dist_left(){
  return 65*pow((analogRead(A2)*0.00488758553), -1.10);
}

float dist_right(){
  return 32*pow((analogRead(A3)*0.00488758553), -1.10);
}

void setup() {
  Serial.begin(9600);
  pinMode(dr_left, INPUT);
  pinMode(dr_right, INPUT);
}

void loop() {
  Serial.print(analogRead(A3));
  Serial.print("  ");
  Serial.print(analogRead(A2));
  Serial.print("  ");
  Serial.print(dist_left());  
  Serial.print("  ");
  Serial.println(dist_right());  

}
