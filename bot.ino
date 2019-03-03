#include <Servo.h> //Servo library
Servo servoLeft; //initialize
Servo servoRight;
int RightSensor = 0; //right photoresistor
int CenterSensor = 1; //center photoresistor
int LeftSensor = 2; //left photoresistor
int RightValue; //value
int TolRight = 500; //tolerance value right
int CenterValue; //value
int TolCenter = 500; //tolerance value center
int LeftValue; //value
int TolLeft = 500; //tolerance value left
int x = 1000; //delay for calibration
void setup() { //setup area
  servoLeft.attach(10);  //pins for servos
  servoRight.attach(9);
  Serial.begin(9600); //baud rate for serial monitor
}
void forward() { //forward subroutine
  servoLeft.write(0);
  servoRight.write(180);
  delay(2000);
}

void reverse() { //forward subroutine
  servoLeft.write(180);
  servoRight.write(0);
  delay(2000);
}

void turnRight() { //right subroutine
  servoLeft.write(180);
  servoRight.write(180);
  delay(2000);
}
void turnLeft() { //left subroutine
  servoLeft.write(0);
  servoRight.write(0);
  delay(2000);
}

void stopRobot() { //stop subroutine
  servoLeft.write(90);
  servoRight.write(90);
  delay(2000);
}
void loop() {
  RightValue = analogRead(RightSensor); //read right sensor
  Serial.print("R :");
  Serial.println(RightValue);

  CenterValue = analogRead(CenterSensor); //read center sensor
  Serial.print("C :");
  Serial.println(CenterValue);
  
  LeftValue = analogRead(LeftSensor); //read left sensor
  Serial.print("L :");
  Serial.println(LeftValue);

  if (CenterValue > TolCenter) { //center > tolerance? delay by value then stop then forward
    delay(x);
    stopRobot();

    forward();
  }
  if (RightValue > TolRight) { //right > tolerance? delay by value then stop then right
    delay(x);
    stopRobot();
    turnRight();
  }
  if (LeftValue > TolLeft) { //left > tolerance? delay by value then stop then left
    delay(x);
    stopRobot();
    turnLeft();
  }
}
