#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
   int int_var = INT_MAX;
   float flo_var = FLT_MAX;
   double dou_var = DBL_MAX;

   printf("Maximum integer: %d\n", int_var);
   printf("Maximum float: %f\n", flo_var);
   printf("Maximum double: %f\n", dou_var);

   return 0;
}
