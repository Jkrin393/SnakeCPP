#include <iostream>
#include "snake_logic.h"
#include "game_board.h"
#include "shared_types.h"

using std::endl;
using std::cout;

int main()
{
    int rows = 3;
    int cols = 3;

    Position starting_position = {1,1};
    Snake snake(starting_position);


    
   // cout<<(starting_position==second_position)<<endl;
    //cout<<(second_position==third_position)<<endl;

    //snake.m_printSnake();
    GameBoard board;
    board.m_set_cell(starting_position, Celltype::CELL_SNAKE);
    
    Position m_curr_head_location = snake.m_getSnakeHead();
    board.m_print_board();
    cout<<endl;
    snake.m_move(Direction::Up);
    m_curr_head_location = snake.m_getSnakeHead();
    board.m_set_cell(m_curr_head_location, Celltype::CELL_SNAKE);
    board.m_print_board();


}