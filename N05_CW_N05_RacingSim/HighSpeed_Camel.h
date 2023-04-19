#pragma once
#include "GroundVehicle.h"
class HighSpeed_Camel :
    public GroundVehicle
{
public:
    HighSpeed_Camel() :GroundVehicle(40, "ֱûסענûי גונבכ‏ה", 10) {}
    virtual double get_relax_time(int relax_count);
};

