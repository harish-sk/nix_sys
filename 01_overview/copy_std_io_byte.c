#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
  int c;

  while((c = getc(stdin)) != EOF){
    if(putc(c, stdout) == EOF) {
      perror("output error");
      exit(1);
    }
  }
  if(ferror(stdin)){
    perror("output error");
    exit(1);
  }
  return 0;
}
