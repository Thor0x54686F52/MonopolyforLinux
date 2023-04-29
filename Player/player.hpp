#include <string>
#include <iostream>
#include "../Own_Random_Libary/own_random_libary.hpp"
using namespace std;

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player {
    private:
        string Name;
        int Money = 1500;
        int Field = 0;
        int House = 0;
        int Hotel = 0;
        int doublets = 0;
        /*
          Every time the player rolls a doublets (both dices has the same nunber), this variable gets increased by one one.
          If the player roll three doublets in a row the player has to go to the prison.
          There he/she gets every round one chance to roll a douplet to come free.
          If the player don't roll a doublet he/she has to pay 50€

          0-3 if the player rolles a doublet. After that the player is in prison
          4-6 the player is in prison and the player don't roll a doublet the number gets increased by one
        */
        bool prison = false; 

    public:
        Player(string name);

        int Prison();

        void Transaktion(int money);

        int Bewegen();

        string Besitzerauslesen();

        int Rolled_dice();
};

#endif