#include <stdio.h>
#include <ctype.h>

void swap(int *lhs, int *rhs) {
   int save = *lhs;
   *lhs = *rhs;
   *rhs = save;
}

int main() {

   int frst, scnd;

   printf("Enter the first number: ");
   if (!(scanf("%d", &frst) == 1)) {
      printf("There are not of type integer...");
      return 0;
   }
   printf("Enter the second number: ");
   if (!(scanf("%d", &scnd) == 1)) {
      printf("There are not of type integer...");
      return 0;
   }

   printf("before swap first: %d, second: %d\n", frst, scnd);

   swap(&frst, &scnd);

   printf("after  swap first: %d, second: %d", frst, scnd);

   return 0;
}
