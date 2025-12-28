
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
    int m_xValue;
    int m_yValue;
    
    bool operator == (const Position& second_position) const
    {
        return m_xValue ==second_position.m_xValue && m_yValue == second_position.m_yValue;
    }
};
enum class Direction 
{
    Up,
    Down,
    Left,
    Right,
    No_direction
}; 