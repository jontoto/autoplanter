#include <iostream>
#include <wiringPi.h>

#include "digital_pin.hpp"

DigitalPin::DigitalPin(int ctrl_pin) : m_ctrl_pin{ctrl_pin} {
    wiringPiSetup();
    pinMode(m_ctrl_pin, OUTPUT);
}

DigitalPin::~DigitalPin() {
    // Make sure that the pin is off when the light controller is off
    digitalWrite(m_ctrl_pin, LOW);
}

void DigitalPin::turn_on() {
    std::cout << "turning on " << m_ctrl_pin << std::endl;
    digitalWrite(m_ctrl_pin, HIGH);
}

void DigitalPin::turn_off() {
    std::cout << "turning off " << m_ctrl_pin << std::endl;
    digitalWrite(m_ctrl_pin, LOW);
}
