#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
  char buf1[] = "abcdefghij";
  char buf2[] = "ABCDEFGHIJ";

  int fd;

  if((fd = creat("file.hole", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0) {
    perror("cannot create file.hole");
    exit(1);
  }
  if(write(fd, buf1, sizeof(buf1)) != sizeof(buf1)) {
    perror("cannot write buf1");
    exit(1);
  }
  if(lseek(fd, 16384, SEEK_SET) == -1){
    perror("lseek error");
    exit(1);
  }
  if(write(fd, buf2, sizeof(buf2)) != sizeof(buf2)) {
    perror("cannot write buf2");
    exit(1);
  }
  return 0;
}
