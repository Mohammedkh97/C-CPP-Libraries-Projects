# Tic Tac Toe Game

This is a console-based implementation of the classic **Tic Tac Toe** game. It allows two players to take turns and play on a 3x3 grid. The game validates moves, checks for winners, and declares a draw if the board is full without a winner.

## Features

- **2-player gameplay**: Players alternate between 'X' and 'O'.
- **Board display**: The board is rendered after each move, showing the current game state.
- **Move validation**: The game checks if a move is valid (i.e., the spot is not already occupied).
- **Winner detection**: The game checks for a winner after each move by examining rows, columns, and diagonals.
- **Draw detection**: If the board is full and there is no winner, the game declares a draw.

## File Structure

- **`main.cpp`**: The entry point of the program. Manages the game loop.
- **`Board.h` & `Board.cpp`**: Contains the `Board` class responsible for managing the game board, displaying it, and handling player moves.
- **`Game.h` & `Game.cpp`**: Implements the game logic, including alternating players and determining the winner.

## Requirements

- A C++ compiler such as `g++` or `clang++` to compile the code.
- A terminal or command prompt to run the game.

## Compilation and Running

1. Clone the repository or download the files.
2. Open a terminal and navigate to the project directory.
3. Compile the code using the following command:
   ```bash
   g++ -o tictactoe main.cpp Board.cpp Game.cpp
   ```
4. Run the game:
   ```bash
   ./tictactoe
   ```

## How to Play

- The game will prompt each player to enter a row and column number (1-3) for their move.
- Players take turns, and the game will update the board after each move.
- The first player to get 3 of their marks in a row, column, or diagonal wins the game.
- If the board is filled without a winner, the game declares a draw.

## Example of Game Play

```
--------- 
| 1 2 3 | 
| 4 5 6 | 
| 7 8 9 | 
--------- 

Player X, enter your move (row and column): 1 1
--------- 
| X 2 3 | 
| 4 5 6 | 
| 7 8 9 | 
--------- 

Player O, enter your move (row and column): 2 2
--------- 
| X 2 3 | 
| 4 O 6 | 
| 7 8 9 | 
--------- 
...
```

## License

This project is open-source and available under the MIT License.

---

This README file provides all necessary details about the Tic Tac Toe game, including how to set it up, compile it, and play it. You can extend this file with any other relevant information such as acknowledgments or contributions.