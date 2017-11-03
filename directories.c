#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
  DIR * d;
  d = opendir(".");
  printf("Statistics of current directory:\n");

  struct stat file_info;
  stat(".",&file_info);
  printf("Total Directory size: %lld\n", file_info.st_size);

  printf("Directories: \n");
  struct dirent * entry;
  entry = readdir(d);
  while (entry) {
    if (opendir(entry->d_name)) {
      printf("  %s\n", entry->d_name);
    }
    entry = readdir(d);
  }

  printf("Regular files: \n");
  d = opendir(".");
  entry = readdir(d);
  while (entry) {
    if (opendir(entry->d_name) == NULL) {
      printf("  %s\n", entry->d_name);
    }
    entry = readdir(d);
  }
  closedir(d);
  
  return 0;
}
