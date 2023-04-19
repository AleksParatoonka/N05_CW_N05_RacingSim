#pragma once
#include "AirVehicle.h"
class Eagle :
    public AirVehicle
{
public:
    Eagle() :AirVehicle(8, "Орел") {}
    virtual double get_reduction_factor(double distance);
};

