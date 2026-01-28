# Tic-Tac-Toe Implementation

## Changes Made

- Fixed `actionForEmptyHolder` logic to correctly check if holder is empty
- Added game-over check to prevent moves after win/draw
- Implemented `stopGame` to free memory by destroying all bits
- Implemented `ownerAt` helper to get player at board index
- Implemented `checkForWinner` to detect 3-in-a-row wins
- Implemented `checkForDraw` to detect full board with no winner
- Implemented `stateString` to serialize board state
- Implemented `setStateString` to restore board from saved state
