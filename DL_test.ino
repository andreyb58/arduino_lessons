#define dll A3
#define dlr A2

void setup() {
  pinMode(dll, INPUT);
  pinMode(dlr, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.print(analogRead(dll));
  Serial.print(" ");
  Serial.println(analogRead(dlr));

}
