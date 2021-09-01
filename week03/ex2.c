#include <stdio.h>
#include <stdlib.h>

void swap(int *lhs, int *rhs) {
   int save = *lhs;
   *lhs = *rhs;
   *rhs = save;
}

void bubble_sort(int **array, int size) {
   for (int i = 0; i < size; ++i) {
      for (int j = 0; j < size; ++j) {
         if ((*array)[i] < (*array)[j]) 
            swap(&(*array)[i], &(*array)[j]);
      }
   }
}

int main() {

   int *array = (int *)malloc(sizeof(int) * 4);
   array[0] = 4; array[1] = 2; array[2] = 3; array[3] = 1;
   
   printf("Array before: ");
   for (int i = 0; i < 4; ++i) {
      printf("%d ", array[i]);
   }
   
   // Call Bubble Sort
   bubble_sort(&array, 4);
   
   printf("\nArray after:  ");
   for (int i = 0; i < 4; ++i) {
      printf("%d ", array[i]);
   }

   return 0;
}
