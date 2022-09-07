#include "HallMotor.h"
#include "Arduino.h"
#include "SPI.h"

HallMotor::HallMotor(int ss_pin, int dir_pin, int pwm_pin) {

  int speed;
  bool direction1;
  volatile int count;

  //Connecting Public and Private Variables
  _ss_pin = ss_pin;
  _dir_pin = dir_pin;
  _pwm_pin = pwm_pin;
}
    void HallMotor::hault(){
      speed = 0;
      analogWrite(_pwm_pin, speed);
    }
    
    void HallMotor::retract(int speed){
      direction1 = 1;
      digitalWrite(_dir_pin,direction1);
      analogWrite(_pwm_pin,speed);
    }

    void HallMotor::extend(int speed){
      direction1 = 0;
      digitalWrite(_dir_pin, direction1);
      analogWrite(_pwm_pin, speed);  
     }
    
    void HallMotor::calibrate(){
      
    }