#include <stdio.h>
#include <stdlib.h>

typedef struct process {
    int id; // to save order ot the input
    int arrival_time;
    int burst_time;
    int burst_time_o; // original
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

int main() {
    int n; // number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    process pr[n];
    int TIME; // timeline
    int PROCESS_LEFT = n; // when we should stop the execution
    
    int QUANTUM;
    printf("Enter the quantum quantity: ");
    scanf("%d", &QUANTUM);

    for (int i = 0; i < n; ++i) {
        printf("Enter the arrival time for the [%d] process: ", i);
        scanf("%d", &pr[i].arrival_time);
        printf("Enter the burst   time for the [%d] process: ", i);
        scanf("%d", &pr[i].burst_time);

        pr[i].id = i;
        pr[i].burst_time_o = pr[i].burst_time;
        pr[i].completion_time = 0;
        pr[i].turn_around_time = 0;
        pr[i].waiting_time = 0;
        pr[i].done = 0;
    }

    /* Bubble sort */
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (pr[i].arrival_time > pr[j].arrival_time) {
                process temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;
            }
        }
    }

    TIME = pr[0].arrival_time;

    for (int i = 0; PROCESS_LEFT > 0; ) {
        if (pr[i].done == 0) {
            if (pr[i].burst_time <= QUANTUM) {

                TIME += pr[i].burst_time;

                pr[i].completion_time = TIME;
                pr[i].turn_around_time = pr[i].completion_time - pr[i].arrival_time;
                pr[i].waiting_time = pr[i].turn_around_time - pr[i].burst_time_o;

                pr[i].done = 1; PROCESS_LEFT -= 1; i++;
            }
            else {
                pr[i].burst_time -= QUANTUM;
                
                TIME += QUANTUM;
                i++;
            }
        }
        else {
            i++;
        }
        if (i >= n) i = 0; // if excceeded turn it down and repeat algorithm again
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
        pr[i].burst_time_o,
        pr[i].completion_time,
        pr[i].turn_around_time,
        pr[i].waiting_time);
    }
    printf("\nAverage turnaround time: %f\n", average_turnaround_time);
    printf("Average waiting time: %f", average_waiting_time);

    return 0;
}

// Following the results the best algorithm is SJN, but
// It can leads to some difference, in some cases,
// But average waiting time will be on the SJN strong side.

/* For FCFS
P# 	 AT 	 BT 	 CT 	 TAT 	 WT

0 	 0 	 2 	 2 	 2 	 0
1 	 0 	 4 	 6 	 6 	 2
2 	 0 	 6 	 12 	 12 	 6
3 	 0 	 8 	 20 	 20 	 12
4 	 0 	 1 	 21 	 21 	 20
5 	 11 	 1 	 22 	 11 	 10
6 	 11 	 8 	 30 	 19 	 11
7 	 11 	 6 	 36 	 25 	 19
8 	 11 	 4 	 40 	 29 	 25
9 	 11 	 2 	 42 	 31 	 29

Average turnaround time: 17.600000
Average waiting time: 13.400000%
*/

/* For Shortest Job Next
P# 	 AT 	 BT 	 CT 	 TAT 	 WT

0 	 0 	 1 	 1 	 1 	 0
1 	 0 	 2 	 3 	 3 	 1
2 	 0 	 4 	 7 	 7 	 3
3 	 0 	 6 	 13 	 13 	 7
4 	 0 	 8 	 34 	 34 	 26
5 	 11 	 8 	 42 	 31 	 23
6 	 11 	 6 	 26 	 15 	 9
7 	 11 	 4 	 20 	 9 	 5
8 	 11 	 2 	 16 	 5 	 3
9 	 11 	 1 	 14 	 3 	 2

Average turnaround time: 12.100000
Average waiting time: 7.900000
*/

/* For Round-Robin
P# 	 AT 	 BT 	 CT 	 TAT 	 WT

0 	 0 	 1 	 1 	 1 	 0
1 	 0 	 2 	 3 	 3 	 1
2 	 0 	 4 	 25 	 25 	 21
3 	 0 	 6 	 28 	 28 	 22
4 	 0 	 8 	 40 	 40 	 32
5 	 11 	 8 	 42 	 31 	 23
6 	 11 	 6 	 37 	 26 	 20
7 	 11 	 4 	 38 	 27 	 23
8 	 11 	 2 	 23 	 12 	 10
9 	 11 	 1 	 24 	 13 	 12

Average turnaround time: 20.600000
Average waiting time: 16.400000
*/