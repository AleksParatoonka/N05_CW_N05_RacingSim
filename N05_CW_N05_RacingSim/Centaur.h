#pragma once
#include "GroundVehicle.h"
class Centaur :
    public GroundVehicle
{
public:
    Centaur() :GroundVehicle(15, "Кентавр", 8) {}
    virtual double get_relax_time(int relax_count);
};

