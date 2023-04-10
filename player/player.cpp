#include "player.hpp"

void Player::Benennen(string name, int money, int field, bool prison){
    Name = name;
    Money = money;
    Field = field;
    Prison = prison;
}

void Player::Caught(bool caught){
    Prison = caught;
}

string Player::Transaktion(int money){
    if(money < 0){
        money = money*(-1);
        if(money < Money){
            Money = Money-money;
        }
        if(money > Money) {
            return "zu wenig Geld";
        }
    }
    else{
        Money = Money+money;
    }
    std::cout << "Der Kontostand beträgt: " << Money << "€" << std::endl;
    return "0";
}

int Player::Bewegen(int forward){
    Field = Field+forward;
    if(Field > 39){
        Field = Field-39;
    }
    return Field;
}

string Player::Besitzerauslesen(){
    std::cout << "Spielser.h 67 der Besitzer ist: " << Name << std::endl;
    return Name;
}