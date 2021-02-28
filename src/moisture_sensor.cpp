#include<iostream>
#include<wiringPi.h>

#include"moisture_sensor.hpp" 

MoistureSensor::MoistureSensor(int read_pin) : m_read_pin{read_pin} {
    wiringPiSetup();
    pinMode(m_read_pin, OUTPUT);
}

int MoistureSensor::get_reading() {
    int status = digitalRead(m_read_pin);
    return status;
}
