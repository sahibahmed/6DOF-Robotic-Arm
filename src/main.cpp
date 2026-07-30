#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Arduino.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

const int x = A0; //arduino connection pins
const int y = A1; 
int baseAngle = 90; //use this to remember base servo position

#define SERVOMIN 150
#define SERVOMAX 600

void setServoAngle(int channel, int angle)
{
  angle = constrain(angle, 0, 180);
  int pulse = map(angle, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(channel, 0, pulse);
} //convert pulse values into readable angle values

void setup() {
    pwm.begin();
    pwm.setPWMFreq(50);
}

void loop() { //velocity-style control
    int x_val = analogRead(x); //read joystick x value
    int y_val = analogRead(y);


    if (x_val < 450){ //left --> dec servo angle(go left)
      baseAngle--; 
    }
    else if (x_val > 574){//right --> inc servo angle(go right)
      baseAngle++; 
    }

    baseAngle = constrain(baseAngle, 40, 140); //constraint

    setServoAngle(0, baseAngle); //move servo to stroed position

    delay(15);

}