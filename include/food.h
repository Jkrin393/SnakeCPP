#include "shared_types.h"
#pragma once

class Food
{
    private:
        Position m_food_location;

    public:
        Food();
        void m_spawn_food();
        Position m_get_food_position();
        
        //testing
        void m_print_food();

};