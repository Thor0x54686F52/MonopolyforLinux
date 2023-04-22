#include <string>
#include <array>
#include <iostream>

using namespace std;

#ifndef PLOTS_HPP
#define PLOTS_HPP

class Grundstueke{ //dient zur Nummerierung und zuweisung der Grundstücke zu den einzelnen Spielern
    private:
        int Field;
        string Besitzer = "";
        int Preis_Grundstuek;
        int Preis_Haus;
        std::vector group;
        /*
          It takes the index of the street in the array from the street.
          If the player wants to build on one street, it takes the index of the other street(s) and looks what the owner of that street(s) is.
          If the player is the owner of all of that streets, he/she can build
        */
        string Strasenname;
        int Miete;

    public:
        Grundstueke(string Name,int field, int preis, int miete, int preis_haus, int gruppe0, int gruppe1);

        string Besitzerrueckgabe();

        int Miete_zahlen(string besitzer, string besitzer1, string besitzer2);
};

class Werke{
    private:
        int Field;
        string Besitzer = "";
        int group;
        string Werkname;

    public:
        void allocation_values(int field, int gruppe, string Name);

        int miete(int Wuerfelaugen, string schueldiger, string besitzer1, string besitzer2);

        string Besitzerauslesen();
};

class Train_Station{
    private:
        int Field;
        int Gruppe[3];
        string Besitzer="";
        string train_station;

    public:
        void allocation_values(int field, int gruppe0, int gruppe1, int gruppe2, string Name);

        int Miete(string schueldiger, string Besitzer0, string Besitzer1, string Besitzer2);

        string Besitzerauslesen();
};

Grundstueke Strasen[22];
Werke Kraftwerke[2];
Train_Station train_station[4];

void allocation_values_streets();

void allocation_values_Werke();

void allocation_values_train_station();

void allocation_values();

#endif