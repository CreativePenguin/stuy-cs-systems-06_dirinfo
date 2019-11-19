#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

DIR *my_opendir(char *path) {
  DIR *d = opendir(path);
  if (!d) {
    printf("error %d: %s", errno, strerror(errno));
    return 0;
  }
  return d;
}

int main(int argc, char *argv[]) {
  DIR *inputdir = my_opendir(argv[2]);
  // printf("argv[2] = %s\n", argv[2]);
  struct dirent *dir = readdir(inputdir);
  struct stat *stats;

  printf("d %s\n", dir->d_name);
  // stat(strcat(argv[2], dir->d_name), stats);
  // printf("%s\n", strcat(argv[2], dir->d_name));
  // printf("dir %s\n", (dir + stats->st_size)->d_name);
  printf("dir %s\n", (dir + 3)->d_name);
  printf("\n");
  printf("Total Directory Size: %lu\n", dir->d_ino);
  return 0;
}
