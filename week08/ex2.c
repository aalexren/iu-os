#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
 * It occupies some memory, e.g. 10 Mb
 * and free space is decreasing during the runtime.
 * (Cause we don't call free)
*/

/*
 * top command shows also memory process occupied, CPU loading,
 * due to memory allocation, and cpu consumption the order of 
 * this proccess in output tends to first place.
*/

int main() {
   for (int i = 0; i < 10; i++) {
      printf("#%d allocation of memory\n", i);
      int* a = malloc(sizeof(int) * 250000 * 10);
      memset(a, 0, sizeof(int) * 250000 * 10);
      sleep(1);
   }

   return 0;
}
