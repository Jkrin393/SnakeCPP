#pragma once

struct Position
{
    int m_xvalue;
    int m_yvalue;
    
    bool operator == (const Position second_position) const
    {
        return m_xvalue ==second_position.m_xvalue && m_yvalue == second_position.m_yvalue;
    }
};

class Snake
{
//MAX_LENGTH SHOULD agree with the max board size(len x width), for now hardcoded for a 3x3
private:
    static const int MAX_LENGTH = 9;
    int m_head_location;
    int m_tail_location;
    Position m_snake_body[MAX_LENGTH];
    int m_snake_length;
    bool m_is_growing;

public:
    Snake(Position starting_position); //constructor
    Position m_getSnakeHead() const; //note to self, const at the END indicates the function doesnt modify the parameters
    void m_move(Position new_head);
    void m_grow();
    bool m_collisionDetected() const;
    void m_printSnake() const;
    int m_getSnakeLength() const;
};

