#pragma once
#include <array>
#include "shared_types.h"

class GameBoard
{
    public:
        static const int m_board_rows{8}; 
        static const int m_board_cols{8};

        GameBoard();
        void m_set_cell(Position& cell_position, Celltype cell_type); 
        Celltype m_get_cell(const Position& position) const;
        void m_print_board() const;
        void m_clear_board();
    
    private:
        std::array<std::array<Celltype, m_board_cols>, m_board_rows> cells;// array 1 = cols, array 2 = rows 
};