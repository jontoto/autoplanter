#pragma once

#include <stdint.h>

// Define a wrapper class to control interfacing with the MCP3008 ADC

class ADCMcp3008 {
 private:
    // The adc communicates using 10-bits so need a buffer of length 2
    // plus one bit to send the start signal
    uint8_t m_buffer[3];
    int m_spi_channel = 0;
    int m_spi_fd;

 public:
    ADCMcp3008(int spi_channel, int clock_speed);
    ~ADCMcp3008();

    uint32_t read_channel(uint8_t channel);
};