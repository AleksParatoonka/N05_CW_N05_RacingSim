#pragma once
#include "AirVehicle.h"
class Broom :
    public AirVehicle
{
public:
    Broom() :AirVehicle(20, "�����") {}
    virtual double get_reduction_factor(double distance);
};

