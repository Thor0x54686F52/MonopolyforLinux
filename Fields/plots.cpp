#include "plots.hpp"

//Streets
Grundstueke::Grundstueke() {}

Grundstueke::Grundstueke(string Name, int field, int preis, int miete, int preis_haus, int gruppe0, int gruppe1 = 0){
    Field=field;
    Preis_Grundstuek=preis;
    Miete=miete;
    Preis_Haus=preis_haus;
    Strasenname=Name;
    group.push_back(gruppe0);
}

string Grundstueke::Besitzerrueckgabe(){
    return Owner;
}

int Grundstueke::Miete_zahlen(string besitzer, string besitzer1, string besitzer2) {
/*Wenn die Straße nicht dem Spieler der auf diese Straße gelandet ist gehört, wird durch abfragen der Besitzer der Straßen, geprüft, ob eine erhöte Miete gezahlt werden muss.
    Dafür müssen jedoch auserhalb dieser Funktion die Besitzer der anderen Straßen dieser Gruppe abgefragt werden, da es in dieser Funktion sonst zu Fehlern bei der Kompilierung kommt
    Wenn der Spieler keine erhöte Miete zahlen muss, wird geprüft obder Spieler die normale Miete zahlen muss.
    Wenn das nicht zutrifft, wird geprüfft, ob der Spieler die Straße besitzt.
    Sonst wird überprüft ob ein Grundstück noch nicht verkauf ist, das heißt ob 'Besitzer == ""'.
    Wenn das zutrifft, wird der Spieler gefragt, ob dieser diese Straße kaufen will.
    Wenn durch einen Fehler, keine dieser Möglichkeiten zutrifft, dass heißt, wenn der Teufel seine Finger im Spiel hat ;), wird 666 zurückgegeben.
*/
    if(Owner != besitzer &&
        (Owner != besitzer1 && besitzer == besitzer1) &&
        (Owner != besitzer2 && (besitzer == besitzer2 || besitzer2 == "30"))){
        return Miete*(-2);
    }
    else if(Owner != besitzer){
        return Miete*(-1);
    }
    else if(Owner == besitzer) {
        return 0;
    }
    else if(Owner == ""){
        std::cout << "Wollen Sie die Straße " << Strasenname << " um " << Preis_Grundstuek << " kaufen? " << std::endl;
        cin >> besitzer; //diese Entscheidung muss als zwei Buttons angezeigt werden mit den Auswahlmöglichkeiten ja und nein
        Owner = besitzer;
        if(besitzer == "ja"){
            return Preis_Grundstuek*(-1);
        }
        if(besitzer != "nein"){
            return 0;
        }
    }
    return 666;
}

void Grundstueke::Buy(string buyer) {
    Owner = buyer;
}

int Grundstueke::ret_price() {
    return Preis_Grundstuek;
}

int Grundstueke::give_Field() {
    return Field;
}

//trainstations
void Train_Station::allocation_values(int field, int gruppe0, int gruppe1, int gruppe2, string Name){
    Field=field;
    Gruppe[0]=gruppe0;
    Gruppe[1]=gruppe1;
    Gruppe[2]=gruppe2;
    train_station=Name;
}

