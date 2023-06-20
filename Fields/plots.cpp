#include "plots.hpp"

//Streets
Lots::Lots() {}

Lots::Lots(string name,int field, int price, int miete, int price_house, int group0, int group1 = 22) {
    Field = field;
    price_of_Lot = price;
    Rent = miete;
    Price_of_House = price_house;
    Streetname = name;
    group.push_back(group0);
    if(group1 < 21 && group1 > 0) {
        group.push_back(group1);
    }
}

string Lots::return_Owner() {
    return Owner;
}

int Lots::pay_Rent(string owner, string owner1, string owner2) {
/*
    If the street does not belong to the player who landed on that street, querying the owner of the street will determine if an increased rent is required to be paid.
    To do this, however, the owners of the other streets in this group must be queried outside of this function, otherwise this function will result in errors during compilation
    If the player does not have to pay the increased rent, it is checked whether the player has to pay the normal rent.
    If not, a check is made to see if the player owns the straight.
    Otherwise it is checked whether a property is not yet for sale, i.e. whether 'Owner == ""'.
    If so, the player will be asked if he wants to buy that road.
    If, due to an error, none of these possibilities apply, that is, if the devil has his fingers in the game ;), 666 is returned.
*/
    if(Owner != owner &&
      (Owner != owner1 && owner == owner1) &&
      (Owner != owner2 && (owner == owner2 || owner2 == "30"))){
        return Rent*(-2);
    }
    else if(Owner != owner){
        return Rent*(-1);
    }
    else if(Owner == owner) {
        return 0;
    }
    else if(Owner == ""){
        std::cout << "Wollen Sie die Straße " << Streetname << " um " << price_of_Lot << " kaufen? " << std::endl;
        cin >> owner; //This desition has to be shown as to bottuns with the options "Ja" for "Yes" and "Nein" for "No"
        Owner = owner;
        if(owner == "ja"){
            return price_of_Lot*(-1);
        }
        if(owner != "nein"){
            return 0;
        }
    }
    return 666;
}

void Lots::Buy(string buyer) {
    Owner = buyer;
}

int Lots::ret_price() {
    return price_of_Lot;
}

int Lots::give_Field() {
    return Field;
}

//trainstations
void Train_Station::allocation_values(int field, int group0, int group1, int group2, string name){
    Field = field;
    Group[0] = group0;
    Group[1] = group1;
    Group[2] = group2;
    Train_station = name;
}

int Train_Station::Rent(string schueldiger, string owner0, string owner1, string owner2){
    if(Owner!=owner0 && Owner!=owner1 && Owner!=owner2 && Owner!=schueldiger && Owner!=""){
        return 25;
    }
    if(Owner!=owner0 && Owner!=owner1 && Owner==owner2 && Owner!=schueldiger && Owner!=""){
        return 50;
    }
    if(Owner!=owner0 && Owner==owner1 && Owner!=owner2 && Owner!=schueldiger && Owner!=""){
        return 50;
    }
    if(Owner==owner0 && Owner!=owner1 && Owner!=owner2 && Owner!=schueldiger && Owner!=""){
        return 50;
    }
    if(Owner!=owner0 && Owner==owner1 && Owner==owner2 && Owner!=schueldiger && Owner!=""){
        return 100;
    }
    if(Owner==owner0 && Owner!=owner1 && Owner==owner2 && Owner!=schueldiger && Owner!=""){
        return 100;
    }
    if(Owner==owner0 && Owner==owner1 && Owner!=owner2 && Owner!=schueldiger && Owner!=""){
        return 100;
    }
    if(Owner==owner0 && Owner==owner1 && Owner==owner2 && Owner!=schueldiger && Owner!=""){
        return 200;
    }
    if(Owner==schueldiger){
        return 0;
    }
    if(Owner==""){
        cout << "Wollen Sie den train_station " << Train_station << " um 200€ kaufen? " << endl;
        cin >> Owner; //This desition has to be shown as to bottuns with the options "Ja" for "Yes" and "Nein" for "No"
        if(Owner == "ja"){
            return -200;
        }
        if(Owner != "nein"){
            return 0;
        }
    }
    return 0;
}

string Train_Station::Besitzerrueckgabe() {
    return Owner;
}

int Train_Station::ret_price() {
    return 200;
}

int Train_Station::give_Field() {
    return Field;
}

void Train_Station::Buy(string buyer) {
    Owner = buyer;
}

//Werke
void power_plant::allocation_values(int field, int group, string name){
    Field = field;
    group = group;
    Name_of_power_plant = name;
}

int power_plant::Rent(int dice_eyes, string schueldiger, string owner1, string owner2){
    if(owner1 == Owner && Owner != "" && schueldiger != Owner && owner2 != Owner){
        return dice_eyes*4;
    }
    else if(owner1 == Owner && owner2 == Owner && Owner != "" && schueldiger != Owner){
        return dice_eyes*10;
    }
    else if(schueldiger == Owner){
        return 0;
    }
    else if(Owner == ""){
        cout << "Wollen Sie die Straße " << Name_of_power_plant << " um 150€ kaufen? " << endl;
        cin >> Owner; //This desition has to be shown as to bottuns with the options "Ja" for "Yes" and "Nein" for "No"
        if(Owner == "ja"){
            return -150;
        }
        if(Owner != "ja"){
            return 0;
        }
    }
    return 666;
}

