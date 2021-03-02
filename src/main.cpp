#include <iostream>
#include <chrono>
#include <thread>
#include <unistd.h>

#include "digital_pin.hpp"
#include "moisture_sensor.hpp"

int main(int argc, char** argv) { 
    MoistureSensor sensor(0, 0);
    DigitalPin red_light(25);
    DigitalPin green_light(24);

    for (int i = 0; i < 100; i++) {
        int value = sensor.get_reading();
        std::cout << "moisture sensor reads: " << value << std::endl;
        if (value < 200) {
            red_light.turn_on();
            green_light.turn_off();
        } else {
            red_light.turn_off();
            green_light.turn_on();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    return 0;
}
