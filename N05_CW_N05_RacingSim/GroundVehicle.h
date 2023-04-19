#pragma once
#include "Vehicle.h"

class GroundVehicle :
    public Vehicle
{
protected:
    double before_relax_time;
public:
    GroundVehicle(double speed_, std::string name_, double before_relax_time_) :Vehicle(speed_, name_) {
        before_relax_time = before_relax_time_;
        type = 1;
    }
    virtual double get_relax_time(int relax_count);
    double calculate_time(double distance) override;
};

