#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "game.h"

#define NO_WINNER_YET '0'
#define BOARD_CELLS 9
#define MAX_CELL_INPUT 1000

#define PLAYER_X 'X'
#define PLAYER_O 'O'

int checkWin(char board[BOARDROWS][BOARDCOLS]);
int cellInputIsValid(char cellInput[], char whosTurn);

int main() {
  
  printf("Welcome to i9's TicTacToe!\n");

  int gameTerminated = 0;

  char winner = NO_WINNER_YET;

  char board[BOARDROWS][BOARDCOLS] = {
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

    fgets(cellInput, sizeof cellInput, stdin);

    if (feof(stdin)) {
      gameTerminated = 1;
      break;
    }

    if (!cellInputIsValid(cellInput, whosTurn)) {
      continue;
    }

    char rowInput = cellInput[0];
    char colInput = cellInput[2];  

    /* start: extract row and col played */
    char rowInputStr[2] = {rowInput, '\0'};
    char colInputStr[2] = {colInput, '\0'};
    int rowNum = atoi(rowInputStr);
    int colNum = atoi(colInputStr);
    /* end: extract row and col played */

    if (board[rowNum][colNum] != ' ') {
      printf("Cell '%s' has been played!\n", cellInput);
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

  if (gameTerminated) {
    printf("\nGame terminated!\n");
  } else if (winner == NO_WINNER_YET)
    printf("Draw Game!\n");
  else
    printf("Player '%c' WINS!\n", winner);

  return 0;
}