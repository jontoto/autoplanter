#pragma once

class MoistureSensor {
private:
    /* data */
    int m_read_pin;
public:
    MoistureSensor(int read_pin);
    ~MoistureSensor() = default;

    int get_reading();
};
