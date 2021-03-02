
#include <iostream>
#include <stdint.h>
#include <unistd.h>
#include <wiringPiSPI.h>

#include "adc_mcp3008.hpp"

ADCMcp3008::ADCMcp3008(int spi_channel, int clock_speed) {
    m_spi_channel = spi_channel;
    m_spi_fd = wiringPiSPISetup(m_spi_channel, clock_speed);
    if (m_spi_fd == -1) {
        // TODO: error out or something
        std::cout << "WARNING::Unable to setup SPI!" << std::endl;
    }
}
ADCMcp3008::~ADCMcp3008() {
    close(m_spi_fd);
}

uint32_t ADCMcp3008::read_channel(uint8_t analog_channel) {
    if (analog_channel >= 8) {
        std::cout << "ERROR " << analog_channel << "is out of bounds for this chip" << std::endl;
        return 0;
    }
    // first byte starts the ADC
    m_buffer[0] = 1;

    // second byte tells it which mode / channel to use
    // assume single-ended
    m_buffer[1] = 0;
    // Run in single ended mode
    m_buffer[1] |= (1 << 7);
    // The next 3 bits define which of the 8 channels are sampled
    m_buffer[1] |= (analog_channel << 4);

    wiringPiSPIDataRW(m_spi_channel, m_buffer, 3);

    uint32_t result = (m_buffer[1] & 3) << 8;
    result |= m_buffer[2];
    return result;
}