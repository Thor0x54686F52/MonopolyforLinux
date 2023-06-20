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
        }
    }
    else {
        Money = Money+money;
    }
}

int Player::Move() {
    std::vector<int> dice = Player::Rolled_dice();
    if(prison) {
        Prison();
    }
    else {
        for(int i = 0; i < 3; i++) {
            Field = Field + dice[0] + dice[1];
            if(Field > 39) {
                Field = Field-39;
            }
            if(dice[0] != dice[1]) {
                break;
            }
            dice = Player::Rolled_dice();
            doublets++;
            std::cout << doublets << std::endl;
        }
    }
    
    if(doublets == 3 || Field == 30) {
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

std::vector<int> Player::Rolled_dice() {
    std::vector<int> dice_vector;
    dice_vector.push_back(Random(6) + 1);
    dice_vector.push_back(Random(6) + 1);
    return dice_vector;
}

int Player::Prison() {
    std::vector<int> dice = Player::Rolled_dice();
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

string Player::GetOwnerName() {
    return Name;
}