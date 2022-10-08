#include "gesammelte_Header.hpp"
using namespace std;

class Spieler{
private:
    string Name;
    int Money;
    int Field;
    int House;
    int Hotel;
    bool Prison;

public:
    void Benennen(string name, int money, int field, bool prison){
        Name = name;
        Money = money;
        Field = field;
        Prison = prison;
    }

    void Caught(bool caught){
        Prison = caught;
    }

    string Transaktion(int money){
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
        cout << "Der Kontostand beträgt: " << Money << "€" << endl;
        return "0";
    }

    int Bewegen(int forward){
        Field = Field+forward;
        if(Field > 39){
            Field = Field-39;
        }
        return Field;
    }

    string Besitzerauslesen(){
        cout << "Spielser.h 67 der Besitzer ist: " << Name << endl;
        return Name;
    }
};
