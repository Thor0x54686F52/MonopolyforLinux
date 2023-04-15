#include "player.hpp"

void Player::Benennen(string name){
    Name = name;
}

void Player::Caught(bool caught){
    Prison = caught;
}

bool Player::Transaktion(int money){
    if(money < 0){
        money = money*(-1);
        if(money <= Money){
            Money = Money-money;
        }
        if(money > Money) {
            return false;
        }
    }
    else{
        Money = Money+money;
    }
    return true;
}

int Player::Bewegen(int forward){
    Field = Field+forward;
    if(Field > 39){
        Field = Field-39;
    }
    return Field;
}

string Player::Besitzerauslesen(){
    return Name;
}