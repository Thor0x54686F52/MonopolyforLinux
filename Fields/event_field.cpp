#include "event_field.hpp"

void Community_cest_Chance::Card_assignment(string text){
    Text = text;
}

void Community_cest_Chance::Hotels_House_values(int house, int hotel){
    House = house;
    Hotel = hotel;
}

void Community_cest_Chance::Moneytransfer(int money){
    Money_transfer = money;
}

void Community_cest_Chance::forward_backward(int field, int money){
    Field = field;
    Money_transfer = money;
}

int Community_cest_Chance::Field_value(){
    return Field;
}

int Community_cest_Chance::Money(){
    return 200;
}

std::string Community_cest_Chance::return_Text(){
    return Text;
}

array<Community_cest_Chance, 16> Community_Chest() {
    array<Community_cest_Chance, 16> community_chest;

    community_chest[0].Card_assignment("Sie kommen aus dem Gefängnis frei! Behalten Sie diese Karte, bis Sie sie benötigen oder verkaufen.");//Has to be implement theat the player can use that card or can sell it
    community_chest[1].Card_assignment("Schuldgeld. Zahlen Sie 50€.");
    community_chest[2].Card_assignment("Urlaubsgeld! Sie erhalten 100€.");
    community_chest[3].Card_assignment("Ihre Lebensversicherung wird fällig. Sie erhalten 100€.");
    community_chest[4].Card_assignment("Arzt-Kosten. Zahlen Sie 50€.");
    community_chest[5].Card_assignment("Einkommenssteuerrückerstattung. Sie erhalten 20€.");
    community_chest[6].Card_assignment("Krankenhausgebühren. Zahlen Sie 100€.");
    community_chest[7].Card_assignment("Gehen Sie in das Gefängnis. Begeben Sie sich direkt dorthin. Gehen Sie nicht über Los. Ziehen Sie nicht 200€ ein.");
    community_chest[8].Card_assignment("Sie erhalten auf Vorzugs-Aktien 7% Dividende: 25€.");
    community_chest[9].Card_assignment("Sie haben Geburtstag. Jeder Spieler schenkt Ihnen 10€.");//Has to be implement that the player gets from every other player 10€
    community_chest[10].Card_assignment("Sie erben 100€.");
    community_chest[11].Card_assignment("Aus Lagerverkäufen erhalten Sie 50€.");
    community_chest[12].Card_assignment("Zweiter Preis im Schönheitswettbewerb. Sie erhalten 10€.");
    community_chest[13].Card_assignment("Sie werden zu Straßenausbesserungsarbeiten herangezogen. Zahlen Sie 40€ je Haus und 115€ je Hotel an die Bank.");
    community_chest[14].Card_assignment("Rücken Sie vor bis auf Los. (Ziehe 200€ ein).");
    community_chest[15].Card_assignment("Bank-Irrtum zu Ihren Gunsten. Ziehen Sie 200€ ein.");

    community_chest[13].Hotels_House_values(-40, -115);

    community_chest[1].Moneytransfer(-50);
    community_chest[2].Moneytransfer(100);
    community_chest[3].Moneytransfer(100);
    community_chest[4].Moneytransfer(-50);
    community_chest[5].Moneytransfer(20);
    community_chest[6].Moneytransfer(-100);
    community_chest[8].Moneytransfer(25);
    community_chest[10].Moneytransfer(100);
    community_chest[11].Moneytransfer(50);
    community_chest[12].Moneytransfer(10);
    community_chest[15].Moneytransfer(200);

    community_chest[7].forward_backward(10, 0);
    community_chest[14].forward_backward(0, 200);
    return community_chest;
}

array<Community_cest_Chance, 16> Chance() {
    array<Community_cest_Chance, 16>  chance;
    chance[0].Card_assignment("Rücken Sie vor bis zur Kaiserstrasse.");
    chance[1].Card_assignment("Machen Sie einen Ausflug zum Bahnhof Wien Hauptbahnhof. Wenn Sie über Los kommen, ziehen Sie 200€ ein.");
    chance[2].Card_assignment("Ihr Bausparvertrag wird fällig. Sie erhalten 200€.");
    chance[3].Card_assignment("Rücken Sie vor bis zum Untere Donaulände. Wenn Sie über Los kommen, ziehen Sie 200€ ein.");
    chance[4].Card_assignment("Rücken Sie vor bis zum nächsten Versorgungswerk. Werfen Sie die Würfel und zahlen dem Eigentümer den zehnfachen Betrag Ihres Wurfergebnisses. Wenn das Werk noch niemandem gehört, können Sie es von der Bank kaufen.");//muss noch überarbeitet werden
    chance[5].Card_assignment("Gehen Sie in das Gefängnis. Begeben Sie sich direkt dorthin. Gehen Sie nicht über Los. Ziehen Sie nicht 200€ ein.");
    chance[6].Card_assignment("Rücken Sie vor bis auf Los. (Ziehe 200€ ein).");
    chance[7].Card_assignment("Die Bank zahlt Ihnen eine Dividende von 50€.");
    chance[8].Card_assignment("Sie lassen Ihre Häuser renovieren. Zahlen Sie: 25€ pro Haus, 100€ pro Hotel.");
    chance[9].Card_assignment("Sie kommen aus dem Gefängnis frei! Behalten Sie diese Karte, bis Sie sie benötigen oder verkaufen.");//Has to be implement theat the player can use that card or can sell it
    chance[10].Card_assignment("Rücken Sie vor bis zur Gramergasse. Wenn Sie über Los kommen, ziehen Sie 200€ ein.");
    chance[11].Card_assignment("Sie sind zum Vorstand gewählt worden. Zahlen Sie jedem Spieler 50€.");//has to be implemented that the the player gets from every player 50€
    chance[12].Card_assignment("Ihr Bausparvertrag wird fällig. Sie erhalten 200€.");
    chance[13].Card_assignment("Gehen Sie 3 Felder zurück.");
    chance[14].Card_assignment("Strafzettel! Zahlen Sie 15€.");
    chance[15].Card_assignment("Rücken Sie vor bis zum nächsten Bahnhof. Der Eigentümer erhält das Doppelte der normalen Miete. Wenn das Bahnhof noch niemandem gehört, können Sie es von der Bank kaufen.");//muss noch überarbeitet werden
    
    chance[8].Hotels_House_values(-25, -100);

    chance[2].Moneytransfer(200);
    chance[7].Moneytransfer(50);
    chance[12].Moneytransfer(200);
    chance[14].Moneytransfer(-15);

    chance[0].forward_backward(39, 0);
    chance[1].forward_backward(5, 200);
    chance[3].forward_backward(11, 200);
    chance[5].forward_backward(10, 0);//has to be implemented, that the player goes to prison (field 10) after he/she gets that card
    chance[6].forward_backward(0, 200);
    chance[10].forward_backward(24, 200);
    chance[13].forward_backward(-3, 0);//has to be implemented, that after the player gets that card, he/she has to go 3 fields back
    return chance;
}

