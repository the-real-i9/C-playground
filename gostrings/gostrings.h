/* This C header file contains exercise implementations of Go's 'strings' package */
#include <string.h>

void clone(char* dest, char *str) {
  while(*dest++ = *str++);
}

int contains(char *s, char *substr) {
  if(strstr(s, substr))
    return 1;
  
  return 0;
};