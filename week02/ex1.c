#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
   int int_var = INT_MAX;
   float flo_var = FLT_MAX;
   double dou_var = DBL_MAX;

   printf("Maximum integer – size: %ld, value: %d\n", sizeof(int), int_var);
   printf("Maximum float – size: %ld, value: %g\n", sizeof(float), flo_var);
   printf("Maximum double – size %ld, value: %g\n", sizeof(double), dou_var);

   return 0;
}