string power_plant::Besitzerrueckgabe(){
    return Owner;
}

int power_plant::give_Field() {
    return Field;
}

int power_plant::ret_price(){
    return 150;
}

void power_plant::Buy(string buyer) {
    Owner = buyer;
}

//everything
std::array<Lots, 22> allocation_values_streets(){
    std::array<Lots, 22> Streets;
    Streets[0] = Lots("Esterhazystrasse", 1, 60, 2, 50, 1);
    Streets[1] = Lots("Kremserstrasse", 3, 60, 4, 50, 0);

    Streets[2] = Lots("Grieskai", 6, 100, 6, 50, 3, 4);
    Streets[3] = Lots("Herrengasse", 8, 100, 6, 50, 2, 4);
    Streets[4] = Lots("Annenstrasse", 9, 120, 8, 50, 2, 3);

    Streets[5] = Lots("Untere Donaulände", 11, 140, 10, 100, 6, 7);
    Streets[6] = Lots("Taubenmarkt", 13, 140, 10, 100, 5, 7);
    Streets[7] = Lots("Landstrasse", 14, 160, 12, 100, 5, 6);

    Streets[8] = Lots("Mariatheresienstrasse", 16, 180, 14, 100, 9, 10);
    Streets[9] = Lots("Herzogfriedrichstrasse", 18, 180, 14, 100, 8, 10);
    Streets[10] = Lots("Andreashoferstrasse", 19, 200, 16, 100, 8, 9);

    Streets[11] = Lots("10. Oktoberstrasse", 21, 220, 18, 150, 12, 13);
    Streets[12] = Lots("Neuer Platz", 23, 220, 18, 150, 11, 13);
    Streets[13] = Lots("Gramergasse", 24, 240, 20, 150, 11, 12);

    Streets[14] = Lots("Hellbrunnerstrasse", 26, 260, 22, 150, 15, 16);
    Streets[15] = Lots("Domplatz", 27, 260, 22, 150, 14, 16);
    Streets[16] = Lots("Gedreidegasse", 29, 280, 24, 150, 14, 15);

    Streets[17] = Lots("Mariahilferstrasse", 31, 300, 26, 200, 18, 19);
    Streets[18] = Lots("Kärntnerstrasse", 33, 300, 26, 200, 17, 19);
    Streets[19] = Lots("Graben", 34, 340, 28, 200, 17, 18);

    Streets[20] = Lots("Kronmarktstrasse", 37, 350, 50, 200, 21);
    Streets[21] = Lots("Kaiserstrasse", 39, 400, 100, 200, 20);
    return Streets;
}

std::array<power_plant, 2> allocation_values_Werke() {
    array<power_plant, 2> power_plant;
    power_plant[0].allocation_values(12, 1, "Elektrizitaetswerk");
    power_plant[1].allocation_values(28, 0, "Wasserwerk");
    return power_plant;
}

std::array<Train_Station, 4> allocation_values_train_station() {
    std::array<Train_Station, 4> train_station;
    train_station[0].allocation_values(5, 15, 25, 35, "Bahnhof Wien Hauptbahnhof");
    train_station[1].allocation_values(15, 5, 25, 35, "Westbahnhof");
    train_station[2].allocation_values(25, 5, 15, 35, "Wien Hauptbahnhof");
    train_station[3].allocation_values(35, 5, 15, 25, "Franz Josef Bahnhof");
    return train_station;
}

void allocation_values() {
    allocation_values_streets();
    allocation_values_Werke();
    allocation_values_train_station();
}

std::array<int, 3> Check_field(int field) {
    std::array<int, 3> giveback;
    std::array<Lots, 22> Streets = allocation_values_streets();
    std::array<power_plant, 2> factories = allocation_values_Werke();
    std::array<Train_Station, 4> train_station = allocation_values_train_station();

    giveback[0] = -1;
    
    if(field % 10 == 0 || field == 2 || field == 4 || field == 7 || field == 17 || field == 22 || field == 23 || field == 36 || field == 38) {
        giveback[0] = 3;
        giveback[1] = 0;
        giveback[2] = 0;
    }

    if(giveback[0] < 0) {
        for(int i = 0; i < 22; i++) {
            if(field == Streets[i].give_Field()){
                if(Streets[i].return_Owner() == ""){
                    giveback[1] = 0;
                }
                else {
                    giveback[1] == 1;
                    giveback[2] == Streets[i].ret_price();
                }
                giveback[0] = 0;
            }
        }
    }

    if(giveback[1] < 0) {
        for(int i = 0; i < 2; i++) {
            if(field == factories[i].give_Field()){
                if(factories[i].Besitzerrueckgabe() == ""){
                    giveback[1] = 0;
                }
                else {
                    giveback[1] == 1;
                    giveback[2] == factories[i].ret_price();
                }
                giveback[0] = 1;
            }
        }
    }
    for(int i = 0; i < 4; i++) {
        for(int i = 0; i < 2; i++) {
            if(field == train_station[i].give_Field()){
                if(train_station[i].Besitzerrueckgabe() == ""){
                    giveback[1] = 0;
                }
                else {
                    giveback[1] == 1;
                    giveback[2] == train_station[i].ret_price();
                }
                giveback[0] = 3;
            }
        }
    }
    return giveback;
}