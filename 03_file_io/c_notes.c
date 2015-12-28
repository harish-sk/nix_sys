#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
  /* Following functions are covered 
     1. open
     2. creat
     3. read
     4. write
     6. close
  */
  int fd_a, fd_b;
  int temp;
  char *str = "Good Morning\n";

  /* First lets create a new file a.txt 
     If file a.txt exists then it is truncated to size 0
     and opened for Write Only
   */
  fd_a = creat("a.txt", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  /* Same thing of opening could also be achived by
     fd_a = open("a.txt", O_WRONLY | O_CREAT | O_TRUNC, 
                 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
     hence mostly creat is a redundant call.
  */
  if(fd_a < 0) {
    perror("cannot create a.txt");
    exit(1);
  }
  printf("created file a.txt; fd_a is %d\n", fd_a);

  /* Write content of str to file fd_a */
  if((temp = write(fd_a, str, strlen(str))) < 0){
    perror("cannot write to a.txt");
    exit(1);
  }
  /* write returns number of bytes sucessfully written */
  printf("written %d bytes to fd_a\n", temp);
  
  /* close the file
   */
  if(close(fd_a) < 0){
    perror("cannot close a.txt");
    exit(1);
    /* Note that generally return value of close is ignored.
       BUT following error might be returned
       1. EBADF - fd isn't a valid open file descriptor
       2. EINTR - close was interupted by signal
       3. EIO - IO error occured.
    */
  }
  /*
    A successful close does not guarantee that the data has been 
    successfully saved to disk, as the kernel defers writes.
    If you want to make sure that data is stored then use flush
  */
  return 0;
}
