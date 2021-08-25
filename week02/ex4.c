#include <stdio.h>

void swap(int *lhs, int *rhs) {
   int save = *lhs;
   *lhs = *rhs;
   *rhs = save;
}

int main() {

   int frst, scnd;

   printf("Enter the first number: ");
   scanf("%d", &frst);
   printf("Enter the second number: ");
   scanf("%d", &scnd);

   printf("before swap first: %d, second: %d\n", frst, scnd);

   swap(&frst, &scnd);

   printf("after  swap first: %d, second: %d", frst, scnd);

   return 0;
}
