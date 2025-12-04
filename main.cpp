#include <iostream>
#include "snake_logic.h"

using std::endl;
using std::cout;

int main()
{
    int rows = 3;
    int cols = 3;

    Position starting_position = {2,2};
    Snake snake(starting_position);
    Position second_position = {2,2};
    Position third_position = {2,3};
    
    cout<<(starting_position==second_position)<<endl;
    cout<<(second_position==third_position)<<endl;

    //snake.m_printSnake();

}