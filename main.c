#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

DIR * my_opendir(char *path) {
  DIR *d = opendir(path);
  if(!d) {
    printf("error %d: %s", errno, strerror(errno));
    return 0;
  }
  return d;
}

int main(int argc, char *argv[]) {
  DIR *inputdir = my_opendir(argv[0]);
  struct dirent *directories = readdir(inputdir);
  printf("dir %s", directories->d_name);
  return 0;
}
