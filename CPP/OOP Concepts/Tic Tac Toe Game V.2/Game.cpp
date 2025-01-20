#include <iostream>
#include "Game.hpp"

Game::Game() : currentPlayer('X') {}

void Game::startGame()
{
    int row, col;
    bool gameEnded = false;

    while (!gameEnded)
    {
        board.displayBoard();
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;
        row--;
        col--; // Adjust for 0-based indexing

        if (board.makeMove(row, col, currentPlayer))
        {
            if (board.checkWinner(currentPlayer))
            {
                board.displayBoard();
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                gameEnded = true;
            }
            else if (board.isFull())
            {
                board.displayBoard();
                std::cout << "It's a draw!" << std::endl;
                gameEnded = true;
            }
            else
            {
                switchPlayer();
            }
        }
        else
        {
            std::cout << "Invalid move, try again." << std::endl;
        }
    }
}

void Game::switchPlayer()
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
