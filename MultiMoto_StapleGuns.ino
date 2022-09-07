#include "HallMotor.h"
#include <SPI.h>
// L9958 slave select pins for SPI
#define SS_M4 14
#define SS_M3 13
#define SS_M2 12
#define SS_M1 11
// L9958 DIRection pins
#define DIR_M1 2
#define DIR_M2 3
#define DIR_M3 4
#define DIR_M4 7
// L9958 PWM pins
#define PWM_M1 9
#define PWM_M2 10    // Timer1
#define PWM_M3 5
#define PWM_M4 6     // Timer0


// L9958 Enable for all 4 motors
int ENABLE_MOTORS = 8;



int pwm1, pwm2, pwm3, pwm4;
boolean dir1, dir2, dir3, dir4;

int hallSensor1 = 22; 
int hallSensor2 = 23; 

volatile int hallCount_motor1 = 0;
volatile int hallCount_motor2 = 0;

int countDifference1 = 0;
int countDifference2 = 0;

void setup() {
  unsigned int configWord;


  // put your setup code here, to run once:
  pinMode(SS_M1, OUTPUT); digitalWrite(SS_M1, LOW);  // HIGH = not selected
  pinMode(SS_M2, OUTPUT); digitalWrite(SS_M2, LOW);
  pinMode(SS_M3, OUTPUT); digitalWrite(SS_M3, LOW);
  pinMode(SS_M4, OUTPUT); digitalWrite(SS_M4, LOW);

  // L9958 DIRection pins
  pinMode(DIR_M1, OUTPUT);
  pinMode(DIR_M2, OUTPUT);
  pinMode(DIR_M3, OUTPUT);
  pinMode(DIR_M4, OUTPUT);

  // L9958 PWM pins
  pinMode(PWM_M1, OUTPUT);  digitalWrite(PWM_M1, LOW);
  pinMode(PWM_M2, OUTPUT);  digitalWrite(PWM_M2, LOW);    // Timer1
  pinMode(PWM_M3, OUTPUT);  digitalWrite(PWM_M3, LOW);
  pinMode(PWM_M4, OUTPUT);  digitalWrite(PWM_M4, LOW);    // Timer0

  // L9958 Enable for all 4 motors
  pinMode(ENABLE_MOTORS, OUTPUT);
  digitalWrite(ENABLE_MOTORS, HIGH);  // HIGH = disabled

  /******* Set up L9958 chips *********
    ' L9958 Config Register
    ' Bit
    '0 - RES
    '1 - DR - reset
    '2 - CL_1 - curr limit
    '3 - CL_2 - curr_limit
    '4 - RES
    '5 - RES
    '6 - RES
    '7 - RES
    '8 - VSR - voltage slew rate (1 enables slew limit, 0 disables)
    '9 - ISR - current slew rate (1 enables slew limit, 0 disables)
    '10 - ISR_DIS - current slew disable
    '11 - OL_ON - open load enable
    '12 - RES
    '13 - RES
    '14 - 0 - always zero
    '15 - 0 - always zero
  */  // set to max current limit and disable ISR slew limiting
  configWord = 0b0000010000001100;

  SPI.begin();
  SPI.setBitOrder(LSBFIRST);
  SPI.setDataMode(SPI_MODE1);  // clock pol = low, phase = high

  // Motor 1
  digitalWrite(SS_M1, LOW);
  SPI.transfer(lowByte(configWord));
  SPI.transfer(highByte(configWord));
  digitalWrite(SS_M1, HIGH);
  // Motor 2
  digitalWrite(SS_M2, LOW);
  SPI.transfer(lowByte(configWord));
  SPI.transfer(highByte(configWord));
  digitalWrite(SS_M2, HIGH);
  // Motor 3
  digitalWrite(SS_M3, LOW);
  SPI.transfer(lowByte(configWord));
  SPI.transfer(highByte(configWord));
  digitalWrite(SS_M3, HIGH);
  // Motor 4
  digitalWrite(SS_M4, LOW);
  SPI.transfer(lowByte(configWord));
  SPI.transfer(highByte(configWord));
  digitalWrite(SS_M4, HIGH);

  //Set initial actuator settings to pull at 0 speed for safety
  dir1 = 0; dir2 = 0; dir3 = 0; dir4 = 0; // Set direction
  pwm1 = 0; pwm2 = 0; pwm3 = 0; pwm4 = 0; // Set speed (0-255)

  digitalWrite(ENABLE_MOTORS, LOW);// LOW = enabled

  pinMode(hallSensor1,INPUT);//HALL SENSOR
  pinMode(hallSensor2,INPUT);

  digitalWrite(hallSensor1, LOW);//set hall, set low to start for rising edge
  digitalWrite(hallSensor2, LOW);//set hall, set low to start for rising edge

  attachInterrupt(digitalPinToInterrupt(hallSensor1), hallCount1, RISING); //enable the hall effect interupts
  attachInterrupt(digitalPinToInterrupt(hallSensor2), hallCount2, RISING); //enable the hall effect interupts

  Serial.begin(9600);
} // End setup

HallMotor motor1(SS_M1, DIR_M1, PWM_M1);
HallMotor motor2(SS_M2,DIR_M2, PWM_M2);

int distance1 = 12 * 279;

void loop() {
  //sync1();
  //extend1(distance1);
  retract1(0);
}//end void loop

void sync1(){
  countDifference1 = hallCount_motor1 - hallCount_motor2;
  countDifference2 = hallCount_motor2 - hallCount_motor1;
  if (countDifference1 > 5){
    motor1.speed = motor1.speed - 5;
  }
  else if(countDifference1 > 10){
    motor1.speed = motor1.speed - 10;
  }
  else if(countDifference1 > 15){
    motor1.speed = motor1.speed - 15;
  }
    else if(countDifference1 > 20){
    motor1.speed = motor1.speed - 20;
  }
  else{
    motor1.speed = 255;
  }
  if (countDifference2 > 5){
    motor2.speed = motor2.speed - 5;
  }
  else if(countDifference2 > 10){
    motor2.speed = motor2.speed - 10;
  }
  else if(countDifference2 > 15){
    motor2.speed = motor2.speed - 15;
  }
    else if(countDifference2 > 20){
    motor2.speed = motor2.speed - 20;
  }
  else{
    motor2.speed = 255;
  }
}

void extend1(int distance){
  if (hallCount_motor1 < distance) {

    motor1.extend(motor1.speed);
    motor2.extend(motor2.speed);    
  }
  else{
    hault();
  }
}

void retract1(int distance){
  /*
  if (hallCount_motor1 > distance) {
    motor1.extend(255);
  }
  else{
    motor1.hault();
  }
  */

  motor1.retract(255);
  motor2.retract(255);

}

void hault(){
    motor1.hault();
    motor2.hault();
}


void hallCount1(){
  if (motor1.direction1 == 0){
    hallCount_motor1 = hallCount_motor1 + 1;
    motor1.count = hallCount_motor1;
  }

  else{
    hallCount_motor1 = hallCount_motor1-1;
    motor1.count = hallCount_motor1;
  }
}

void hallCount2(){
  if (motor2.direction1 == 0){
    hallCount_motor2 = hallCount_motor2 + 1;
    motor2.count = hallCount_motor2;
  }

  else{
    hallCount_motor2 = hallCount_motor2-1;
    motor2.count = hallCount_motor2;
  }
}