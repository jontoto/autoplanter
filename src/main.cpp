#include <iostream>
#include "moisture_sensor.hpp"

int main(int argc, char** argv) { 

    MoistureSensor sensor(2);
    std::cout << "moisture sensor reading " 
              << sensor.get_reading() << std::endl;
    return 0;
}
