#include "./Fields/event_field.hpp"
#include "./Fields/plots.hpp"
#include "./Player/player.hpp"
#include "./Own_Random_Libary/own_random_libary.hpp"
#include <iostream>

int main(){
    array<Community_cest_Chance, 16> test1 = Chance();
    array<Community_cest_Chance, 16> test2 = Community_Chest();
    int i = 2;
    Player player[i];
    player[0].Benennen("test1");
    player[1].Benennen("test2");
    std::cout << player[1].Besitzerauslesen() << "\n";
    return 0;
}
