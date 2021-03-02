cmake_minimum_required(VERSION 3.10)

# set the project name
project(autoplanter)
set(CMAKE_CXX_STANDARD 11)

# add the executable
add_executable(autoplanter src/main.cpp 
               src/moisture_sensor.cpp
               src/digital_pin.cpp 
               src/adc_mcp3008.cpp)
target_link_libraries(autoplanter wiringPi)

target_include_directories(autoplanter PUBLIC include)    