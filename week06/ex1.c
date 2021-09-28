#include <stdio.h>
#include <stdlib.h>

typedef struct process {
    int arrival_time;
    int burst_time;
} process;

typedef struct answer {
    int completion_time;
    int turn_around_time;
    int waiting_time;
} answer;

int comp (const void * elem1, const void * elem2) {
    process f = *((process*)elem1);
    process s = *((process*)elem2);
    if (f.arrival_time > s.arrival_time) return 1;
    if (f.arrival_time < s.arrival_time) return -1;
    return 0;
}

int main() {
    int n; // number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    process pr[n];
    answer an[n];

    for (int i = 0; i < n; ++i) {
        printf("Enter the arrival time for the [%d] process: ", i);
        scanf("%d", &pr[i].arrival_time);
        printf("Enter the burst   time for the [%d] process: ", i);
        scanf("%d", &pr[i].burst_time);

        an[i].completion_time = 0;
        an[i].turn_around_time = 0;
        an[i].waiting_time = 0;
    }

    qsort (pr, sizeof(pr)/sizeof(*pr), sizeof(*pr), comp);

    an[0].completion_time = pr[0].arrival_time + pr[0].burst_time;
    an[0].turn_around_time = an[0].completion_time;
    an[0].waiting_time = 0;
    for (int i = 1; i < n; ++i) {
        an[i].completion_time += an[i-1].completion_time + pr[i].burst_time;
        an[i].turn_around_time = an[i].completion_time - pr[i].arrival_time;
        an[i].waiting_time = an[i].turn_around_time - pr[i].burst_time;
    }

    double average_turnaround_time = 0;
    double average_waiting_time = 0;
    for (int i = 0; i < n; ++i) {
        average_turnaround_time += an[i].turn_around_time;
        average_waiting_time += an[i].waiting_time;
    }
    average_turnaround_time /= n;
    average_waiting_time /= n;

    printf("P# \t AT \t BT \t CT \t TAT \t WT\n\n");
    for (int i = 0; i < n; ++i) {
        printf("%d \t %d \t %d \t %d \t %d \t %d\n", 
        i, 
        pr[i].arrival_time,
        pr[i].burst_time,
        an[i].completion_time,
        an[i].turn_around_time,
        an[i].waiting_time);
    }
    printf("\nAverage turnaround time: %f\n", average_turnaround_time);
    printf("Average waiting time: %f", average_waiting_time);

    return 0;
}