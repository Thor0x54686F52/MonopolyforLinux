#include "gesammelte_Header.hpp"
using namespace std;

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player{
    private:
        string Name;
        int Money;
        int Field;
        int House;
        int Hotel;
        bool Prison;

    public:
        void Benennen(string name, int money, int field, bool prison);

        void Caught(bool caught);

        string Transaktion(int money);

        int Bewegen(int forward);

        string Besitzerauslesen(); return Name;
};

#endif