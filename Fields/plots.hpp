#include <string>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

#ifndef PLOTS_HPP
#define PLOTS_HPP

class Grundstueke{ //dient zur Nummerierung und zuweisung der Grundstücke zu den einzelnen Spielern
    private:
        int Field;
        string Owner = "";
        int Preis_Grundstuek;
        int Preis_Haus;
        std::vector<int> group;
        /*
          It takes the index of the street in the array from the street.
          If the player wants to build on one street, it takes the index of the other street(s) and looks what the owner of that street(s) is.
          If the player is the owner of all of that streets, he/she can build
        */
        string Strasenname;
        int Miete;

    public:
        Grundstueke();

        Grundstueke(string Name,int field, int preis, int miete, int preis_haus, int gruppe0, int gruppe1);

        string Besitzerrueckgabe();

        int Miete_zahlen(string besitzer, string besitzer1, string besitzer2);

        void Buy(string buyer);

        int ret_price();

        int give_Field();
};

class Werke{
    private:
        int Field;
        string Owner = "";
        int group;
        string Werkname;

    public:
        void allocation_values(int field, int gruppe, string Name);

        int miete(int Wuerfelaugen, string schueldiger, string besitzer1, string besitzer2);

        string Besitzerrueckgabe();

        int give_Field();

        int ret_price();

        void Buy(string buyer);
};

class Train_Station{
    private:
        int Field;
        int Gruppe[3];
        string Owner="";
        string train_station;

    public:
        void allocation_values(int field, int gruppe0, int gruppe1, int gruppe2, string Name);

        int Miete(string schueldiger, string Besitzer0, string Besitzer1, string Besitzer2);

        string Besitzerrueckgabe();

        int ret_price();

        int give_Field();

        void Buy(string buyer);
};

std::array<Grundstueke, 22> allocation_values_streets();

std::array<Werke, 2> allocation_values_Werke();

std::array<Train_Station, 4> allocation_values_train_station();

void allocation_values();

std::array<int, 3> Check_field(int field);
/*
  First value can be 0, 1, 2, 3
   - 0 stands for Grundstueke
   - 1 stands for Werke
   - 2 stands for Train_Stations
   - 3 stands for nothing of them

  Second value stands if it's bought allready, if it can be bougt
   - 0 stands for "You can't buy it"
   - 1 stands for "You can buy it"

  Third value is the price, if it can be bougt
*/

#endif