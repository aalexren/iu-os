#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char* cmd;

   printf("To exit from shell enter the q...\n");
   printf("All commands should not contains newline symbol!\n");

   while (1) {
      printf("$ ");
      scanf("%[^\n]", cmd);
      if (strcmp(cmd, "q") == 0) return 0;
      fflush(stdin); // clear buffer for scanf
      //printf("$ \n %s", cmd);
      system(cmd);
   }

   return 0;
}
