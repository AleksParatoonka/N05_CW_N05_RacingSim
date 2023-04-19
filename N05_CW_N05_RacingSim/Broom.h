#pragma once
#include "AirVehicle.h"
class Broom :
    public AirVehicle
{
public:
    Broom() :AirVehicle(20, "Метла") {}
    virtual double get_reduction_factor(double distance);
};

