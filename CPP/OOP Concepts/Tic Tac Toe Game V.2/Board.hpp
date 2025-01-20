#ifndef BOARD_HPP
#define BOARD_HPP

class Board
{
private:
    char mat[3][3]; // 3x3 game board
public:
    Board();
    void displayBoard() const;
    bool makeMove(int row, int col, char player);
    bool isFull() const;
    bool checkWinner(char player) const;
    bool isValidMove(int row, int col) const;
};

#endif // BOARD_HPP
