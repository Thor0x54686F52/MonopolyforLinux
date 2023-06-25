#include <string>
#include <iostream>
#include "../Own_Random_Libary/own_random_libary.hpp"
#include "../Fields/plots.hpp"

//Max playernumber should be choosen by an dropdown-menue
#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player {
  private:
    std::string Name;
    int Money = 1500;
    int Field = 0;
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
    Player(std::string name);

    void Transaktion(int money);

    int Move();

    int Prison();

    std::string GetOwnerName();

    std::vector<int> Rolled_dice();
    /* the first returnvalue is the sum of the rolled Dices, the second value signals if it was a dice double or not. 
      0 stands for no dice double
      1 stands for a dice double
    */
};

std::vector<Player> Set_Player(int max_player); //There has to be set a vector in main for holding all players, has to be looked that in the game there don't get a new player pushed back

#endif