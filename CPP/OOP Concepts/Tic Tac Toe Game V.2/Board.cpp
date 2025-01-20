#include <iostream>
#include "Board.hpp"

Board::Board()
{
    // Initialize the board with numbers 1 to 9
    char c = '1';
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat[i][j] = c++;
        }
    }
}

void Board::displayBoard() const
{
    std::cout << "---------\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout << "| ";
        for (int j = 0; j < 3; j++)
        {
            std::cout << mat[i][j] << " ";
        }
        std::cout << "|\n";
    }
    std::cout << "---------\n";
}

bool Board::makeMove(int row, int col, char player)
{
    if (isValidMove(row, col))
    {
        mat[row][col] = player;
        return true;
    }
    return false;
}

bool Board::isFull() const
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (mat[i][j] != 'X' && mat[i][j] != 'O')
            {
                return false;
            }
        }
    }
    return true;
}

bool Board::checkWinner(char player) const
{
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++)
    {
        if ((mat[i][0] == player && mat[i][1] == player && mat[i][2] == player) ||
            (mat[0][i] == player && mat[1][i] == player && mat[2][i] == player))
        {
            return true;
        }
    }
    if ((mat[0][0] == player && mat[1][1] == player && mat[2][2] == player) ||
        (mat[0][2] == player && mat[1][1] == player && mat[2][0] == player))
    {
        return true;
    }
    return false;
}

bool Board::isValidMove(int row, int col) const
{
    return mat[row][col] != 'X' && mat[row][col] != 'O';
}
