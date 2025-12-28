#pragma once
#include <array>
#include "shared_types.h"
#include "snake_logic.h"

class GameBoard
{
    public:
        static const int m_board_rows{8}, m_board_cols{8};        
        GameBoard();
        void m_setCell(Position& cell_position, Celltype cell_type);
        bool m_positionIsEmpty(const Position& pos) const; 
        Celltype m_getCell(const Position& position) const;
        void m_printBoard() const;
        void m_clearBoard();
        Position m_getRandomFreePosition() const;
    
    private:
        std::array<std::array<Celltype, m_board_cols>, m_board_rows> cells;// array 1 = cols, array 2 = rows 
};