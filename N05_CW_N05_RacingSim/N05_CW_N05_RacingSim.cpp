// N05_CW_N05_RacingSim.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <windows.h>

#include "Race.h"
#include "Vehicle.h"
#include "ResultVehicle.h"

#include "GroundVehicle.h"
#include "Camel.h"
#include "HighSpeed_Camel.h"
#include "Centaur.h"
#include "AllTerrain_Boots.h"

#include "AirVehicle.h"
#include "FlyingCarpet.h"
#include "Eagle.h"
#include "Broom.h"

//-------------------------------------------- Vehicle -------------------------------------------------

/*class Vehicle {
protected:
    int num = 0;
    double speed;
    double time;
    int type;
    std::string name;

public:
    Vehicle() {
        name = " ";
    }
    Vehicle(double speed_, std::string name_) {
        speed = speed_;
        name = name_;
    }
    
    virtual double calculate_time(double distance) { if (speed > 0) return distance/speed; }
    double get_time() { return time; }
    std::string get_name() { return name; }
    //const std::string& get_name() const get_name() { return name; }
    int get_num() { return num; }
};*/

//-------------------------------------------- ResultVehicle -------------------------------------------------

/*class ResultVehicle :public Vehicle {
public:
    ResultVehicle() : Vehicle() {}
    ResultVehicle(int n, double time_, std::string name_) : Vehicle() {
        num = n;
        time = time_;
        name = name_;
    }
};*/

//-------------------------------------------- GroundVehicle -------------------------------------------------

/*class GroundVehicle :public Vehicle {
protected:
    double before_relax_time;
public:
    GroundVehicle(double speed_, std::string name_, double before_relax_time_) :Vehicle(speed_, name_) {
        before_relax_time = before_relax_time_;
        type = 1;
    }
    virtual double get_relax_time(int relax_count) {
        double relax_time = 0;
        return relax_time;
    }

    double calculate_time(double distance) override {
        if (speed > 0) {
            double time = distance / speed;
            int relax_count = 0;
            if (before_relax_time != 0) {
                int relax_count = static_cast<int>(time / before_relax_time);
            }
            
            if (relax_count == 0) {
                return time;
            }
            else {
                time = fmod(time, before_relax_time);
                for (int i = 1; i <= relax_count; i++) {
                    time += (before_relax_time + get_relax_time(i));
                }
                return time;
            }
        }
    }
};*/
/*class Camel :public GroundVehicle {

public:
    Camel() :GroundVehicle(10, "Верблюд", 30) {}

    virtual double get_relax_time(int relax_count) {
        double relax_time = 0;
        switch (relax_count) {
            case 1:
                relax_time = 5;
                break;
            default:
                relax_time = 8;
                break;
        }
        return relax_time;
    }
};
class HighSpeed_Camel :public GroundVehicle {
public:
    HighSpeed_Camel() :GroundVehicle(40, "Быстрый верблюд", 10) {}
    virtual double get_relax_time(int relax_count) {
        double relax_time = 0;
        switch (relax_count) {
        case 1:
            relax_time = 5;
            break;
        case 2:
            relax_time = 6.5;
            break;
        default:
            relax_time = 8;
            break;
        }
        return relax_time;
    }
};
class Centaur :public GroundVehicle {
public: 
    Centaur() :GroundVehicle(15, "Кентавр", 8) {}
    virtual double get_relax_time(int relax_count) {
        double relax_time = 2;
        return relax_time;
    }
};
class AllTerrain_Boots :public GroundVehicle {
public:
    AllTerrain_Boots() :GroundVehicle(6, "Ботинки-вездеходы", 60) {}
    virtual double get_relax_time(int relax_count) {
        double relax_time = 0;
        switch (relax_count) {
        case 1:
            relax_time = 10;
            break;
        default:
            relax_time = 5;
            break;
        }
        return relax_time;
    }
};*/

//-------------------------------------------- AirVehicle -------------------------------------------------

/*class AirVehicle :public Vehicle {
public:
    AirVehicle(double speed_, std::string name_) : Vehicle(speed_, name_) {
        type = 2;
    }
    
    virtual double get_reduction_factor(double distance)  {
        double reduction_factor = 0.0;
        
        return reduction_factor;
    }

    double calculate_time(double distance) override {
        double time = 0.0;
        if (speed > 0) {
            time = distance *(1 - get_reduction_factor(distance)) / speed;
            //time =  get_reduction_factor(distance);
        }
        return time;
    }
};*/
/*class FlyingCarpet :public AirVehicle {
public:
    FlyingCarpet() :AirVehicle(10, "Ковер-самолет") {}

    virtual double get_reduction_factor(double distance) {
        double reduction_factor = 0.0;
        if (distance >= 10000) {
            reduction_factor = 0.05;
        }
        else if (distance < 10000 && distance >= 5000) {
            reduction_factor = 0.1; 
        }
        else if (distance < 5000 && distance >= 1000) {
            reduction_factor = 0.03;
        }
        else {
            reduction_factor = 0.0;
        }
        return reduction_factor;
    }
};
class Eagle :public AirVehicle {
public:
    Eagle() :AirVehicle(8, "Орел") {
       
    }
    virtual double get_reduction_factor(double distance) {
        double reduction_factor = 0.06;
        return reduction_factor;
    }
};
class Broom :public AirVehicle {  
public:
    Broom() :AirVehicle(20, "Метла") {}
    virtual double get_reduction_factor(double distance) {
        double reduction_factor = 0.0;
        reduction_factor = (static_cast<int>(distance/1000)) * 0.01;
        //reduction_factor = (distance / 1000)*0.01;
        return reduction_factor;
    }
};*/

