#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

DIR * my_opendir(char *path) {
  DIR *val = opendir(path);
  if (!val) {
    printf("error %d: %s", errno, strerror(errno));
    return 0;
  }
  return val;
}

struct dirent * my_readdir(DIR *dir) {
  struct dirent *val = readdir(dir);
  if(!val) {
    printf("error %d: %s", errno, strerror(errno));
    return 0;
  }
  return val;
}

// int my_sscanf(idk what to put for inputs);

int main(int argc, char *argv[]) {
  DIR *inputdir = my_opendir(argv[2]);
  char *inputpath = argv[2];
  // printf("argv[2] = %s\n", argv[2]);
  // struct dirent *dir = readdir(inputdir);
  struct dirent *dir;
  struct stat *stats;
  // stat(dir->d_name, stats);
  // printf("stats: %u\n", stats->st_mode);

  while(1) {
    char curfilepath[100];
    dir = my_readdir(inputdir);
    if(!dir) break;
    int curfilepatherr = sscanf(curfilepath, "%s/%s", inputpath, dir->d_name);
    if(!curfilepatherr) {
      printf("curfilepatherr %d\n", curfilepatherr);
      printf("error %d: %s\n", errno, strerror(errno));
    }

    printf("\tfilename: %s\tpath: %s\n", dir->d_name, curfilepath);
    stat(dir->d_name, stats);
    printf("stats: %u\n", stats->st_mode);
  }

  // stat(strcat(argv[2], dir->d_name), stats);
  // printf("%s\n", strcat(argv[2], dir->d_name));
  // printf("dir %s\n", (dir + stats->st_size)->d_name);
  printf("\n");
  // printf("Total Directory Size: %ld\n", stats->st_size);
  return 0;
}
