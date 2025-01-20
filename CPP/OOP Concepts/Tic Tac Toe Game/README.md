# Tic Tac Toe

A simple and interactive command-line Tic Tac Toe game written in modern C++ with an organized structure for improved readability and scalability.

---

## Features

- **Game Mechanics**: Classic 3x3 Tic Tac Toe gameplay where two players alternate marking spaces on the grid until one wins or the game ends in a draw.
- **Player Interaction**: Easy-to-use prompts for players to input their moves.
- **Winner Detection**:
  - Row-wise, column-wise, and diagonal checks for winner determination.
  - Handles draw scenarios if no moves are left.
- **Grid Display**: Dynamic and clean rendering of the game board after each turn.
- **Error Handling**: Prevents overwriting of already marked spaces with clear feedback.

---

## Example Gameplay

```plaintext
Tic Tac Toe Game

---------
| 1 2 3 |
| 4 5 6 |
| 7 8 9 |
---------

Player X, enter your move: 5

---------
| 1 2 3 |
| 4 X 6 |
| 7 8 9 |
---------

Player O, enter your move: 3

---------
| 1 2 O |
| 4 X 6 |
| 7 8 9 |
---------

...and so on.
```

---

## Future Improvements

- Implement a computer opponent (AI).
- Add support for different grid sizes (e.g., 4x4, 5x5).
- GUI version using a graphics library.
- Persistent score tracking for multiple games.

---

Enjoy the game!

