#include <chrono>
#include <memory>
#include <thread>

#include "adc_mcp3008.hpp"
#include "digital_pin.hpp"
#include "moisture_sensor.hpp" 

MoistureSensor::MoistureSensor(int power_pin, int analog_channel) : m_analog_channel{analog_channel} {
    m_power = std::make_shared<DigitalPin>(power_pin);
    m_reader = std::make_shared<ADCMcp3008>(SPI_CHANNEL_ID, SPI_FREQUENCY_HZ);
}

int MoistureSensor::get_reading() {
    m_power->turn_on();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    uint32_t sensor_value = m_reader->read_channel(m_analog_channel);
    // Turn off the power pin so the sensor doesn't corrode
    m_power->turn_off();
    return (int) sensor_value;
}
