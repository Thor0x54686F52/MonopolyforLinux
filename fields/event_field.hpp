#include <vector>
#include <string>
#include <array>
#include <time.h>
#include <random>
#include <iostream>
using namespace std;

#ifndef EVENT_FIELD_HPP
#define EVENT_FIELD_HPP

class Community_cest_Chance {
    private:
        string text;
        int money_transfer;//is for the money the player have to pay
        int field;//is for the field which the player have to move
        int house;//is for the price of a house when it have to be renovateted
        int hotel;//is for the price of a hotel when it have to be renovateted
    public:
        void Kartenzuweisung(string Text);

        void Hotels_House_values(int House, int Hotel);

        void Money_transfer(int money);

        void forward_backward(int Field, int money);
        
        int Field_value();//gives back the Fieldnummber where the player have to go. If the player comes over start, the player calls the funktion "Money()" which gives the player the money for coming over start

        int Money();

        string Text();
};

Community_cest_Chance Community_cest[16];
Community_cest_Chance Chance[16];

void Community_Cest();

void chance();

vector<int> Mix(vector<int> ToMix);

#endif