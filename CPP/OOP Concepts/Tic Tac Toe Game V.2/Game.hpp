#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"

class Game
{
private:
    Board board;
    char currentPlayer;

public:
    Game();
    void startGame();
    void switchPlayer();
};

#endif // GAME_HPP
