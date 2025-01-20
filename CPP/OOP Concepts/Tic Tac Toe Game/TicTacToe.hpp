#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <vector>
#include <optional>

class TicTacToe
{
public:
    TicTacToe();
    void playGame();

private:
    enum class Player
    {
        X,
        O
    };
    std::vector<std::vector<char>> board;
    Player currentPlayer;

    void initializeBoard();
    void displayBoard() const;
    bool makeMove();
    std::optional<char> checkWinner() const;
    void announceResult(char result) const;
    void switchPlayer();
    static char getPlayerSymbol(Player player);
    static bool allEqual(char a, char b, char c);
};

#endif // TICTACTOE_H
