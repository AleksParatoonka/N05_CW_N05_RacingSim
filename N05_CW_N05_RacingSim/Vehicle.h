#pragma once
#include <iostream>

class Vehicle
{
protected:
    int num = 0;
    double speed;
    double time;
    int type;
    std::string name;

public:
    Vehicle() {
        name = " ";
    }
    Vehicle(double speed_, std::string name_) {
        speed = speed_;
        name = name_;
    }

    virtual double calculate_time(double distance);
    double get_time();
    std::string get_name();
    int get_num();
};

