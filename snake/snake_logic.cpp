//attempting to use only stack memory with 0 copies and 0 moves, per vid by TheCherno "https://www.youtube.com/watch?v=Xx-NcqmveDc"
//snake should only know about itself and not anything else on the board
#include <iostream>
#include "snake_logic.h"

Snake::Snake(Position starting_position)
    :
    m_head_location(0),
    m_tail_location(0),
    m_snake_length(1),
    m_is_growing(false),
    m_snake_body{}

{
    m_snake_body[0] = starting_position;

};

/*Snake::Snake(Position starting_position)
{
    m_snake_body[0] = starting_position;
    m_head_location = 0;//represnts position in the snake array
    m_tail_location = 0;
    m_snake_length = 1;
    m_is_growing = false;
}
*/

Position Snake::m_getSnakeHead() const
{
    return m_snake_body[m_head_location];
}
Position Snake::m_getSnakeTail() const
{
    return m_snake_body[m_tail_location];
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

void Snake::m_move(Direction direction)
{
    Position m_curr_head_location = m_getSnakeHead();
    Position m_next_head_location = m_curr_head_location;
    
    switch (direction)
    {
    case Direction::Up:    m_next_head_location.m_yvalue--; break;
    case Direction::Down:  m_next_head_location.m_yvalue++; break;
    case Direction::Left:  m_next_head_location.m_xvalue--; break;
    case Direction::Right: m_next_head_location.m_xvalue++; break;
    }

    m_head_location = (m_head_location + 1) % MAX_LENGTH;//place in the circular array
    m_snake_body[m_head_location] = m_next_head_location;

    if(m_is_growing)
    {

        ++m_snake_length;
        m_is_growing = false;
    }
    else
    {
        m_tail_location = (m_tail_location + 1) % MAX_LENGTH;
    }
}


bool Snake::m_selfCollisionDetected() const
{
    int curr_snake_index,i;
    Position head = m_getSnakeHead();
    for(i = 0; i<m_snake_length; i++)
    {
        curr_snake_index = (m_tail_location + 1) % MAX_LENGTH;
        if(m_snake_body[curr_snake_index]==head)
        {
            return true;
        }
    }
    return false;
}



