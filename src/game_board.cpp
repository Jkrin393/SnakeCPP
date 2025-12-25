#include "game_board.h"
#include <iostream>

//you FOOL!!!! row = y, col = x  
GameBoard::GameBoard()
{
    std::array<Celltype, m_board_cols> empty_row;
    empty_row.fill(Celltype::CELL_EMPTY);
    cells.fill(empty_row);

}
void GameBoard::m_set_cell(Position& cell_position, Celltype cell_type)
{
    if (cell_position.m_xvalue >= 0 && cell_position.m_xvalue < m_board_cols && cell_position.m_yvalue >= 0 && cell_position.m_yvalue < m_board_rows)
    {
        cells[cell_position.m_yvalue][cell_position.m_xvalue] = cell_type;
    }
    else
    {
        std::cerr << "Error: attempted to access out-of-bounds cell at (" << cell_position.m_xvalue << "," << cell_position.m_yvalue << ")\n";
    }
}

Celltype GameBoard::m_get_cell(const Position& position) const
{
    return cells[position.m_yvalue][position.m_xvalue];
}

void GameBoard::m_print_board() const
{
    
    for(int curr_row = 0;curr_row<m_board_rows;curr_row++)
    {
        for(int curr_col =0; curr_col < m_board_cols; curr_col++)
        {
            std::cout << static_cast<char>(cells[curr_row][curr_col]) << ' ';
        }
        std::cout<<std::endl;
    }

}
void GameBoard::m_clear_board()
{
    for(int y{0}; y<GameBoard::m_board_rows;y++)
    {
        for (int x{0};x<GameBoard::m_board_cols;x++)
        {
            Position p{x,y};
            m_set_cell(p, Celltype::CELL_EMPTY);
        }
    }
}