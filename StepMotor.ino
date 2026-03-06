#include <Stepper.h>

const int steps_per_rev = 200; //Set to 200 for NIMA 17
#define IN1 7
#define IN2 6
#define IN3 5
#define IN4 4

Stepper motor(steps_per_rev, IN1, IN2, IN3, IN4);


void setup()
{
  motor.setSpeed(60);
}

void loop() 
{
  motor.step(steps_per_rev);
  delay(500);

  motor.step(-steps_per_rev);
  delay(500);
}
