#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
   
   for (int i = 0; i < 5; ++i) {
      fork();
   }
   sleep(5);

   return 0;
}

/* 
 * The parent process and child share some memory segments.
 * Therefore the loop counter remains the changed for every new child process.
 * E.g. if parent reachs 2, than child can execute just one more time.
 * And what about number of forked processes? In the total it will be 2^n - 1 (excluding original one).
 */
