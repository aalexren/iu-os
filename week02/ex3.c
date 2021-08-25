#include <stdio.h>
#include <ctype.h>
#include <string.h>

void square(int n) {
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         putchar('*');
      }
      putchar('\n');
   }
}

void reverse_triangle(int n) {
   for (int i = 0; i < n / 2 + 1; ++i) {
      /* increasing to right */
      for (int j = 0; j < i + 1; ++j) {
         putchar('*');
      }
      putchar('\n');
   }
   for (int i = n / 2; i >= 0; --i) {
      /* decreasing to left */
      for (int j = 0; j < i; ++j) {
         putchar('*');
      }
      putchar('\n');
   }
}

void right_triangle(int n) {
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i + 1; ++j) {
         putchar('*');
      }
      putchar('\n');
   }
}

void triangle(int n) {
   for (int i = 0; i < n; ++i) {
      /* gaps on the left */
      for (int j = 0; j < n - 1 - i; ++j) {
         putchar(' ');
      }
      /* asteriks */
      for (int j = 0; j < 2 * i + 1; ++j) {
         putchar('*');
      }
      /* gaps on the right */
      for (int j = 0; j < n - 1 - i; ++j) {
         putchar(' ');
      }
      putchar('\n');
   }
}

int main(int argc, char* argv[]) {

   if (argc < 2) {
      printf("There is no size parameter...");
      return 0;
   }

   for (int i = 0; i < strlen(argv[1]); ++i) {
      if (!isdigit(argv[1][i])) {
         printf("Argument is not integer...");
         return 0;
      }
   } 

   int n;
   sscanf(argv[1], "%d", &n);
   
   int opt;
   printf("Choose additional option: \n");
   printf("0) Triangle\n1) Right triangle\n2) Reverse triangle\n3) Square\n");
   printf("input: ");
   scanf("%d", &opt);
   
   switch (opt) {
      case 0: triangle(n); break;
      case 1: right_triangle(n); break;
      case 2: reverse_triangle(n); break;
      case 3: square(n); break;
   }

   return 0;
}
