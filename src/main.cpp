#include<iostream>
#include <wiringPi.h>

int main(int argc, char** argv) { 
    wiringPiSetup();

    // pinMode(0, OUTPUT);
    pinMode(1, INPUT);

    int status = digitalRead(1);
    std::cout << "pin 1 = " << status << std::endl;
    return 0;
}
