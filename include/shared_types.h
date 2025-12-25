
//header file to store anything shared between classes to ensure encapsulation/seperation of duties(Position/Celltype started in GameBoard)
//dont like the name of this file but can't think of a better one atm
#pragma once

enum class Celltype :char 
{
    CELL_EMPTY = 'e',
    CELL_SNAKE = 's',
    CELL_FOOD = 'f',
    //CELL_EDGE = '|', 
    //CELL_TOP_BOTTOM_EDGE = '-',
    
};
struct Position
{
    int m_xvalue;
    int m_yvalue;
    
    bool operator == (const Position& second_position) const
    {
        return m_xvalue ==second_position.m_xvalue && m_yvalue == second_position.m_yvalue;
    }
};
enum class Direction 
{
    Up,
    Down,
    Left,
    Right
}; 