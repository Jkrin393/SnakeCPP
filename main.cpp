#include <iostream>
#include "snake_logic.h"
#include "game_board.h"
#include "shared_types.h"
#include "game_logic.h"
#include "food.h"

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
            board.m_setCell(p, Celltype::CELL_EMPTY);
        }
    }
    int length{snake.m_getSnakeLength()};
    int head{snake.m_getHeadIndex()};
    int tail{snake.m_getTailIndex()};
    int snake_max_len = snake.m_getSnakeMaxLength();

    for(int i{0};i<length;i++)
    {
        int curr_index{(tail+i)%snake_max_len};
        Position pos{snake.m_getBodyPosition(curr_index)};
        board.m_setCell(pos,Celltype::CELL_SNAKE);
    }

    board.m_printBoard();
}

int main()
{
    
    GameBoard board{};
    //Snake snake({0,0});

    Position pos1{0,0},pos2{1,0},pos3{2,0};
    Celltype test{Celltype::CELL_SNAKE};
    //board.m_setCell(pos1, test);
    //board.m_setCell(pos2, test);
    //board.m_setCell(pos2, test);
    for(int y{0};y<8;++y)
    {
        for(int x{0};x<8;++x)

            board.m_setCell(pos1={x,y},test);
    }


    Position test_pos = board.m_getRandomFreePosition();

    cout<<"Random position is- x: " << test_pos.m_xValue<< " y: " <<test_pos.m_yValue<<endl;

    
    /*
    cout<<"Starting board \n"<<endl;
    draw(snake, board);

    snake.m_move(Direction::Right);
    cout<<"\n move right \n"<<endl;
    draw(snake, board);

    snake.m_grow();
    snake.m_move();
    cout<<"\n grow w/ no input \n"<<endl;
    draw(snake, board);

    cout<<"\n move right after 1 growth \n"<<endl;
    snake.m_move(Direction::Right);
    draw(snake, board);
    
    cout<<"\n move down 2 times: \n"<<endl;
    snake.m_move(Direction::Down);
    snake.m_move(Direction::Down);
    draw(snake, board);
    
    cout<<"\n attempt opposite move(up): \n"<<endl;
    snake.m_move(Direction::Up);
    draw(snake, board);
    */


    

}