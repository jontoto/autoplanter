#pragma once

class LedLight {
 private:
    int m_ctrl_pin;
 public:
    LedLight(int ctrl_pin);
    ~LedLight() = default;

    void turn_on();
    void turn_off();
};