//attempting to use only stack memory with 0 copies and 0 moves, per vid by TheCherno "https://www.youtube.com/watch?v=Xx-NcqmveDc"
#include <iostream>
#include "snake_logic.h"

Snake::Snake(Position starting_position)
{
    m_snake_body[0] = starting_position;
    m_head_location = 0;
    m_tail_location = 0;
    m_snake_length = 1;
    m_is_growing = false;
}

Position Snake::m_getSnakeHead() const
{
    return m_snake_body[m_head_location];
}

int Snake::m_getSnakeLength() const 
{
    return m_snake_length;

}

void Snake::m_grow()
{
    m_is_growing = true;
}

void Snake::m_printSnake() const
{
    
    for(int i =0; i< m_snake_length; i++)
    {
        Position current_position = m_snake_body[i];
        std::cout<<current_position.m_xvalue << ", " <<current_position.m_yvalue;
    }
    
}
/*
bool Snake::m_collisionDetected() const
{
    Position head = m_getSnakeHead();
    for(int i = 0; i<m_snake_length; i++)
    {
        if (m_head_location==body[i]
    }
    return false;
}
*/


