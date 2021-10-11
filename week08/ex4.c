#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
   struct rusage* info;

   for (int i = 0; i < 10; i++) {
      printf("#%d allocation of memory\n", i);
      printf("System time used = %ld.%06ld\n", info->ru_stime.tv_sec, info->ru_stime.tv_usec);
      printf("max resident set size: %ld\n", info->ru_maxrss);
      printf("integral shared text memory size: %ld\n", info->ru_ixrss);
      printf("integral unshared data size: %ld\n", info->ru_idrss);
      printf("integral unshared stack size: %ld\n", info->ru_isrss);
      int* a = malloc(sizeof(int) * 250000);
      memset(a, 0, sizeof(int) * 250000);
      getrusage(RUSAGE_SELF, info);
      sleep(1);
   }

   return 0;
}
