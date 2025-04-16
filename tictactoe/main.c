#include <stdio.h>

#include "game.h"

#define NO_WINNER_YET '0'
#define BOARD_CELLS 9
#define MAX_CELL_INPUT 4

#define PLAYER_X 'X'
#define PLAYER_O 'O'

int checkWin(char board[BOARD_ROWS][BOARD_COLS]);
int cellInputIsValid(char *cellInput, char whosTurn);

int main() {
  
  printf("Welcome to i9's TicTacToe!\n");

  int gameTerminated = 0;

  char winner = NO_WINNER_YET;

  char board[BOARD_ROWS][BOARD_COLS] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '},
  };

  // playing
  int filledCells = 0;
  char whosTurn = PLAYER_X;
  while (filledCells < BOARD_CELLS) {

    printf("Player '%c': ", whosTurn);

    char cellInput[MAX_CELL_INPUT];

    scanf("%s", cellInput);

    if (feof(stdin)) {
      gameTerminated = 1;
      break;
    }

    if (!cellInputIsValid(cellInput, whosTurn)) {
      continue;
    }

    // extract cell played

    int rowNum;
    int colNum;

    sscanf(cellInput, "%d,%d", &rowNum, &colNum);

    if (!board[rowNum][colNum]) {
      printf("Invalid cell '%d,%d'! What's that?\n", rowNum, colNum);
      continue;
    }

    if (board[rowNum][colNum] != ' ') {
      printf("Cell '%d,%d' has been played!\n", rowNum, colNum);
      continue;
    }

    // play
    board[rowNum][colNum] = whosTurn;

    int aWin = checkWin(board);

    if (aWin) {
      winner = whosTurn;
      break;
    }

    whosTurn = whosTurn == PLAYER_X ? PLAYER_O : PLAYER_X;

    filledCells++;
  }

  if (gameTerminated)
    printf("\nGame terminated!\n");
  else if (winner == NO_WINNER_YET)
    printf("Draw Game!\n");
  else
    printf("🏆 Player %c wins! 🏆\n", winner);

  return 0;
}