int Train_Station::Miete(string schueldiger, string Besitzer0, string Besitzer1, string Besitzer2){
    if(Owner!=Besitzer0 && Owner!=Besitzer1 && Owner!=Besitzer2 && Owner!=schueldiger && Owner!=""){
        return 25;
    }
    if(Owner!=Besitzer0 && Owner!=Besitzer1 && Owner==Besitzer2 && Owner!=schueldiger && Owner!=""){
        return 50;
    }
    if(Owner!=Besitzer0 && Owner==Besitzer1 && Owner!=Besitzer2 && Owner!=schueldiger && Owner!=""){
        return 50;
    }
    if(Owner==Besitzer0 && Owner!=Besitzer1 && Owner!=Besitzer2 && Owner!=schueldiger && Owner!=""){
        return 50;
    }
    if(Owner!=Besitzer0 && Owner==Besitzer1 && Owner==Besitzer2 && Owner!=schueldiger && Owner!=""){
        return 100;
    }
    if(Owner==Besitzer0 && Owner!=Besitzer1 && Owner==Besitzer2 && Owner!=schueldiger && Owner!=""){
        return 100;
    }
    if(Owner==Besitzer0 && Owner==Besitzer1 && Owner!=Besitzer2 && Owner!=schueldiger && Owner!=""){
        return 100;
    }
    if(Owner==Besitzer0 && Owner==Besitzer1 && Owner==Besitzer2 && Owner!=schueldiger && Owner!=""){
        return 200;
    }
    if(Owner==schueldiger){
        return 0;
    }
    if(Owner==""){
        cout << "Wollen Sie den train_station " << train_station << " um 200€ kaufen? " << endl;
        cin >> Owner; //diese Entscheidung muss als zwei Buttons angezeigt werden mit den Auswahlmöglichkeiten ja und nein
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
void Werke::allocation_values(int field, int gruppe, string Name){
    Field=field;
    group=gruppe;
    Werkname=Name;
}

int Werke::miete(int Wuerfelaugen, string schueldiger, string besitzer1, string besitzer2){
    if(besitzer1 == Owner && Owner != "" && schueldiger != Owner && besitzer2 != Owner){
        return Wuerfelaugen*4;
    }
    else if(besitzer1 == Owner && besitzer2 == Owner && Owner != "" && schueldiger != Owner){
        return Wuerfelaugen*10;
    }
    else if(schueldiger == Owner){
        return 0;
    }
    else if(Owner == ""){
        cout << "Wollen Sie die Straße " << Werkname << " um 150€ kaufen? " << endl;
        cin >> Owner; //diese Entscheidung muss als zwei Buttons angezeigt werden mit den Auswahlmöglichkeiten ja und nein
        if(Owner == "ja"){
            return -150;
        }
        if(Owner != "ja"){
            return 0;
        }
    }
    return 666;
}

string Werke::Besitzerrueckgabe(){
    return Owner;
}

int Werke::give_Field() {
    return Field;
}

int Werke::ret_price(){
    return 150;
}

void Werke::Buy(string buyer) {
    Owner = buyer;
}

//everything
std::array<Grundstueke, 22> allocation_values_streets(){
    std::array<Grundstueke, 22> Streets;
    Streets[0] = Grundstueke("Esterhazystrasse", 1, 60, 2, 50, 1);
    Streets[1] = Grundstueke("Kremserstrasse", 3, 60, 4, 50, 0);

    Streets[2] = Grundstueke("Grieskai", 6, 100, 6, 50, 3, 4);
    Streets[3] = Grundstueke("Herrengasse", 8, 100, 6, 50, 2, 4);
    Streets[4] = Grundstueke("Annenstrasse", 9, 120, 8, 50, 2, 3);

    Streets[5] = Grundstueke("Untere Donaulände", 11, 140, 10, 100, 6, 7);
    Streets[6] = Grundstueke("Taubenmarkt", 13, 140, 10, 100, 5, 7);
    Streets[7] = Grundstueke("Landstrasse", 14, 160, 12, 100, 5, 6);

    Streets[8] = Grundstueke("Mariatheresienstrasse", 16, 180, 14, 100, 9, 10);
    Streets[9] = Grundstueke("Herzogfriedrichstrasse", 18, 180, 14, 100, 8, 10);
    Streets[10] = Grundstueke("Andreashoferstrasse", 19, 200, 16, 100, 8, 9);

    Streets[11] = Grundstueke("10. Oktoberstrasse", 21, 220, 18, 150, 12, 13);
    Streets[12] = Grundstueke("Neuer Platz", 23, 220, 18, 150, 11, 13);
    Streets[13] = Grundstueke("Gramergasse", 24, 240, 20, 150, 11, 12);

    Streets[14] = Grundstueke("Hellbrunnerstrasse", 26, 260, 22, 150, 15, 16);
    Streets[15] = Grundstueke("Domplatz", 27, 260, 22, 150, 14, 16);
    Streets[16] = Grundstueke("Gedreidegasse", 29, 280, 24, 150, 14, 15);

    Streets[17] = Grundstueke("Mariahilferstrasse", 31, 300, 26, 200, 18, 19);
    Streets[18] = Grundstueke("Kärntnerstrasse", 33, 300, 26, 200, 17, 19);
    Streets[19] = Grundstueke("Graben", 34, 340, 28, 200, 17, 18);

    Streets[20] = Grundstueke("Kronmarktstrasse", 37, 350, 50, 200, 21);
    Streets[21] = Grundstueke("Kaiserstrasse", 39, 400, 100, 200, 20);
    return Streets;
}

std::array<Werke, 2> allocation_values_Werke(){
    array<Werke, 2> Kraftwerke;
    Kraftwerke[0].allocation_values(12, 1, "Elektrizitaetswerk");
    Kraftwerke[1].allocation_values(28, 0, "Wasserwerk");
    return Kraftwerke;
}

std::array<Train_Station, 4> allocation_values_train_station(){
    std::array<Train_Station, 4> train_station;
    train_station[0].allocation_values(5, 15, 25, 35, "Bahnhof Wien Hauptbahnhof");
    train_station[1].allocation_values(15, 5, 25, 35, "Westbahnhof");
    train_station[2].allocation_values(25, 5, 15, 35, "Wien Hauptbahnhof");
    train_station[3].allocation_values(35, 5, 15, 25, "Franz Josef Bahnhof");
    return train_station;
}

void allocation_values(){
    allocation_values_streets();
    allocation_values_Werke();
    allocation_values_train_station();
}

std::array<int, 3> Check_field(int field) {
    std::array<int, 3> giveback;
    std::array<Grundstueke, 22> Streets = allocation_values_streets();
    std::array<Werke, 2> factories = allocation_values_Werke();
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
                if(Streets[i].Besitzerrueckgabe() == ""){
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

    if(giveback[0] < 0) {
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