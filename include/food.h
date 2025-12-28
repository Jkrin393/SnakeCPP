#include "shared_types.h"
#pragma once

class Food
{
    private:
        Position m_food_location;

    public:
        Food();
        void m_spawnFood();
        Position m_getFoodPosition();
        
        //testing
        void m_printFood();

};