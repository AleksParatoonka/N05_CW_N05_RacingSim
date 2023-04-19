#pragma once
#include "GroundVehicle.h"
class Camel :
    public GroundVehicle
{
public:
    Camel() :GroundVehicle(10, "Верблюд", 30) {}

    virtual double get_relax_time(int relax_count);
};

