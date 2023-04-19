#pragma once
#include "Vehicle.h"

class ResultVehicle :
    public Vehicle
{
public:
    ResultVehicle() : Vehicle() {}
    ResultVehicle(int n, double time_, std::string name_) : Vehicle() {
        num = n;
        time = time_;
        name = name_;
    }
};

