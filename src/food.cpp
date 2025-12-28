#include "food.h"
#include <random>
#include <iostream>

//https://cplusplus.com/reference/random/   --- https://stackoverflow.com/questions/29549873/stdmt19937-doesnt-return-random-number
//using mersenne-twister, a common generator for random number strings
/*steps to get random locations for food
1) generate random seed from hardware
2) create an instance of a Mersenne-Twister-Engine
3) define a range for the generated numbers to fit into, looks like a function call but the uniform_int_distribution object is overloaded to narrow the range
4) generate a random number from the string by "calling" distribution with the gen_64 mersenne object
*/

std::random_device rand_seed;
std::mt19937_64  gen_64(rand_seed()); 
std::uniform_int_distribution<int> distribution(0,7);//len of hardcoded row/col in game_board

Food::Food()
    :
    m_food_location{-1,-1}
{
}
void Food::m_spawnFood()
{
    m_food_location.m_xvalue = distribution(gen_64);
    m_food_location.m_yvalue = distribution(gen_64); 
    //m_food_location{2,2};
}

Position Food::m_getFoodPosition()
{
    return m_food_location;
}

void Food::m_printFood()
{
    Position loc{m_getFoodPosition()};
    std::cout<<"the food is at, x:" <<loc.m_xvalue<<"y: "<<loc.m_yvalue<<std::endl;
}



