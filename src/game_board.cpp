#include "game_board.h"
#include <iostream>
#include <random>

//you FOOL!!!! row = y, col = x  
GameBoard::GameBoard()
{
    std::array<Celltype, m_board_cols> empty_row;
    empty_row.fill(Celltype::CELL_EMPTY);
    cells.fill(empty_row);

}
void GameBoard::m_setCell(Position& cell_position, Celltype cell_type)
{
    if (cell_position.m_xValue >= 0 && cell_position.m_xValue < m_board_cols && cell_position.m_yValue >= 0 && cell_position.m_yValue < m_board_rows)
    {
        cells[cell_position.m_yValue][cell_position.m_xValue] = cell_type;
    }
    else
    {
        std::cerr << "Error: attempted to access out-of-bounds cell at (" << cell_position.m_xValue << "," << cell_position.m_yValue << ")\n";
    }
}

Celltype GameBoard::m_getCell(const Position& position) const
{
    return cells[position.m_yValue][position.m_xValue];
}

void GameBoard::m_printBoard() const
{
    
    for(int curr_row = 0;curr_row<m_board_rows;curr_row++)
    {
        for(int curr_col =0; curr_col < m_board_cols; curr_col++)
        {
            std::cout << static_cast<char>(cells[curr_row][curr_col]) << ' ';
        }
        std::cout<<std::endl;
    }

}
void GameBoard::m_clearBoard()
{
    for(int y{0}; y<GameBoard::m_board_rows;y++)
    {
        for (int x{0};x<GameBoard::m_board_cols;x++)
        {
            Position p{x,y};
            m_setCell(p, Celltype::CELL_EMPTY);
        }
    }
}

bool GameBoard::m_positionIsEmpty(const Position& position_to_check) const
{
    Celltype curr_cell = m_getCell(position_to_check);
    return curr_cell == Celltype::CELL_EMPTY;
} 

//https://cplusplus.com/reference/random/   --- https://stackoverflow.com/questions/29549873/stdmt19937-doesnt-return-random-number
//using mersenne-twister, a common generator for random number strings
/*steps to get random locations for food
1) generate random seed from hardware
2) create an instance of a Mersenne-Twister-Engine
3) define a range for the generated numbers to fit into, looks like a function call but the uniform_int_distribution object is overloaded to narrow the range
4) generate a random number from the string by "calling" distribution with the gen_64 mersenne object
*/
std::random_device rand_seed;
std::mt19937_64  gen_64(rand_seed()); 
std::uniform_int_distribution<int> distribution(0, GameBoard::m_board_rows-1);

//want to generate random positions while m_positionIsOccupied returns true until it returns false
Position GameBoard::m_getRandomFreePosition() const
{
    Position temp_position{-1, -1};
    int attempts = GameBoard::m_board_rows*GameBoard::m_board_cols;

    for (int i{0};i<attempts;++i)
    {
        temp_position.m_xValue=distribution(gen_64);
        temp_position.m_yValue=distribution(gen_64);
        if(m_positionIsEmpty(temp_position))
            return temp_position;
    } 
    //if board is full return some notice to the calling funciton, for now Position -1,-1
    return temp_position={-1,-1};
}

