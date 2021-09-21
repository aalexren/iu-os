#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

// It raises quite fast.
// It can occur even in the first iteration.
// e.g. in some execution it will show folloing output:
// x: 1, err: 0
// x: 1, err: 1 <----- race condition is occured
// x: 3, err: 2

int x = 0; int err;
int count  = -1;

void* producer() {
    for (int i = 0; i < 10; ++i) {
        if (count == 1) sleep(2);
        err = x;
        x += 1;
        count = 1; // data is written to the buffer
    }
}

void* consumer() {
    for (int i = 0; i < 10; ++i) {
        if (count == 0) sleep(2);
        if (err == x) {
            printf("x: %d, ", x);
            printf("err: %d\n", err);
            printf("Race condition is occured!\n");
            sleep(10);
        }
        printf("x: %d, ", x);
        printf("err: %d\n", err);
        count = 0; // consumer obtained data from the buffer
    }
}

int main() {
    pthread_t tp;
    pthread_t tc;

    pthread_create(&tp, NULL, producer, NULL);
    pthread_create(&tc, NULL, consumer, NULL);

    pthread_join(tp, NULL);
    pthread_join(tc, NULL);

    return 0;
}