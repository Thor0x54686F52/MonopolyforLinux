#include "own_random_libary.hpp"

int Random(int max) {
    static std::random_device e{};
    return std::uniform_int_distribution<int>{0, max - 1}(e);
}

std::vector<int> Mix_vector(int max) {
    std::vector<int> mixingvector;
    int card_value;
    for(int i = 0; i < max; i++) {
        card_value = Random(max);
        for(int j = 0; j < i; j++) { //looks if a index is already in use
            if(card_value == mixingvector[j]) {
                card_value = Random(max);
                j = -1;
            }
        }
        mixingvector.push_back(card_value);
    }
    return mixingvector;
}
