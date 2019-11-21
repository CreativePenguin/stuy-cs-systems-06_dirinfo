#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

DIR * my_opendir(char *path) {
  DIR *val = opendir(path);
  if (!val) {
    printf("error %d: %s", errno, strerror(errno));
    exit(1);
  }
  return val;
}

struct dirent * my_readdir(DIR *dir) {
  struct dirent *val = readdir(dir);
  if(!val && !errno) {
    printf("error %d: %s", errno, strerror(errno));
    exit(1);
  }
  return val;
}

void my_stat(char path[255], struct stat *stats) {
  int staterr = stat(path, stats);
  if(staterr < 0) {
    printf("error %d: %s", errno, strerror(errno));
    exit(1);
  }
}

// int my_sscanf(idk what to put for inputs);

int main(int argc, char *argv[]) {
  char inputpath[255];
  if(!argv[2]) {
    printf("Add arguments with ARGV=foldername\n");
    printf("\n");
    printf("Enter folder to search: ");
    fgets(inputpath, 255, stdin);
    printf("\n");
  } else strcpy(inputpath, argv[2]);
  DIR *inputdir = my_opendir(inputpath);
  // printf("argv[2] = %s\n", argv[2]);
  // struct dirent *dir = readdir(inputdir);
  struct dirent *dir = malloc(sizeof(dir));
  // struct dirent *dir;
  struct stat *stats = malloc(sizeof(stat));
  // stat(dir->d_name, stats);
  // printf("stats: %u\n", stats->st_mode);

  while(1) {
    char curfilepath[257];
    char filetype = 'f';
    dir = readdir(inputdir);
    if(!dir) break;
    sprintf(curfilepath, "%s/%s", inputpath, dir->d_name);
    // printf("%s\n", curfilepath);
    my_stat(curfilepath, stats);
    if(stats->st_size == 4096) filetype = 'd';
    printf("%c: %s\t%ld\n", filetype, dir->d_name, stats->st_size);
  }


  // stat(strcat(argv[2], dir->d_name), stats);
  // printf("%s\n", strcat(argv[2], dir->d_name));
  // printf("dir %s\n", (dir + stats->st_size)->d_name);
  printf("\n");

  free(dir);
  free(stats);
  return 0;
}
