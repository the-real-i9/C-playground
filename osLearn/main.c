#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define READ_LEN 200

int main(int argc, const char *argv[]) {
  
  int fd;

  fd = open("./main.c", O_RDONLY);

  if (fd == -1) {
    fprintf(stderr, "error opening file\n");
    return 1;
  }
  
  char buf[READ_LEN];

  int rdstat;
  rdstat = read(fd, &buf, sizeof(buf));

  if (rdstat == -1) {
    fprintf(stderr, "error reading file\n");
    return 1;
  }

  int i = 0;
  while (i < READ_LEN) {

    if (*(buf + i) == EOF) {
      continue;
    }
    printf("%c", *(buf + i));

    i++;
  }

  printf("\n");

  return 0;
}
