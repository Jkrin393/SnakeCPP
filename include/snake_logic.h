#pragma once
#include "shared_types.h"
#include <optional>


class Snake
{
//MAX_LENGTH must agree with the max board size in game_board header(len x width), for now hardcoded
private:
    static const int MAX_LENGTH = 64;
    int m_head_location;
    int m_tail_location;
    int m_snake_length;
    Direction m_current_direction;

    Position m_snake_body[MAX_LENGTH];
    bool m_is_growing;
 

public:
    Snake(Position starting_position);
    //movement functions
    void m_move(Direction input_direction = Direction::No_direction); 
    void m_grow(){ m_is_growing = true;};
    bool m_isOppositeDirection(Direction a, Direction b);

    //getters
    Position m_getSnakeHead() const {return m_snake_body[m_head_location];};//returns Position of head
    Position m_getSnakeTail() const {return m_snake_body[m_tail_location];};//returns Position of tail
    int m_getHeadIndex() const { return m_head_location; }; //returns INDEX of head in the Snake's circular array
    int m_getTailIndex() const { return m_tail_location; }; //returns INDEX of tail in the Snake's circular array
    int m_getSnakeLength() const { return m_snake_length;};
    Position m_getBodyPosition(int index) const { return m_snake_body[index];};//returns Position of body at index

    //collisions
    bool m_selfCollisionDetected() const;
    bool m_borderCollisionDetected() const;


    //testing
    void m_setSnakeLen(int length){ m_snake_length = length;};
    void m_printSnake() const;
    int m_getSnakeMaxLength() const {return MAX_LENGTH;};
};

