#include <iostream>
#include <wiringPi.h>

#include "led_light.hpp"

LedLight::LedLight(int ctrl_pin) : m_ctrl_pin{ctrl_pin} {
    wiringPiSetup();
    pinMode(m_ctrl_pin, OUTPUT);
}

void LedLight::turn_on() {
    std::cout << "turning on " << m_ctrl_pin << std::endl;
    digitalWrite(m_ctrl_pin, HIGH);
}

void LedLight::turn_off() {
    std::cout << "turning off " << m_ctrl_pin << std::endl;
    digitalWrite(m_ctrl_pin, LOW);
}