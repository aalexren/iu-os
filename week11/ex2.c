#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

int main() {
   DIR *dp;
   struct dirent *entry;

   dp = opendir("/");
   while ((entry = readdir(dp)) != NULL) {
      printf("--- %s ---\n", entry->d_name);
   }
   closedir(dp);

   return 0;
}
