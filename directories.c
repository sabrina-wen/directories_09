#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

int main() {
  DIR * d;
  d = opendir("/");
  printf("Statistics of directory: .\n");
  struct dirent * entry;
  entry = readdir(d);
  closedir(d);

  return 0;
}
