#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "game.h"

int cellInputIsValid(char *cellInput, char whosTurn) {

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