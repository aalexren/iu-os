#include <stdio.h>
#include <stdlib.h>

int main() {
   int *array;
   printf("Enter the number of integers: ");
   int n; scanf("%d", &n);
   array = (int*)malloc(sizeof(int) * n);
   for (int i = 0; i < n; ++i) {
      array[i] = i;
      printf("%d ", array[i]);
   }
   free(array);

   return 0;
}
