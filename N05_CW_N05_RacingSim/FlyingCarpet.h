#pragma once
#include "AirVehicle.h"
class FlyingCarpet :
    public AirVehicle
{
public:
    FlyingCarpet() :AirVehicle(10, "Ковер-самолет") {}

    virtual double get_reduction_factor(double distance);
};

