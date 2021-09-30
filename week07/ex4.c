#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *realloc(void *ptr, size_t size) {
    void *new_ptr = malloc(size);

    // malloc()
    if (ptr == NULL) {
        return new_ptr;
    }

    // free()
    if (size == 0) {
        free(ptr);
        return NULL;
    }

    memcpy(new_ptr, ptr, size);

    return new_ptr;
}

int main() {
    // int *a = malloc(20 * sizeof(int));
    int *a = malloc(0);

    // a[8] = 10;
    // printf("%d\n", a[8]);

    a = realloc(a, 30 * sizeof(int));
    a[25] = 11;
    printf("%d %d\n", a[8], a[25]);

    return 0;
}