#include "game_logic.h"

//using an initilizer list to avoid extra copied on assignment
GameLogic::GameLogic(Position snake_starting_position)
    :m_snake(snake_starting_position),
    m_game_board(),
    m_food_position(),
    m_game_over(false)
{
    m_spawnFood();
}

