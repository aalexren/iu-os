#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
   pid_t pid;
   pid = fork(); // get id of child proccess in the original one
   
   int n = 10;
   for (int i = 0; i <= n; ++i) {
      if (pid > 0) {
         printf("Hello from parent [%d - %d]\n", pid, i);
      }
      else if (pid == 0) {
         printf("Hello from child [%d - %d]\n", pid, i);
      }
      else {
         return EXIT_FAILURE;
      }
   }

   return EXIT_SUCCESS;
}
/*
 * The original proccess will fork proccess and get its pid;
 * The thing is that for understanding proccess for itself has 0 pid, while
 * the child proccess has another pid; That's why when we see 0 in pid
 * it means the child proccess, and when we get non-zero value it means we are in the parent proccess for the previous one.
 * It's relative thing between parent and child.
 */
