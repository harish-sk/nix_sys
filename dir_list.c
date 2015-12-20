#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
  DIR *dp;
  struct dirent *dirp;

  /* Check for at least one argument */
  if(argc != 2) {
    fprintf(stderr,"usage: ls directory_name\n");
    exit(0);
  }
  
  if((dp = opendir(argv[1])) == NULL) {
    fprintf(stderr,"Error: Directory %s cannot be opened\n", argv[1]);
    exit(0);
  }
  
  while((dirp = readdir(dp)) != NULL) {
    printf("%s\n", dirp->d_name);
  }
  
  closedir(dp);
  exit(0);
}
