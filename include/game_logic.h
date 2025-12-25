#include "game_board.h"
#include "shared_types.h"
#include "snake_logic.h"

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
        const GameBoard& m_getBoardState() const;
        const Snake& m_getSnakeLocation() const;
        const Position& m_getFoodLocation() const; 
        void m_tick();
};




