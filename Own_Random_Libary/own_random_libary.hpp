#include <random>
#include <vector>

#ifndef DICE_HPP
#define DICE_HPP

// returns an int between 0 and max-1. It is concibated for a randomice a vector
int Random(int max); 

std::vector<int> Mix_vector(int max);

std::vector<int> Rolling_Dice();
/* the first returnvalue is the sum of the rolled Dices, the second value signals if it was a dice double or not. 
 0 stands for no dice double
 1 stands for a dice double
*/

#endif