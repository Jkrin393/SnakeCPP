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
    m_snake_body{},
    m_current_direction{Direction::Right}

{
    m_snake_body[0] = starting_position;

};

bool Snake::m_isOppositeDirection(Direction a, Direction b)//logic table at bottom of page
{
    //should evaluate to false unless the directions are one of these 4 cases
    return  (a==Direction::Up && b == Direction::Down)    ||
            (a==Direction::Down && b == Direction::Up)    ||
            (a==Direction::Left && b == Direction::Right) ||
            (a==Direction::Right && b == Direction::Left);
}


void Snake::m_move(Direction input_direction)
{
    //if no input detected snake should continue going the previous direction
    //if input is detected but it is an opposite direction, snake should continue prevous direction
    if(input_direction!=Direction::No_direction && !m_isOppositeDirection(input_direction, m_current_direction))
        Snake::m_current_direction = input_direction;

    Position m_curr_head_location = m_getSnakeHead();
    Position m_next_head_location = m_curr_head_location;
    
    switch (Snake::m_current_direction)
    {
    case Direction::Up    :  m_next_head_location.m_yvalue--; break;
    case Direction::Down  :  m_next_head_location.m_yvalue++; break;
    case Direction::Left  :  m_next_head_location.m_xvalue--; break;
    case Direction::Right :  m_next_head_location.m_xvalue++; break;
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

//collision logic
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

//testing
void Snake::m_printSnake() const
{
    
    for(int i =0; i< m_snake_length; i++)
    {
        Position current_position = m_snake_body[i];
        std::cout<<current_position.m_xvalue << ", " <<current_position.m_yvalue;
    }
    
}



/*Logic table for isOpposite function
    &&
A    |   B   |  isOpposite
Up   |  Down |  true
Down |   Up  |  true
Left | Right |  true
Right| Left  |  true

Up   | L,R,U |  false
Down | L,R,D |  false
Left | U,D,L |  false
Right| U,D.L |  false



*/




