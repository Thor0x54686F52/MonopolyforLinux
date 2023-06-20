#include <string>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

#ifndef PLOTS_HPP
#define PLOTS_HPP

class Lots{
    private:
        int Field;
        string Owner = "";
        int price_of_Lot;
        int Price_of_House;
        std::vector<int> group;
        /*
          It takes the index of the street in the array from the street.
          If the player wants to build on one street, it takes the index of the other street(s) and looks what the owner of that street(s) is.
          If the player is the owner of all of that streets, he/she can build
        */
        string Streetname;
        int Rent;

    public:
        Lots();

        Lots(string name,int field, int price, int miete, int price_house, int group0, int group1 = 22);

        string return_Owner();

        int pay_Rent(string owner, string owner1, string owner2);

        void Buy(string buyer);

        int ret_price();

        int give_Field();
};

class power_plant{
    private:
        int Field;
        string Owner = "";
        int Group;
        string Name_of_power_plant;

    public:
        void allocation_values(int field, int group, string name);

        int Rent(int Wuerfelaugen, string schueldiger, string besitzer1, string besitzer2);

        string Besitzerrueckgabe();

        int give_Field();

        int ret_price();

        void Buy(string buyer);
};

class Train_Station{
    private:
        int Field;
        int Group[3];
        string Owner = "";
        string Train_station;

    public:
        void allocation_values(int field, int group0, int group1, int group2, string name);

        int Rent(string schueldiger, string owner0, string owner1, string owner2);

        string Besitzerrueckgabe();

        int ret_price();

        int give_Field();

        void Buy(string buyer);
};

std::array<Lots, 22> allocation_values_streets();

std::array<power_plant, 2> allocation_values_Werke();

std::array<Train_Station, 4> allocation_values_train_station();

void allocation_values();

std::array<int, 3> Check_field(int field);
/*
  First value can be 0, 1, 2, 3
   - 0 stands for Lots
   - 1 stands for power_plant
   - 2 stands for Train_Stations
   - 3 stands for nothing of them

  Second value stands if it's bought allready, if it can be bougt
   - 0 stands for "You can't buy it"
   - 1 stands for "You can buy it"

  Third value is the price, if it can be bougt
*/

#endif