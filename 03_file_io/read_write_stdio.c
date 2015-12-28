#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE 4096

int main(void)
{
  int n;
  char buf[BUFSIZE];

  while((n = read(STDIN_FILENO, buf, BUFSIZE)) > 0){
    if(write(STDOUT_FILENO, buf, n) != n) {
      perror("write error");
      exit(1);
    }
    if(n < 0) {
      perror("read error");
      exit(1);
    }
  }
  return 0;
}
