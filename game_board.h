#pragma once
#include <array>

//int MAX_ROWS = 3;
//int MAX_COLS = 3;

enum class Celltype :char 
{
    CELL_EMPTY = 'e',
    CELL_SNAKE = 's',
    CELL_FOOD = 'f'
    
};
struct Position
{
    int m_xvalue;
    int m_yvalue;
    
    bool operator == (const Position second_position) const
    {
        return m_xvalue ==second_position.m_xvalue && m_yvalue == second_position.m_yvalue;
    }
};

class GameBoard
{
    public:
        static const int m_board_rows = 3; //has to also be static to work in the board array, refresh static behavior
        static const int m_board_cols = 3;

        GameBoard();
        void m_set_cell(Position& set_cell_position, Celltype set_cell_type) const;
        Celltype m_get_cell(const Position& position);
        void m_print_board();
    
    private:
        std::array<std::array<Celltype, m_board_cols>, m_board_rows> cells;// array 1 = cols, array 2 = rows 
};