
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Arduino.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

//arduino connection pins
const int x1 = A0; 
const int y1 = A1; 
const int x2 = A2; 
const int y2 = A3; 

const int sw1 = 2; //push-button for open
const int sw2 = 3; //push-button for close

//store servo position for each joint/servo
//initial values act as the "Home Position" settings for the arm 
int baseAngle = 90; 
int shoulderAngle = 145; 
int elbowAngle = 130; 

int wrist_pAngle = 90; //currently unactive
int wrist_rAngle = 20; 
int gripper = 90; 


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
  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
}

void loop() { //velocity-style control
    int x1_val = analogRead(x1); //read x value of joystick 1
    int y1_val = analogRead(y1); //read y value of joystick 1

    int x2_val = analogRead(x2); //read x value of joystick 2 
    int y2_val = analogRead(y2); //read y value of joystick 2


    /*Joystick was physically rotated to simplify wriring while maintaining
    intuitive control directions. Because of which, x and y axis assignments 
    were swapped in software 
    */
    //BASE
    if (y1_val < 450)
    {                      //left --> dec servo angle(go left)
      baseAngle -= 1; 
    }
    else if (y1_val > 574)
    { //right --> inc servo angle(go right)
      baseAngle += 1; 
    }


    //SHOULDER
    if (x1_val < 450)
    {
      shoulderAngle -= 1;
    }
    else if (x1_val > 574)
    {
      shoulderAngle += 1;
    }


    //ELBOW
    if (x2_val < 450)
    {                      //left --> dec servo angle(go left)
      elbowAngle -= 1; 
    }
    else if (x2_val > 574)
    { //right --> inc servo angle(go right)
      elbowAngle += 1; 
    }


    //WRIST ROTATION
    if (y2_val < 450)
    {
      wrist_pAngle -= 1;
    }
    else if (y2_val > 574)
    {
      wrist_pAngle += 1;
    }



    //GRIPPER 
    if (digitalRead(sw1) == LOW){ //Open
      setServoAngle(5, 150);
    }
    if (digitalRead(sw2) == LOW){ //Close
      setServoAngle(5, 90);
    }


    
    baseAngle = constrain(baseAngle, 40, 140); //constraint for base joint
    shoulderAngle = constrain(shoulderAngle, 40, 150); //constraint for shoulder joint
    elbowAngle = constrain(elbowAngle, 20, 160); //constraint for shoulder joint
    wrist_rAngle = constrain(wrist_rAngle, 20, 160); //constraint for shoulder joint

    setServoAngle(0, baseAngle); //move servo to stored position
    setServoAngle(1, shoulderAngle); 
    setServoAngle(2, elbowAngle);
    setServoAngle(4, wrist_rAngle);

    delay(20);
}
