#pragma once

#include <memory>

#include "adc_mcp3008.hpp"
#include "digital_pin.hpp"

#define SPI_FREQUENCY_HZ 10000
#define SPI_CHANNEL_ID 0

class MoistureSensor {
private:
    std::shared_ptr<DigitalPin> m_power;
    std::shared_ptr<ADCMcp3008> m_reader;
    int m_analog_channel;

public:
    MoistureSensor(int power_pin, int analog_channel);
    ~MoistureSensor() = default;

    int get_reading();
};
