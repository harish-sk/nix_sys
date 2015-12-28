#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
  if(lseek(STDIN_FILENO, 0, SEEK_CUR) == -1) {
    perror("cannot seek");
    exit(1);
  }else {
    printf("can seek\n");
  }
  /* 
     files can be seeked
     pipe cannot be seeked
     fifo cannot be seeked
   */
  return 0;
}
