#pragma once
#include "AirVehicle.h"
class Eagle :
    public AirVehicle
{
public:
    Eagle() :AirVehicle(8, "����") {}
    virtual double get_reduction_factor(double distance);
};

