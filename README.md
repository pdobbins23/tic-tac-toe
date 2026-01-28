# Tic-Tac-Toe Implementation

## Additions - Peter Dobbins

**NOTE:** I developed this on Linux (NixOS).

To build the project, run:

```
cmake -B build

cmake --build build
```

- Fixed `actionForEmptyHolder` logic to correctly check if holder is empty
- Added game-over check to prevent moves after win/draw
- Implemented `stopGame` to free memory by destroying all bits
- Implemented `ownerAt` helper to get player at board index
- Implemented `checkForWinner` to detect 3-in-a-row wins
- Implemented `checkForDraw` to detect full board with no winner
- Implemented `stateString` to serialize board state
- Implemented `setStateString` to restore board from saved state
