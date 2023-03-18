#include "Ereignisfeld.hpp"

Community_cest_Chance Community_cest[16];
Community_cest_Chance Chance[16];

Community_cest_Chance Community_Cest(int ) {
    Community_cest[0].Kartenzuweisung("Sie kommen aus dem Gefängnis frei! Behalten Sie diese Karte, bis Sie sie benötigen oder verkaufen.");//muss noch überarbeitet werden
    Community_cest[1].Kartenzuweisung("Schuldgeld. Zahlen Sie 50€.");
    Community_cest[2].Kartenzuweisung("Urlaubsgeld! Sie erhalten 100€.");
    Community_cest[3].Kartenzuweisung("Ihre Lebensversicherung wird fällig. Sie erhalten 100€.");
    Community_cest[4].Kartenzuweisung("Arzt-Kosten. Zahlen Sie 50€.");
    Community_cest[5].Kartenzuweisung("Einkommenssteuerrückerstattung. Sie erhalten 20€.");
    Community_cest[6].Kartenzuweisung("Krankenhausgebühren. Zahlen Sie 100€.");
    Community_cest[7].Kartenzuweisung("Gehen Sie in das Gefängnis. Begeben Sie sich direkt dorthin. Gehen Sie nicht über Los. Ziehen Sie nicht 200€ ein.");
    Community_cest[8].Kartenzuweisung("Sie erhalten auf Vorzugs-Aktien 7% Dividende: 25€.");
    Community_cest[9].Kartenzuweisung("Sie haben Geburtstag. Jeder Spieler schenkt Ihnen 10€.");//muss noch überarbeitet werden
    Community_cest[10].Kartenzuweisung("Sie erben 100€.");
    Community_cest[11].Kartenzuweisung("Aus Lagerverkäufen erhalten Sie 50€.");
    Community_cest[12].Kartenzuweisung("Zweiter Preis im Schönheitswettbewerb. Sie erhalten 10€.");
    Community_cest[13].Kartenzuweisung("Sie werden zu Straßenausbesserungsarbeiten herangezogen. Zahlen Sie 40€ je Haus und 115€ je Hotel an die Bank.");
    Community_cest[14].Kartenzuweisung("Rücken Sie vor bis auf Los. (Ziehe 200€ ein).");
    Community_cest[15].Kartenzuweisung("Bank-Irrtum zu Ihren Gunsten. Ziehen Sie 200€ ein.");

    Community_cest[13].Hotels_House_values(-40, -115);

    Community_cest[1].Money_transfer(-50);
    Community_cest[2].Money_transfer(100);
    Community_cest[3].Money_transfer(100);
    Community_cest[4].Money_transfer(-50);
    Community_cest[5].Money_transfer(20);
    Community_cest[6].Money_transfer(-100);
    Community_cest[8].Money_transfer(25);
    Community_cest[10].Money_transfer(100);
    Community_cest[11].Money_transfer(50);
    Community_cest[12].Money_transfer(10);
    Community_cest[15].Money_transfer(200);

    Community_cest[7].forward_backward(10, 0);
    Community_cest[14].forward_backward(0, 200);
}

void chance() {
    Chance[0].Kartenzuweisung("Rücken Sie vor bis zur Kaiserstrasse.");
    Chance[1].Kartenzuweisung("Machen Sie einen Ausflug zum Bahnhof Wien Hauptbahnhof. Wenn Sie über Los kommen, ziehen Sie 200€ ein.");
    Chance[2].Kartenzuweisung("Ihr Bausparvertrag wird fällig. Sie erhalten 200€.");
    Chance[3].Kartenzuweisung("Rücken Sie vor bis zum Untere Donaulände. Wenn Sie über Los kommen, ziehen Sie 200€ ein.");
    Chance[4].Kartenzuweisung("Rücken Sie vor bis zum nächsten Versorgungswerk. Werfen Sie die Würfel und zahlen dem Eigentümer den zehnfachen Betrag Ihres Wurfergebnisses. Wenn das Werk noch niemandem gehört, können Sie es von der Bank kaufen.");//muss noch überarbeitet werden
    Chance[5].Kartenzuweisung("Gehen Sie in das Gefängnis. Begeben Sie sich direkt dorthin. Gehen Sie nicht über Los. Ziehen Sie nicht 200€ ein.");
    Chance[6].Kartenzuweisung("Rücken Sie vor bis auf Los. (Ziehe 200€ ein).");
    Chance[7].Kartenzuweisung("Die Bank zahlt Ihnen eine Dividende von 50€.");
    Chance[8].Kartenzuweisung("Sie lassen Ihre Häuser renovieren. Zahlen Sie: 25€ pro Haus, 100€ pro Hotel.");
    Chance[9].Kartenzuweisung("Sie kommen aus dem Gefängnis frei! Behalten Sie diese Karte, bis Sie sie benötigen oder verkaufen.");//muss noch überarbeitet werden
    Chance[10].Kartenzuweisung("Rücken Sie vor bis zur Gramergasse. Wenn Sie über Los kommen, ziehen Sie 200€ ein.");
    Chance[11].Kartenzuweisung("Sie sind zum Vorstand gewählt worden. Zahlen Sie jedem Spieler 50€.");//muss noch überarbeitet werden
    Chance[12].Kartenzuweisung("Ihr Bausparvertrag wird fällig. Sie erhalten 200€.");
    Chance[13].Kartenzuweisung("Gehen Sie 3 Felder zurück.");
    Chance[14].Kartenzuweisung("Strafzettel! Zahlen Sie 15€.");
    Chance[15].Kartenzuweisung("Rücken Sie vor bis zum nächsten Bahnhof. Der Eigentümer erhält das Doppelte der normalen Miete. Wenn das Bahnhof noch niemandem gehört, können Sie es von der Bank kaufen.");//muss noch überarbeitet werden
    Chance[8].Hotels_House_values(-25, -100);

    Chance[2].Money_transfer(200);
    Chance[7].Money_transfer(50);
    Chance[12].Money_transfer(200);
    Chance[14].Money_transfer(-15);

    Chance[0].forward_backward(39, 0);
    Chance[1].forward_backward(5, 200);
    Chance[3].forward_backward(11, 200);
    Chance[5].forward_backward(10, 0);//muss während dem Spiel geprüft werden ob der Spieler im Gefängnis gelandet ist
    Chance[6].forward_backward(0, 200);
    Chance[10].forward_backward(24, 200);
    Chance[13].forward_backward(-3, 0);//muss noch so gerregelt werden, dass der Spieler 3 Felder zurück geht
}

vector<int> Mix(vector<int> Cards, int max) {
    int card_value;

    srand(card_value);
    for(int i1 = 0; i1 < max; i1++) {
        card_value = rand()%16+1;
        card_value--;
        for(int i2 = 0; i2 < 16; i2++) { //looks if a index is already in use
            if(card_value == Cards[i2]) {
                card_value = rand()%16+1;
                card_value--;
                i2 = -1;
            }
        }
        Cards[i1] = card_value;
    }
    for(int i = 0; i < 16; i++) {
        std::cout << Cards[i] << std::endl;
    }
    return Cards;
}