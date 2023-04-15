#include "event_field.hpp"

void Community_cest_Chance::Kartenzuweisung(string Text){
    text = Text;
}

void Community_cest_Chance::Hotels_House_values(int House, int Hotel){
    house = House;
    hotel = Hotel;
}

void Community_cest_Chance::Money_transfer(int money){
    money_transfer = money;
}

void Community_cest_Chance::forward_backward(int Field, int money){
    field = Field;
    money_transfer = money;
}

int Community_cest_Chance::Field_value(){
    return field;
}

int Community_cest_Chance::Money(){
    return 200;
}

string Community_cest_Chance::Text(){
    return text;
}

array<Community_cest_Chance, 16> Community_Chest() {
    array<Community_cest_Chance, 16> community_chest;

    community_chest[0].Kartenzuweisung("Sie kommen aus dem Gefängnis frei! Behalten Sie diese Karte, bis Sie sie benötigen oder verkaufen.");//muss noch überarbeitet werden
    community_chest[1].Kartenzuweisung("Schuldgeld. Zahlen Sie 50€.");
    community_chest[2].Kartenzuweisung("Urlaubsgeld! Sie erhalten 100€.");
    community_chest[3].Kartenzuweisung("Ihre Lebensversicherung wird fällig. Sie erhalten 100€.");
    community_chest[4].Kartenzuweisung("Arzt-Kosten. Zahlen Sie 50€.");
    community_chest[5].Kartenzuweisung("Einkommenssteuerrückerstattung. Sie erhalten 20€.");
    community_chest[6].Kartenzuweisung("Krankenhausgebühren. Zahlen Sie 100€.");
    community_chest[7].Kartenzuweisung("Gehen Sie in das Gefängnis. Begeben Sie sich direkt dorthin. Gehen Sie nicht über Los. Ziehen Sie nicht 200€ ein.");
    community_chest[8].Kartenzuweisung("Sie erhalten auf Vorzugs-Aktien 7% Dividende: 25€.");
    community_chest[9].Kartenzuweisung("Sie haben Geburtstag. Jeder Spieler schenkt Ihnen 10€.");//muss noch überarbeitet werden
    community_chest[10].Kartenzuweisung("Sie erben 100€.");
    community_chest[11].Kartenzuweisung("Aus Lagerverkäufen erhalten Sie 50€.");
    community_chest[12].Kartenzuweisung("Zweiter Preis im Schönheitswettbewerb. Sie erhalten 10€.");
    community_chest[13].Kartenzuweisung("Sie werden zu Straßenausbesserungsarbeiten herangezogen. Zahlen Sie 40€ je Haus und 115€ je Hotel an die Bank.");
    community_chest[14].Kartenzuweisung("Rücken Sie vor bis auf Los. (Ziehe 200€ ein).");
    community_chest[15].Kartenzuweisung("Bank-Irrtum zu Ihren Gunsten. Ziehen Sie 200€ ein.");

    community_chest[13].Hotels_House_values(-40, -115);

    community_chest[1].Money_transfer(-50);
    community_chest[2].Money_transfer(100);
    community_chest[3].Money_transfer(100);
    community_chest[4].Money_transfer(-50);
    community_chest[5].Money_transfer(20);
    community_chest[6].Money_transfer(-100);
    community_chest[8].Money_transfer(25);
    community_chest[10].Money_transfer(100);
    community_chest[11].Money_transfer(50);
    community_chest[12].Money_transfer(10);
    community_chest[15].Money_transfer(200);

    community_chest[7].forward_backward(10, 0);
    community_chest[14].forward_backward(0, 200);
    return community_chest;
}

array<Community_cest_Chance, 16> Chance() {
    array<Community_cest_Chance, 16>  chance;
    chance[0].Kartenzuweisung("Rücken Sie vor bis zur Kaiserstrasse.");
    chance[1].Kartenzuweisung("Machen Sie einen Ausflug zum Bahnhof Wien Hauptbahnhof. Wenn Sie über Los kommen, ziehen Sie 200€ ein.");
    chance[2].Kartenzuweisung("Ihr Bausparvertrag wird fällig. Sie erhalten 200€.");
    chance[3].Kartenzuweisung("Rücken Sie vor bis zum Untere Donaulände. Wenn Sie über Los kommen, ziehen Sie 200€ ein.");
    chance[4].Kartenzuweisung("Rücken Sie vor bis zum nächsten Versorgungswerk. Werfen Sie die Würfel und zahlen dem Eigentümer den zehnfachen Betrag Ihres Wurfergebnisses. Wenn das Werk noch niemandem gehört, können Sie es von der Bank kaufen.");//muss noch überarbeitet werden
    chance[5].Kartenzuweisung("Gehen Sie in das Gefängnis. Begeben Sie sich direkt dorthin. Gehen Sie nicht über Los. Ziehen Sie nicht 200€ ein.");
    chance[6].Kartenzuweisung("Rücken Sie vor bis auf Los. (Ziehe 200€ ein).");
    chance[7].Kartenzuweisung("Die Bank zahlt Ihnen eine Dividende von 50€.");
    chance[8].Kartenzuweisung("Sie lassen Ihre Häuser renovieren. Zahlen Sie: 25€ pro Haus, 100€ pro Hotel.");
    chance[9].Kartenzuweisung("Sie kommen aus dem Gefängnis frei! Behalten Sie diese Karte, bis Sie sie benötigen oder verkaufen.");//muss noch überarbeitet werden
    chance[10].Kartenzuweisung("Rücken Sie vor bis zur Gramergasse. Wenn Sie über Los kommen, ziehen Sie 200€ ein.");
    chance[11].Kartenzuweisung("Sie sind zum Vorstand gewählt worden. Zahlen Sie jedem Spieler 50€.");//muss noch überarbeitet werden
    chance[12].Kartenzuweisung("Ihr Bausparvertrag wird fällig. Sie erhalten 200€.");
    chance[13].Kartenzuweisung("Gehen Sie 3 Felder zurück.");
    chance[14].Kartenzuweisung("Strafzettel! Zahlen Sie 15€.");
    chance[15].Kartenzuweisung("Rücken Sie vor bis zum nächsten Bahnhof. Der Eigentümer erhält das Doppelte der normalen Miete. Wenn das Bahnhof noch niemandem gehört, können Sie es von der Bank kaufen.");//muss noch überarbeitet werden
    
    chance[8].Hotels_House_values(-25, -100);

    chance[2].Money_transfer(200);
    chance[7].Money_transfer(50);
    chance[12].Money_transfer(200);
    chance[14].Money_transfer(-15);

    chance[0].forward_backward(39, 0);
    chance[1].forward_backward(5, 200);
    chance[3].forward_backward(11, 200);
    chance[5].forward_backward(10, 0);//muss während dem Spiel geprüft werden ob der Spieler im Gefängnis gelandet ist
    chance[6].forward_backward(0, 200);
    chance[10].forward_backward(24, 200);
    chance[13].forward_backward(-3, 0);//muss noch so gerregelt werden, dass der Spieler 3 Felder zurück geht
    return chance;
}

