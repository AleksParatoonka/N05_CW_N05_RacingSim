#pragma once
#include "GroundVehicle.h"
class AllTerrain_Boots :
    public GroundVehicle
{
public:
    AllTerrain_Boots() :GroundVehicle(6, "�������-���������", 60) {}
    virtual double get_relax_time(int relax_count);
};

