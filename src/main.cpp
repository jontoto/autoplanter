#include <iostream>
#include <unistd.h>
#include "moisture_sensor.hpp"
#include "led_light.hpp"

int main(int argc, char** argv) { 

    // MoistureSensor sensor(3);
    // std::cout << "moisture sensor reading " 
    //           << sensor.get_reading() << std::endl;
    LedLight red_light(0);
    for (int i = 0; i < 10; i++) {
        red_light.turn_on();
        sleep(1);
        red_light.turn_off();
        sleep(1);
    }
    
    return 0;
}
