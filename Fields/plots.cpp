#include "plots.hpp"

//Streets
Grundstueke::Grundstueke(string Name, int field, int preis, int miete, int preis_haus, int gruppe0, int gruppe1 = 0){
    Field=field;
    Preis_Grundstuek=preis;
    Miete=miete;
    Preis_Haus=preis_haus;
    Strasenname=Name;
    group.pushback(gruppe0);
}

string Grundstueke::Besitzerrueckgabe(){
    return Besitzer;
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
    if(Besitzer != besitzer &&
        (Besitzer != besitzer1 && besitzer == besitzer1) &&
        (Besitzer != besitzer2 && (besitzer == besitzer2 || besitzer2 == "30"))){
        return miete*(-2);
    }
    else if(Besitzer != besitzer){
        return miete*(-1);
    }
    else if(Besitzer == besitzer) {
        return 0;
    }
    else if(Besitzer == ""){
        std::cout << "Wollen Sie die Straße " << Strasenname << " um " << Preis_Grundstuek << " kaufen? " << std::endl;
        cin >> besitzer; //diese Entscheidung muss als zwei Buttons angezeigt werden mit den Auswahlmöglichkeiten ja und nein
        Besitzer = besitzer;
        if(besitzer == "ja"){
            return Preis_Grundstuek*(-1);
        }
        if(besitzer != "nein"){
            return 0;
        }
    }
    return 666;
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
    if(Besitzer!=Besitzer0 && Besitzer!=Besitzer1 && Besitzer!=Besitzer2 && Besitzer!=schueldiger && Besitzer!=""){
        return 25;
    }
    if(Besitzer!=Besitzer0 && Besitzer!=Besitzer1 && Besitzer==Besitzer2 && Besitzer!=schueldiger && Besitzer!=""){
        return 50;
    }
    if(Besitzer!=Besitzer0 && Besitzer==Besitzer1 && Besitzer!=Besitzer2 && Besitzer!=schueldiger && Besitzer!=""){
        return 50;
    }
    if(Besitzer==Besitzer0 && Besitzer!=Besitzer1 && Besitzer!=Besitzer2 && Besitzer!=schueldiger && Besitzer!=""){
        return 50;
    }
    if(Besitzer!=Besitzer0 && Besitzer==Besitzer1 && Besitzer==Besitzer2 && Besitzer!=schueldiger && Besitzer!=""){
        return 100;
    }
    if(Besitzer==Besitzer0 && Besitzer!=Besitzer1 && Besitzer==Besitzer2 && Besitzer!=schueldiger && Besitzer!=""){
        return 100;
    }
    if(Besitzer==Besitzer0 && Besitzer==Besitzer1 && Besitzer!=Besitzer2 && Besitzer!=schueldiger && Besitzer!=""){
        return 100;
    }
    if(Besitzer==Besitzer0 && Besitzer==Besitzer1 && Besitzer==Besitzer2 && Besitzer!=schueldiger && Besitzer!=""){
        return 200;
    }
    if(Besitzer==schueldiger){
        return 0;
    }
    if(Besitzer==""){
        cout << "Wollen Sie den train_station " << train_station << " um 200€ kaufen? " << endl;
        cin >> Besitzer; //diese Entscheidung muss als zwei Buttons angezeigt werden mit den Auswahlmöglichkeiten ja und nein
        if(Besitzer == "ja"){
            return -200;
        }
        if(Besitzer != "nein"){
            return 0;
        }
    }
    return 0;
}

//Werke
void Werke::allocation_values(int field, int gruppe, string Name){
    Field=field;
    group=gruppe;
    Werkname=Name;
}

