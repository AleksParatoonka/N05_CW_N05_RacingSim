#pragma once
#include "Vehicle.h"
#include "ResultVehicle.h"

class Race
{
private:
    int max_count = 7;
    int registration_count = 0;

public:
    double distance;
    int type;
    ResultVehicle vehicle_array[7];

    Race(double distance_, int type_) {
        distance = distance_;
        type = type_;
        switch (type) {
        case 1:
            max_count = 4;
            break;
        case 2:
            max_count = 3;
            break;
        case 3:
            max_count = 7;
            break;
        }
    }
    int get_max();
    int get_registration_count();
    void add_registration_count(int increment);
    void get_winner();

};

