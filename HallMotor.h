#ifndef HallMotor_h
#define HallMotor_h

#include <Arduino.h>

class HallMotor {
  public:
    HallMotor(int ss_pin, int dir_pin, int pwm_pin);
    void retract(int speed);
    void extend(int speed);
    void hault();
    void countHall();
    void calibrate();

    int endPoint;
    int speed;
    volatile int count;
    bool direction1;

  private:
    //pin variables
    int _ss_pin;
    int _dir_pin;
    int _pwm_pin;
    int _hall_pin;
};

#endif