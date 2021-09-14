#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

char *args[1000];
int argc;

void get_args(char *str, char delim) {
   char *token;
   char *iter = str;
   char del[2] = {delim, 0};
   int size = 0;

   /* count number of words in string */
   while (*iter != '\0') {
      if (delim == *iter) {
         size++;
      }
      iter++;
   }
   size++;

   size = size + 1; // for NULL pointer to indicate the end of arguments
   
   for (int i = 0 ; i < 1000; ++i) {
      args[i] = NULL;
   }

   /* split string */
   int index = 0;
   token = strtok(str, del);
   while (token != NULL) {
      args[index] = token;
      token = strtok(NULL, del);
      index++;
   }
   args[size-2][strlen(args[size-2]) - 1] = '\0'; // to delete newline symbol from the last token

   /* if background indicator, then delete it as argument */
   if (size > 1 && strstr(args[size - 2], "&")) {
      args[size - 2] = 0;
      size--;
   }

   argc = size;
}

int main() {
   char* cmd;

   printf("To exit from shell enter the q...\n");
   printf("All commands should not contains newline symbol!\n");

   while (1) {
      
      printf("$ ");
      fgets(cmd, 256, stdin);

      if (strstr(cmd, "exit") != 0) {
         exit(0);
      }
      
      if (strstr(cmd, "&") != 0) {
         pid_t pid = fork(); // to execute in background we fork process and call command there
         if (pid == 0) { // if it's a child proccess
            get_args(cmd, ' ');
            execvp(args[0], args);
         }
      } 
      else {
         pid_t pid = fork(); // to not use system we can just fork it again but for simple command
         if (pid == 0) {
            get_args(cmd, ' ');
            if (argc < 2) exit(0);
            else execvp(args[0], args);
         }
         wait(&pid); // cause it's not a background proccess
      }

      fflush(stdin); // clear buffer to avoid incorrect input
   }

   return 0;
}
