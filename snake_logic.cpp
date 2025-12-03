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

