#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "game.h"

int cellInputIsValid(char cellInput[], char whosTurn) {

  // strip new line from input
  cellInput[strlen(cellInput)-1] = '\0';

  /* start: check for invalid cell input patterns */
  if (strlen(cellInput) == 0) {
    printf("Play something '%c'?!\n", whosTurn);
    return 0;
  }

  
  if (strlen(cellInput) != 3) {
    printf("Invalid cell input format %s. Valid format is: ROWNUM,COLNUM\n", cellInput);
    return 0;
  }
  
  char sepInput = cellInput[1];

  if (sepInput != ',') {
    printf("Invalid cell input format %s. Valid format is: ROWNUM,COLNUM\n", cellInput);
    return 0;
  }

  char rowInput = cellInput[0];
  char colInput = cellInput[2];

  if (rowInput != '0' && rowInput != '1' && rowInput != '2') {
    printf("Invalid ROWNUM '%c'. Expected 0, 1, or 2\n", rowInput);
    return 0;
  }

  if (colInput != '0' && colInput != '1' && colInput != '2') {
    printf("Invalid COLNUM '%c'. Expected 0, 1, or 2\n", rowInput);
    return 0;
  }

  return 1;
}

void extCellPlayed(int cell [2], char cellInput[]) {
  char rowInput = cellInput[0];
  char colInput = cellInput[2];  

  char rowInputStr[2] = {rowInput, '\0'};
  char colInputStr[2] = {colInput, '\0'};

  cell[CELL_ROW] = atoi(rowInputStr);
  cell[CELL_COL] = atoi(colInputStr);
}