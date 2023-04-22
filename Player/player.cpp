#include "player.hpp"

Player::Player(string name) {
    Name = name;
}

void Player::Transaktion(int money) {
    if(money < 0) {
        money = money*(-1);
        if(money <= Money){
            Money = Money-money;
        }
        if(money > Money) {
            std::cout << "To less money" << std::endl;
            return;
        }
    }
    else {
        Money = Money+money;
    }
    return;
}

int Player::Bewegen() {
    if(prison) {
        Prison();
    }

    std::vector<int> dice = Rolling_Dice();
    for(int i = 0; i < 3; i++) {
        Field = Field + dice[0] + dice[1];
        if(Field > 39) {
            Field = Field-39;
        }
        if(dice[0] != dice[1]) {
            break;
        }
        dice = Rolling_Dice();
        doublets++;
        std::cout << doublets << std::endl;
    }
    if(doublets == 3) {
        prison = true;
    }
    else {
        doublets = 0;
    }

    if(prison) {
        Field = 10; //The prison is on the field 10
    }
    return Field;
}

int Player::Rolled_dice() {
    return doublets;
}

int Player::Prison() {
    std::vector<int> dice = Rolling_Dice();
    if(dice[0] == dice[1]) {
        prison = false;
    }
    else {
        doublets++;
    }
    if (doublets == 6) {// the three changes to come out free with a doublet are over, if this variable is 6, so the player has to pay 50€
        Transaktion(50);
        doublets = 0;
    }
    
    return dice[0] + dice[1];
}

string Player::Besitzerauslesen() {
    return Name;
}