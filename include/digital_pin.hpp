#pragma once

class DigitalPin {
 private:
    int m_ctrl_pin;
 public:
    DigitalPin(int ctrl_pin);
    ~DigitalPin();

    void turn_on();
    void turn_off();
};