#pragma once
#include "shared_types.h"


class Snake
{
//MAX_LENGTH SHOULD agree with the max board size(len x width), for now hardcoded
private:
    static const int MAX_LENGTH = 25;
    int m_head_location;
    int m_tail_location;
    int m_snake_length;

    Position m_snake_body[MAX_LENGTH];
    bool m_is_growing;
 

public:
    Snake(Position starting_position);
    //movement functions
    void m_move(Direction direction);
    void m_grow();

    //getters
    Position m_getSnakeHead() const;//returns Position of head
    Position m_getSnakeTail() const;//returns Position of tail
    int m_getHeadIndex() const; //returns index of head in the Snake's circular array
    int m_getTailIndex() const; //returns index of tail in the Snake's circular array
    int m_getSnakeLength() const;
    Position m_getBodyPosition(int index) const;//returns Position of body at index

    //collisions
    bool m_selfCollisionDetected() const;
    bool m_borderCollisionDetected() const;


    //testing
    void set_snake_len(int length);
    void m_printSnake() const;
};

