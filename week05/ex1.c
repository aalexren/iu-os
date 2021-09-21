#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *myThread(void *arg) {
   printf("  >>Hello from Thread #%d!\n", *((int *)arg));
   pthread_exit(NULL);
}

int main() {
   int n; 
   pthread_t *threads;

   printf("Enter the number of threads: ");
   scanf("%d", &n);
   threads = (pthread_t *)malloc(sizeof(pthread_t) * n);

   for (int i = 0; i < n; ++i) {
      if (pthread_create(&threads[i], NULL, myThread, (void *)&i)) {
         printf(" >>ERROR IN CREATING Thread\n!");
         pthread_exit(NULL);
         return 1;
      }
      else {
         printf(" >>Thread #%d created!\n", i);
         pthread_join(threads[i], NULL);
      }
   }

   pthread_exit(NULL);

   return 0;
}
