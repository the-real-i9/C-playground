#include <stdio.h>

struct person {
  char *firstname;
  char *lastname;
};


int main(int argc, char const *argv[]) {
  
  struct person p1 = {"Kenny", "Sammy"};

  printf("%s %s\n", p1.firstname, p1.lastname);

  return 0;
}
