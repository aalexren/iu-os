#include <stdio.h>
#include <string.h>

int main() {
   char* string;
   printf("Original string: ");
   scanf("%[^\n]", string);
   int len = strlen(string);

   printf("Reversed string: ");
   for (int i = len - 1; i >= 0; --i) {
      putchar(string[i]);
   }

   return 0;
}
