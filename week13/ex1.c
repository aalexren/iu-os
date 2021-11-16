#include <stdio.h>

int main() {
    char *filename = "input_dl.txt";
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error: could not open file %s", filename);
        return 1;
    }

    // reading line by line, max 256 bytes
    const unsigned MAX_LENGTH = 256;
    char buffer[MAX_LENGTH];

    int E[3];
    int A[3];
    int C[5][3];
    int R[5][3];

    int cnt = 0;

    while (fgets(buffer, MAX_LENGTH, fp)) {
        if (cnt == 0) {
            sscanf(buffer, "%d %d %d", &E[0], &E[1], &E[2]);
        }
        if (cnt == 2) {
            sscanf(buffer, "%d %d %d", &A[0], &A[1], &A[2]);
        }
        if (cnt == 3) {
            for (int i = 0; i < 5; ++i) {
                fgets(buffer, MAX_LENGTH, fp);
                sscanf(buffer, "%d %d %d", &C[i][0], &C[i][1], &C[i][2]);
                cnt++;
            }
        }
        if (cnt == 9) {
            for (int i = 0; i < 5; ++i) {
                fgets(buffer, MAX_LENGTH, fp);
                sscanf(buffer, "%d %d %d", &R[i][0], &R[i][1], &R[i][2]);
            }
        }
        cnt++;
    }

    

    for (int i = 0; i < 3; ++i) {
        printf("%d ", E[i]);
    }

    printf("\n\n");

    for (int i = 0; i < 3; ++i) {
        printf("%d ", A[i]);
    }

    printf("\n\n");

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d ", R[i][j]);
        }
        printf("\n");
    }

    // close the file
    fclose(fp);

    return 0;
}