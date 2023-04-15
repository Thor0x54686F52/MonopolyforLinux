#include "own_random_libary.hpp"

int Random(int max) {
    static std::random_device e{};
    return std::uniform_int_distribution<int>{0, max - 1}(e);
}

std::vector<int> Mix_vector(int max, std::vector<int> mixingvector) {
    int card_value;
    for(int i = 0; i < max; i++) {
        card_value = Random(max);
        card_value--;
        for(int j = 0; j < i; j++) { //looks if a index is already in use
            if(card_value == mixingvector[j]) {
                card_value = Random(max);
                card_value--;
                j = -1;
            }
        }
        mixingvector.push_back(card_value);
    }
    return mixingvector;
}

std::vector<int> Rolling_Dice() {
    std::vector<int> dice_vector;
    int dice1 = Random(6) + 1;
    int dice2 = Random(6) + 1;

    dice_vector.push_back(dice1 + dice2);
    if(dice1 == dice2) {
        dice_vector.push_back(1);
    }
    else {
        dice_vector.push_back(0);
    }
    return dice_vector;
}