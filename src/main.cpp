#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Arduino.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

const int x_1 = A0; //arduino connection pins
const int y_1 = A1; 
int baseAngle = 90; //use this to remember base servo position
int shoulderAngle = 130;

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
    int x_val = analogRead(x_1); //read joystick x value
    int y_val = analogRead(y_1);


    if (x_val < 450)
    {                      //left --> dec servo angle(go left)
      baseAngle--; 
    }
    else if (x_val > 574){ //right --> inc servo angle(go right)
      baseAngle++; 
    }

    if (y_val < 450)
    {
      shoulderAngle--;
    }
    else if (y_val > 574){
      shoulderAngle++;
    }

    baseAngle = constrain(baseAngle, 40, 140); //constraint for base joint
    shoulderAngle = constrain(shoulderAngle, 40, 150); //constraint for shoulder joint

    setServoAngle(0, baseAngle); //move servo to stroed position
    setServoAngle(1, shoulderAngle); 

    delay(15);
}