#include <stdio.h>
#include <stdlib.h>

typedef struct process {
    int id; // to save order ot the input
    int arrival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
    int done; // indicate that we've done it
} process;

int comp_id (const void * elem1, const void * elem2) {
    process f = *((process*)elem1);
    process s = *((process*)elem2);
    if (f.id > s.id) return 1;
    if (f.id < s.id) return -1;
    return 0;
}

int comp (const void * elem1, const void * elem2) {
    process f = *((process*)elem1);
    process s = *((process*)elem2);
    if (f.arrival_time > s.arrival_time) return 1;
    if (f.arrival_time < s.arrival_time) return -1;
    return 0;
}

/* returns index of minimum burst time among same arrival time */
int min(process *p, int n, int timeline) {
    int an = 0;
    for (int i = 0; i < n; ++i) {
        if (p[i].done == 0) {
            an = i; break;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (p[i].arrival_time <= timeline &&
            p[i].burst_time < p[an].burst_time && 
            p[i].done == 0) {
            an = i;
        }
    }

    return an;
}

int main() {
    int n; // number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    process pr[n];
    int TIME; // timeline

    for (int i = 0; i < n; ++i) {
        printf("Enter the arrival time for the [%d] process: ", i);
        scanf("%d", &pr[i].arrival_time);
        printf("Enter the burst   time for the [%d] process: ", i);
        scanf("%d", &pr[i].burst_time);

        pr[i].id = i;
        pr[i].completion_time = 0;
        pr[i].turn_around_time = 0;
        pr[i].waiting_time = 0;
        pr[i].done = 0;
    }

    qsort(pr, sizeof(pr)/sizeof(*pr), sizeof(*pr), comp);
    TIME = pr[0].arrival_time;


    int min_p = min(pr, n, TIME);
    pr[min_p].completion_time = pr[min_p].arrival_time + pr[min_p].burst_time;
    pr[min_p].turn_around_time = pr[min_p].completion_time;
    pr[min_p].waiting_time = 0;
    pr[min_p].done = 1;
    TIME = pr[min_p].completion_time;
    for (int i = 1; i < n; ++i) {
        int min_t = min(pr, n, TIME); // next min
        pr[min_t].completion_time += pr[min_p].completion_time + pr[min_t].burst_time;
        pr[min_t].turn_around_time = pr[min_t].completion_time - pr[min_t].arrival_time;
        pr[min_t].waiting_time = pr[min_t].turn_around_time - pr[min_t].burst_time;
        pr[min_t].done = 1;
        min_p = min_t;
        TIME = pr[min_t].completion_time;
    }

    double average_turnaround_time = 0;
    double average_waiting_time = 0;
    for (int i = 0; i < n; ++i) {
        average_turnaround_time += pr[i].turn_around_time;
        average_waiting_time += pr[i].waiting_time;
    }
    average_turnaround_time /= n;
    average_waiting_time /= n;

    qsort(pr, sizeof(pr)/sizeof(*pr), sizeof(*pr), comp_id);

    printf("P# \t AT \t BT \t CT \t TAT \t WT\n\n");
    for (int i = 0; i < n; ++i) {
        printf("%d \t %d \t %d \t %d \t %d \t %d\n", 
        pr[i].id, 
        pr[i].arrival_time,
        pr[i].burst_time,
        pr[i].completion_time,
        pr[i].turn_around_time,
        pr[i].waiting_time);
    }
    printf("\nAverage turnaround time: %f\n", average_turnaround_time);
    printf("Average waiting time: %f", average_waiting_time);

    return 0;
}