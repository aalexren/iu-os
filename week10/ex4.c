#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

int main() {
   DIR *dp;
   struct dirent *entry;
   struct dirent *links[10];

   int count = 0;
   dp = opendir("tmp");
   while ((entry = readdir(dp)) != NULL) {
      links[count] = entry;
      count++;
   }

   closedir(dp);
   for (int i = 0; i < count; ++i) {
      int link = 0;
      for (int j = 0; j < count; ++j) {
         if (links[i]->d_ino == links[j]->d_ino) {
            link++;
         }
      }
      if (link >= 2) {
         printf("%s --- ", links[i]->d_name);
         for (int j = 0; j < count; ++j) {
            if (links[i]->d_ino == links[j]->d_ino)
               printf("%s, ", links[j]->d_name);
         }
         printf("\n");
      }
   }

   return 0;
}
