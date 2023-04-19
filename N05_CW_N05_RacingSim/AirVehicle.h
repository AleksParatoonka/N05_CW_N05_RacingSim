#pragma once
#include "Vehicle.h"

class AirVehicle :
    public Vehicle
{
public:
    AirVehicle(double speed_, std::string name_) : Vehicle(speed_, name_) {
        type = 2;
    }

    virtual double get_reduction_factor(double distance);

    double calculate_time(double distance) override;
};

