#pragma once
#include <array>
#include "shared_types.h"
#include "snake_logic.h"

class GameBoard
{
    public:
        static const int m_board_rows{8}, m_board_cols{8}; //move  to private after testing
        
        GameBoard();
        void m_setCell(Position& cell_position, Celltype cell_type); 
        Celltype m_getCell(const Position& position) const;
        void m_printBoard() const;
        void m_clearBoard();
        Position m_getRandomFreePosition(const Snake& snake);
    
    private:
        std::array<std::array<Celltype, m_board_cols>, m_board_rows> cells;// array 1 = cols, array 2 = rows 
};