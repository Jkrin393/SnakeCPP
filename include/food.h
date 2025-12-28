#include "shared_types.h"
#pragma once

class Food
{
    private:
        Position m_food_location;

    public:
        Food(): m_food_location{-1,-1}{};//initialize to a location not on the board
        Position m_getFoodPosition();
        void m_setFoodLocation(Position food_position){this->m_food_location = food_position;}
        
        //testing
        void m_printFood()
        {
            Position loc{m_getFoodPosition()};
            std::cout<<"the food is at, x:" <<loc.m_xValue<<"y: "<<loc.m_yValue<<std::endl;
        }

        //deprecated
        //void m_spawnFood(); moved to game_logic class, food should not know snake location  

};