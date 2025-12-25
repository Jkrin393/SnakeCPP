#include <iostream>
#include "snake_logic.h"
#include "game_board.h"
#include "shared_types.h"
#include "game_logic.h"

using std::endl;
using std::cout;
///test functions
void draw(const Snake& snake, GameBoard& board)
{
    for(int y{0}; y<GameBoard::m_board_rows;y++)
    {
        for (int x{0};x<GameBoard::m_board_cols;x++)
        {
            Position p{x,y};
            board.m_set_cell(p, Celltype::CELL_EMPTY);
        }
    }
    int length{snake.m_getSnakeLength()};
    int head{snake.m_getHeadIndex()};
    int tail{snake.m_getTailIndex()};
    
    for(int i{0};i<length;i++)
    {
        int curr_index{(tail+i)%9}; //9 = current hardcoded max snake length
        Position pos{snake.m_getBodyPosition(curr_index)};
        board.m_set_cell(pos,Celltype::CELL_SNAKE);
    }

    board.m_print_board();
}

int main()
{
    GameBoard board{};
    Snake snake({1,1});
    

    cout<<"Starting board"<<endl;
    draw(snake, board);

    snake.m_move(Direction::Right);
    cout<<"move right \n"<<endl;
    draw(snake, board);

    snake.m_grow();
    cout<<"grow \n"<<endl;
    draw(snake, board);

    cout<<"move after grow \n"<<endl;
    snake.m_move(Direction::Right);
    draw(snake, board);

    

}