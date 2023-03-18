#include "gesammelte_Header.hpp"
using namespace std;

class Community_cest_Chance {
private:
    string text;
    int money_transfer;//is for the money the player have to pay
    int field;//is for the field which the player have to move
    int house;//is for the price of a house when it have to be renovateted
    int hotel;//is for the price of a hotel when it have to be renovateted
public:
    void Kartenzuweisung(string Text){
        text = Text;
    }
    void Hotels_House_values(int House, int Hotel){
        house = House;
        hotel = Hotel;
    }
    void Money_transfer(int money){
        money_transfer = money;
    }
    void forward_backward(int Field, int money){
        field = Field;
        money_transfer = money;
    }
    
    int Field_value(){//gives back the Fieldnummber where the player have to go. If the player comes over start, the player calls the funktion "Money()" which gives the player the money for coming over start
        return field;
    }
    int Money(){
        return 200;
    }
    string Text(){
        return text;
    }
};

vector<int> Mix(vector<int> ToMix);