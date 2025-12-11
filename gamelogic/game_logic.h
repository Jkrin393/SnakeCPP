#include "../snake/snake_logic.h"
#include "../gameboard/game_board.h"
#include "../common/shared_types.h"

#pragma once

class GameLogic
{
    private:
        Snake m_snake;
        GameBoard m_game_board;
        Position m_food_position;
        bool m_game_over;

        void m_spawnFood();
        bool m_isOutsideBounds(const Position& head_location) const;
        bool m_checkCellContents(const Position& position) const;
        
    public:
        GameLogic(Position snake_starting_position);
        void m_updatePositons(Direction snake_direction);
        bool m_checkGameOver() const;
        GameBoard& m_getBoardState() const;
        Snake& m_getSnakeLocation() const;
        Position& m_getFoodLocation() const; 
        void tick();
};




