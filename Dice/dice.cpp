#include "dice.hpp"

int Random(int max) {
    static std::random_device e{};
    return std::uniform_int_distribution<int>{0, max - 1}(e);
}