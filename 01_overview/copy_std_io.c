#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 128

int main(void)
{
  int n;
  int buf[BUF_SIZE];

  while((n = read(STDIN_FILENO, buf, BUF_SIZE)) > 0) {
    if(write(STDOUT_FILENO, buf, n) != n) {
      perror("write error");
      exit(1);
    }
  }
  if(n < 0) {
    perror("write error");
    exit(1);
  }
  return 0;
}
