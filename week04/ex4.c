#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

char *args[1000];
int argc;

void get_args(char *str, char delim) {
   // printf("get args: %s\n", str);
   char *token;
   char *iter = str;
   char del[2] = {delim, 0};
   int size = 0;

   while (*iter != '\0') {
      if (delim == *iter) {
         size++;
      }
      iter++;
   }
   size++;

   size = size + 1; // for NULL pointer to indicate the end of arguments
   
   // args = (char**)malloc(sizeof(char*) * size); // general size
   for (int i = 0 ; i < 1000; ++i) {
      args[i] = NULL;
   }

   int index = 0;
   token = strtok(str, del);
   while (token != NULL) {
      args[index] = token;
      token = strtok(NULL, del);
      // printf("%s\n", token);
      index++;
   }
   args[size-2][strlen(args[size-2]) - 1] = '\0'; // to delete newline symbol from the last token

   if (size > 1 && strstr(args[size - 2], "&")) {
      args[size - 2] = 0;
      size--;
   }

   argc = size;

   // for (int i = 0; i < size; ++i) {
   //    printf("%s\n", args[i]);
   // }
   // printf("%d", size);
}

int main() {
   char* cmd;

   printf("To exit from shell enter the q...\n");
   printf("All commands should not contains newline symbol!\n");

   while (1) {
      
      printf("$ ");
      fgets(cmd, 256, stdin);
      // scanf("[^\n]", cmd);
      // printf("%s", cmd);
      
      // get_args(cmd, ' ');
      // char *check_exit = args[0];

      if (strstr(cmd, "exit") != 0) {
         // printf("no");
         exit(0);
      }
      
      // char *check_bg 
      if (strstr(cmd, "&") != 0) {
         // printf("yes");
         pid_t pid = fork();
         if (pid == 0) {
            // fflush(stdout);
            // printf("memes");
            /* remove the & character */
            // char *new_cmd = cmd;
            // new_cmd[strlen(new_cmd)-2] = '\0';
            // new_cmd[strlen(new_cmd)-3] = '\0';
            // memcpy(new_cmd, cmd, strlen(cmd) - 2);
            // int j = strlen(cmd);
            // for (int i = j - 1; i >= j - 3; --i) {
            //    cmd[i] = '\0';
            // }
            // printf("%s %s", cmd, new_cmd);
            
            get_args(cmd, ' ');
            execvp(args[0], args);
            // wait(&pid);
         }
         // else if (pid > 0) {
         //    printf("parent");
         // }
         // else {
         //    printf("error");
         // }
      } 
      else {
         pid_t pid = fork();
         if (pid == 0) {
            get_args(cmd, ' ');
            if (argc < 2) exit(0);
            else execvp(args[0], args);
         }
         wait(&pid);
      }

      fflush(stdin);
   }

   return 0;
}
