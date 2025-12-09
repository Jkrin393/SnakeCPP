#include "game_board.h"
#include "snake_logic.h" 

#include <iostream>


GameBoard::GameBoard()
{
    //fill() instead of nested loop
    std::array<Celltype, m_board_cols> empty_row;
    empty_row.fill(Celltype::CELL_EMPTY);
    cells.fill(empty_row);

}
void GameBoard::m_set_cell(Position& cell_position, Celltype cell_type)
{
    cells[cell_position.m_xvalue][cell_position.m_yvalue] = cell_type;
}

void GameBoard::m_print_board()
{
    int curr_row, curr_col;
    for(curr_row = 0;curr_row<m_board_rows;curr_row++)
    {
        for(curr_col =0; curr_col < m_board_cols; curr_col++)
        {
            std::cout << static_cast<char>(cells[curr_row][curr_col]) << ' ';
        }
        std::cout<<std::endl;
    }

}