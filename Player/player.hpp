#include <string>
#include <iostream>
using namespace std;

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player{
    private:
        string Name;
        int Money = 1500;
        int Field = 0;
        int House = 0;
        int Hotel = 0;
        bool Prison = false;

    public:
        void Benennen(string name);

        void Caught(bool caught);

        bool Transaktion(int money); //true = enove money; false = not enove mony

        int Bewegen(int forward);

        string Besitzerauslesen();
};

#endif