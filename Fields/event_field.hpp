#include <vector>
#include <string>
#include <array>
#include <iostream>
using namespace std;

#ifndef EVENT_FIELD_HPP
#define EVENT_FIELD_HPP

class Community_cest_Chance {
    private:
        string Text;
        int Money_transfer;//is for the money the player have to pay
        int Field;//is for the field which the player have to move
        int House;//is for the price of a house when it have to be renovateted
        int Hotel;//is for the price of a hotel when it have to be renovateted
    public:
        void Card_assignment(string text);

        void Hotels_House_values(int house, int hotel);

        void Moneytransfer(int money);

        void forward_backward(int field, int money);
        
        int Field_value();//gives back the fieldnummber where the player have to go. If the player comes over start, the player calls the funktion "Money()" which gives the player the money for coming over start

        int Money();

        string return_Text();
};

array<Community_cest_Chance, 16> Community_Chest();
array<Community_cest_Chance, 16> Chance();
#endif