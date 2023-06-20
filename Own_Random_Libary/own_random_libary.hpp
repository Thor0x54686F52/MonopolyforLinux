#include <random>
#include <vector>

#ifndef DICE_HPP
#define DICE_HPP

// returns an int between 0 and max-1. It is concibated for a randomice a vector
int Random(int max); 

std::vector<int> Mix_vector(int max);

#endif