int Werke::miete(int Wuerfelaugen, string schueldiger, string besitzer1, string besitzer2){
    if(besitzer1 == Besitzer && Besitzer != "" && schueldiger != Besitzer && besitzer2 != Besitzer){
        return Wuerfelaugen*4;
    }
    else if(besitzer1 == Besitzer && besitzer2 == Besitzer && Besitzer != "" && schueldiger != Besitzer){
        return Wuerfelaugen*10;
    }
    else if(schueldiger == Besitzer){
        return 0;
    }
    else if(Besitzer == ""){
        cout << "Wollen Sie die Straße " << Werkname << " um 150€ kaufen? " << endl;
        cin >> Besitzer; //diese Entscheidung muss als zwei Buttons angezeigt werden mit den Auswahlmöglichkeiten ja und nein
        if(Besitzer == "ja"){
            return -150;
        }
        if(Besitzer != "ja"){
            return 0;
        }
    }
    return 666;
}

string Werke::Besitzerauslesen(){
    return Besitzer;
}

//everything
void allocation_values_streets(){
    Strasen[0] = Grundstueke("Esterhazystrasse", 1, 60, 2, 50, 1);
    Strasen[1] = Grundstueke("Kremserstrasse", 3, 60, 4, 50, 0);

    Strasen[2] = Grundstueke("Grieskai", 6, 100, 6, 50, 3, 4);
    Strasen[3] = Grundstueke("Herrengasse", 8, 100, 6, 50, 2, 4);
    Strasen[4] = Grundstueke("Annenstrasse", 9, 120, 8, 50, 2, 3);

    Strasen[5] = Grundstueke("Untere Donaulände", 11, 140, 10, 100, 6, 7);
    Strasen[6] = Grundstueke("Taubenmarkt", 13, 140, 10, 100, 5, 7);
    Strasen[7] = Grundstueke("Landstrasse", 14, 160, 12, 100, 5, 6);

    Strasen[8] = Grundstueke("Mariatheresienstrasse", 16, 180, 14, 100, 9, 10);
    Strasen[9] = Grundstueke("Herzogfriedrichstrasse", 18, 180, 14, 100, 8, 10);
    Strasen[10] = Grundstueke("Andreashoferstrasse", 19, 200, 16, 100, 8, 9);

    Strasen[11] = Grundstueke("10. Oktoberstrasse", 21, 220, 18, 150, 12, 13);
    Strasen[12] = Grundstueke("Neuer Platz", 23, 220, 18, 150, 11, 13);
    Strasen[13] = Grundstueke("Gramergasse", 24, 240, 20, 150, 11, 12);

    Strasen[14] = Grundstueke("Hellbrunnerstrasse", 26, 260, 22, 150, 15, 16);
    Strasen[15] = Grundstueke("Domplatz", 27, 260, 22, 150, 14, 16);
    Strasen[16] = Grundstueke("Gedreidegasse", 29, 280, 24, 150, 14, 15);

    Strasen[17] = Grundstueke("Mariahilferstrasse", 31, 300, 26, 200, 18, 19);
    Strasen[18] = Grundstueke("Kärntnerstrasse", 33, 300, 26, 200, 17, 19);
    Strasen[19] = Grundstueke("Graben", 34, 340, 28, 200, 17, 18);

    Strasen[20] = Grundstueke("Kronmarktstrasse", 37, 350, 50, 200, 21);
    Strasen[21] = Grundstueke("Kaiserstrasse", 39, 400, 100, 200, 20);
}

void allocation_values_Werke(){
    Kraftwerke[0].allocation_values(12, 1, "Elektrizitaetswerk");
    Kraftwerke[1].allocation_values(28, 0, "Wasserwerk");
}

void allocation_values_train_station(){
    train_station[0].allocation_values(5, 15, 25, 35, "Bahnhof Wien Hauptbahnhof");
    train_station[1].allocation_values(15, 5, 25, 35, "Westbahnhof");
    train_station[2].allocation_values(25, 5, 15, 35, "Wien Hauptbahnhof");
    train_station[3].allocation_values(35, 5, 15, 25, "Franz Josef Bahnhof");
}

void allocation_values(){
    allocation_values_streets();
    allocation_values_Werke();
    allocation_values_train_station();
}