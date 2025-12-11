#pragma once
#include <array>
#include "shared_types.h"

//int MAX_ROWS = 3;
//int MAX_COLS = 3;


class GameBoard
{
    public:
        static const int m_board_rows = 3; //has to also be static to work in the board array, refresh static behavior
        static const int m_board_cols = 3;

        GameBoard();
        void m_set_cell(Position& cell_position, Celltype cell_type); 
        Celltype m_get_cell(const Position& position) const;
        void m_print_board();
    
    private:
        std::array<std::array<Celltype, m_board_cols>, m_board_rows> cells;// array 1 = cols, array 2 = rows 
};