//-------------------------------------------- Races -------------------------------------------------

/*class Race {
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
    int get_max() { return max_count; }
    int get_registration_count() { return registration_count; }
    void add_registration_count(int increment) { registration_count += increment; }
    void get_winner() {
        bool numb_swap;
        do {
            numb_swap = 0;
            for (int i = 1; i < registration_count; i++) {
                if (vehicle_array[i - 1].get_time() > vehicle_array[i].get_time()) {
                    ResultVehicle tmp = vehicle_array[i - 1];
                    vehicle_array[i - 1] = vehicle_array[i];
                    vehicle_array[i] = tmp;
                    numb_swap = 1;
                }
            }
        } while (numb_swap);
    }
};*/

void print_results(Race* ptr) {
    std::cout << "Результаты гонки: " << std::endl;
    int i = 1;
    ptr->vehicle_array[0].get_name();
    for (ResultVehicle v : ptr->vehicle_array) {
        if (v.get_name() != " ") {
            std::cout << i << ". " << v.get_name() << ". Время: " << v.get_time() << std::endl;
        }
        i++;
    }
}

void registration(Race* ptr) {
    int input;
    bool registration_break = false;

    do {
        std::cout << "\n Должно быть зарегистрировано не менее 2х транспортных средств: " << std::endl;
        std::cout << "1. Зарегистрировать транспорт" << std::endl;
        std::cout << "2. Прервать регистрацию" << std::endl;
        std::cout << "Введите действие: ";
        std::cin >> input;
        if (input == 2) {
            registration_break = true;
            continue;
        }
        // -- registration -- 

        int registration_input = -1;
        bool vehicle_registration = 1;
        registration_input = -1;
        std::cout << std::endl;
        std::cout << "1. Верблюд" << std::endl;
        std::cout << "2. Верблюд-скороход" << std::endl;
        std::cout << "3. Кентавр" << std::endl;
        std::cout << "4. Ботинки-вездеходы" << std::endl;
        std::cout << "5. Ковер-самолет" << std::endl;
        std::cout << "6. Орел" << std::endl;
        std::cout << "7. Метла" << std::endl;
        std::cout << "0. Закончить регистрацию" << std::endl;
        do {
            std::cin >> registration_input;
            if (registration_input == 0) {
                vehicle_registration = 0;
            }
            if (registration_input > 0) {
                bool exists = false;
                for (int i = 0; i < 7; i++) {
                    if (ptr->vehicle_array[i].get_num() == registration_input) {
                        std::cout << "Участник " << registration_input << " " << ptr->vehicle_array[i].get_name() << " уже зарегистрирован" << std::endl;
                        exists = true;
                        break;
                    }
                }
                if (exists == true) {
                    std::cout << "Выберите другого участника или закончите регистрацию" << std::endl;
                    continue;
                }

                switch (registration_input) {
                case 1:
                {
                    if (ptr->type != 2) {
                        Camel c1;
                        //std::cout << c1.calculate_time(ptr->distance) << " ghg " << std::endl;
                        ResultVehicle v1(registration_input, c1.calculate_time(ptr->distance), c1.get_name());
                        ptr->vehicle_array[ptr->get_registration_count()] = v1;
                        ptr->add_registration_count(1);
                    }
                    else {
                        std::cout << "Участник не может быть зарегистрирован на гонку этого типа. Выберите другого участника или закончите регистрацию" << std::endl;
                    }
                }
                break;
                case 2:
                {
                    if (ptr->type != 2) {
                        HighSpeed_Camel c2;
                        ResultVehicle v2(registration_input, c2.calculate_time(ptr->distance), c2.get_name());
                        ptr->vehicle_array[ptr->get_registration_count()] = v2;
                        ptr->add_registration_count(1);
                    }
                    else {
                        std::cout << "Участник не может быть зарегистрирован на гонку этого типа. Выберите другого участника или закончите регистрацию" << std::endl;
                    }
                }
                break;
                case 3:
                {
                    if (ptr->type != 2) {
                        Centaur c3;
                        ResultVehicle v3(registration_input, c3.calculate_time(ptr->distance), c3.get_name());
                        ptr->vehicle_array[ptr->get_registration_count()] = v3;
                        ptr->add_registration_count(1);
                    }
                    else {
                        std::cout << "Участник не может быть зарегистрирован на гонку этого типа. Выберите другого участника или закончите регистрацию" << std::endl;
                    }
                }
                break;
                case 4:
                {
                    if (ptr->type != 2) {
                        AllTerrain_Boots c4;
                        ResultVehicle v4(registration_input, c4.calculate_time(ptr->distance), c4.get_name());
                        ptr->vehicle_array[ptr->get_registration_count()] = v4;
                        ptr->add_registration_count(1);
                    }
                    else {
                        std::cout << "Участник не может быть зарегистрирован на гонку этого типа. Выберите другого участника или закончите регистрацию" << std::endl;
                    }
                }
                break;
                case 5:
                {
                    if (ptr->type != 1) {
                        FlyingCarpet c5;
                        //std::cout << "FlyingCarpet " << c5.calculate_time(ptr->distance) << std::endl;
                        ResultVehicle v5(registration_input, c5.calculate_time(ptr->distance), c5.get_name());
                        ptr->vehicle_array[ptr->get_registration_count()] = v5;
                        ptr->add_registration_count(1);
                    }
                    else {
                        std::cout << "Участник не может быть зарегистрирован на гонку этого типа. Выберите другого участника или закончите регистрацию" << std::endl;
                    }
                }
                break;
                case 6:
                {
                    if (ptr->type != 1) {
                        Eagle c6;
                        ResultVehicle v6(registration_input, c6.calculate_time(ptr->distance), c6.get_name());
                        ptr->vehicle_array[ptr->get_registration_count()] = v6;
                        ptr->add_registration_count(1);
                    }
                    else {
                        std::cout << "Участник не может быть зарегистрирован на гонку этого типа. Выберите другого участника или закончите регистрацию" << std::endl;
                    }
                }
                break;
                case 7:
                {
                    if (ptr->type != 1) {
                        Broom c7;
                        //std::cout << "Broom " << c7.calculate_time(ptr->distance) << std::endl;
                        ResultVehicle v7(registration_input, c7.calculate_time(ptr->distance), c7.get_name());
                        ptr->vehicle_array[ptr->get_registration_count()] = v7;
                        ptr->add_registration_count(1);
                    }
                    else {
                        std::cout << "Участник не может быть зарегистрирован на гонку этого типа. Выберите другого участника или закончите регистрацию" << std::endl;
                    }
                }
                break;
                }
                std::cout << "Вы зарегистрировали: ";
                for (ResultVehicle v : ptr->vehicle_array) {
                    if (v.get_name() != " ") {
                        std::cout << v.get_name() << " ";
                    }
                }
                std::cout << std::endl;
            }
        } while (vehicle_registration != 0 && ptr->get_registration_count() != ptr->get_max());

        if (ptr->get_registration_count() < 2) {
            std::cout << "Вы зарегистрировали меньше 2х участников" << std::endl;
        }
        else {
            registration_break = true;
        }

    } while (registration_break != 1);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;

    bool end = 0;
    do {
        int race_type, distance, start_input, end_input=1;
     
        std::cout << "1. Гонка наземного типа\n";
        std::cout << "2. Гонка воздушного типа\n";
        std::cout << "3. Гонка наземного и воздушного типа" << std::endl;
        std::cout << "Введите тип гонки: ";
        std::cin >> race_type;
        std::cout << "Укажите длину дистанции: ";
        std::cin >> distance;

        // ------ Create RACE -----
        
        Race race1(distance, race_type);
        Race* par_race1 = &race1;

        switch (race_type) {
        case 1:
            std::cout << "\n Гонка наземного типа. Дистанция ";
            break;
        case 2:
            std::cout << "\n Гонка воздушного типа. Дистанция ";
            break;
        case 3:
            std::cout << "\n Гонка наземного и воздушного типа. Дистанция ";
            break;
        }
        std::cout << distance << std::endl;

        // ------ registration ------

        registration(par_race1);

        // ------ After registration ------
        
        if (race1.get_registration_count() >= 2 && race1.get_registration_count() < race1.get_max()) {
            std::cout << "\n1. Начать гонку" << std::endl;
            std::cout << "2. Зарегистрировать еще участников" << std::endl;
            std::cin >> start_input;

            switch (start_input) {
            case 1:
                race1.get_winner();
                print_results(par_race1);
                break;
            case 2:
                registration(par_race1);
                race1.get_winner();
                print_results(par_race1);
                break;
            }
        }
        else if (race1.get_registration_count() == race1.get_max()) {
            race1.get_winner();
            print_results(par_race1);
        }
        else {
            std::cout << "Недостаточное количество участников!!!" << std::endl;
        }
        
        // ------ After RACE ------

        std::cout << "\n1. Провести еще одну гонку" << std::endl ;
        std::cout << "2. Выйти" << std::endl;
        std::cout << "Введите действие: ";
        std::cin >> end_input;
        if (end_input == 2) {
            end = 1;
        }
    } while (end != 1);
}