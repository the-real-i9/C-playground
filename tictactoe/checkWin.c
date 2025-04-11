#include "game.h"

#define WINCOMBOS 8
#define WINCELLS 3
#define CELLRC 2

int winCombos[WINCOMBOS][WINCELLS][CELLRC] = {
  {{0,0}, {0,1}, {0,2}},
  {{1,0}, {1,1}, {1,2}},
  {{2,0}, {2,1}, {2,2}},

  {{0,0}, {1,0}, {2,0}},
  {{0,1}, {1,1}, {2,1}},
  {{0,2}, {1,2}, {2,2}},

  {{0,0}, {1,1}, {2,2}},
  {{0,2}, {1,1}, {2,0}},
};

int checkWin(char board[BOARDROWS][BOARDCOLS]) {
  int winRow;
  
  for (winRow = 0; winRow < WINCOMBOS; winRow++) {
    
    int winCell0R = winCombos[winRow][0][0];
    int winCell0C = winCombos[winRow][0][1];

    int winCell1R = winCombos[winRow][1][0];
    int winCell1C = winCombos[winRow][1][1];

    int winCell2R = winCombos[winRow][2][0];
    int winCell2C = winCombos[winRow][2][1];
    
    char boardCell0 = board[winCell0R][winCell0C];
    char boardCell1 = board[winCell1R][winCell1C];
    char boardCell2 = board[winCell2R][winCell2C];

    if (boardCell0 != ' ' && boardCell0 == boardCell1 && boardCell1 == boardCell2) {
      return 1;
    }
  }

  return 0;
}