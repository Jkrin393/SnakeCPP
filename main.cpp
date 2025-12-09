#include <iostream>
#include "snake_logic.h"
#include "game_board.h"

using std::endl;
using std::cout;

int main()
{
    int rows = 3;
    int cols = 3;

    Position starting_position = {1,1};
    Snake snake(starting_position);
    Position second_position = {2,2};
    Position third_position = {2,3};
    
    
    

    
   // cout<<(starting_position==second_position)<<endl;
    //cout<<(second_position==third_position)<<endl;

    //snake.m_printSnake();
    GameBoard board;
    board.m_set_cell(starting_position, Celltype::CELL_SNAKE);
    board.m_print_board();


}