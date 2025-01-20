#include "TicTacToe.hpp"
#include <iostream>
#include <algorithm>

TicTacToe::TicTacToe() : board(3, std::vector<char>(3)), currentPlayer(Player::X)
{
    initializeBoard();
}

void TicTacToe::playGame()
{
    while (true)
    {
        displayBoard();
        if (makeMove())
        {
            displayBoard();
            auto result = checkWinner();
            if (result.has_value())
            {
                announceResult(result.value());
                break;
            }
            switchPlayer();
        }
    }
}

void TicTacToe::initializeBoard()
{
    char position = '1';
    for (auto &row : board)
    {
        for (auto &cell : row)
        {
            cell = position++;
        }
    }
}

void TicTacToe::displayBoard() const
{
    std::cout << "\nCurrent Board:\n";
    std::cout << "-------------\n";
    for (const auto &row : board)
    {
        std::cout << "| ";
        for (const auto &cell : row)
        {
            std::cout << cell << " ";
        }
        std::cout << "|\n";
    }
    std::cout << "-------------\n";
}

bool TicTacToe::makeMove()
{
    char position;
    std::cout << "Player " << getPlayerSymbol(currentPlayer) << ", enter your position: ";
    std::cin >> position;

    for (auto &row : board)
    {
        for (auto &cell : row)
        {
            if (cell == position)
            {
                cell = getPlayerSymbol(currentPlayer);
                return true;
            }
        }
    }

    std::cout << "Invalid position or already taken. Try again.\n";
    return false;
}

std::optional<char> TicTacToe::checkWinner() const
{
    for (int i = 0; i < 3; ++i)
    {
        if (allEqual(board[i][0], board[i][1], board[i][2]))
            return board[i][0];
        if (allEqual(board[0][i], board[1][i], board[2][i]))
            return board[0][i];
    }

    if (allEqual(board[0][0], board[1][1], board[2][2]))
        return board[0][0];
    if (allEqual(board[0][2], board[1][1], board[2][0]))
        return board[0][2];

    if (std::all_of(board.begin(), board.end(), [](const std::vector<char> &row)
                    { return std::all_of(row.begin(), row.end(), [](char cell)
                                         { return cell == 'X' || cell == 'O'; }); }))
    {
        return 'D';
    }

    return std::nullopt;
}

void TicTacToe::announceResult(char result) const
{
    if (result == 'D')
    {
        std::cout << "The game is a draw!\n";
    }
    else
    {
        std::cout << "Player " << result << " is the winner!\n";
    }
}

void TicTacToe::switchPlayer()
{
    currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;
}

char TicTacToe::getPlayerSymbol(Player player)
{
    return (player == Player::X) ? 'X' : 'O';
}

bool TicTacToe::allEqual(char a, char b, char c)
{
    return a == b && b == c && (a == 'X' || a == 'O');
}
