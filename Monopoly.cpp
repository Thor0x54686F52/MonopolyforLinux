#include "gesammelte_Header.hpp"
using namespace std;

int main(){
    int Cards[16];
    int card_value;

    unsigned long long null = 0;
    unsigned long long eins = 0;
    unsigned long long zwei = 0;
    unsigned long long drei = 0;
    unsigned long long vier = 0;
    unsigned long long fuenf = 0;
    unsigned long long sechs = 0;
    unsigned long long sieben = 0;
    unsigned long long acht = 0;
    unsigned long long neun = 0;
    unsigned long long zehn = 0;
    unsigned long long elf = 0;
    unsigned long long zwoelf = 0;
    unsigned long long dreizehn = 0;
    unsigned long long vierzehn = 0;
    unsigned long long fuenfzehn = 0;
    srand(card_value);
    card_value = rand()%169+1;
    for(int Fehlerschleife = 0; Fehlerschleife < 100; Fehlerschleife++){
        cout << Fehlerschleife << "%" << "\n";
        for(int i1 = 0; i1 < 16; i1++){
            srand(card_value);
            card_value = rand()%16+1;
            card_value--;
            for(int i2 = 0; i2 < 16; i2++){ //looks if a index is already in use
                if(card_value == Cards[i2]){
                    srand(time(0));
                    card_value = rand()%16+1;
                    card_value--;
                    i2 = 0;
                    if(card_value == 0){
                        null++;
                    }
                    else if(card_value == 1){
                        eins++;
                    }
                    else if(card_value == 2){
                        zwei++;
                    }
                    else if(card_value == 3){
                        drei++;
                    }
                    else if(card_value == 4){
                        vier++;
                    }
                    else if(card_value == 5){
                        fuenf++;
                    }
                    else if(card_value == 6){
                        sechs++;
                    }
                    else if(card_value == 7){
                        sieben++;
                    }
                    else if(card_value == 8){
                        acht++;
                    }
                    else if(card_value == 9){
                        neun++;
                    }
                    else if(card_value == 10){
                        zehn++;
                    }
                    else if(card_value == 11){
                        elf++;
                    }
                    else if(card_value == 12){
                        zwoelf++;
                    }
                    else if(card_value == 13){
                        dreizehn++;
                    }
                    else if(card_value == 14){
                        vierzehn++;
                    }
                    else if(card_value == 15){
                        fuenfzehn++;
                    }
                }
            }
            Cards[i1] = card_value;
            
        }
    }
    
    for(int i = 0; i < 16; i++){
        
        //cout << Cards[i] << "\n";
    }
    cout << "eins: " << eins;
    cout << "\nzwei: " << zwei;
    cout << "\ndrei: " << drei;
    cout << "\nvier: " << vier;
    cout << "\nfuenf: " << fuenf;
    cout << "\nsechs: " << sechs;
    cout << "\nsieben: " << sieben;
    cout << "\nacht: " << acht;
    cout << "\nneun: " << neun;
    cout << "\nzehn: " << zehn;
    cout << "\nelf: "<< elf;
    cout << "\nzwoelf: " << zwoelf;
    cout << "\ndreizehn: " << dreizehn;
    cout << "\nvierzehn: " << vierzehn;
    cout << "\nfuenfzehn: " << fuenfzehn;
    cout << "\nEverything is O.K." << endl;
    return 0;
}
