// FCFS
#include<stdio.h>

int main() {
    int bt[20], wt[20], tat[20], i, n;
    float wtavg, tatavg;

    printf("\nEnter the number of processes -- ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nEnter Burst Time for Process %d -- ", i);
        scanf("%d", &bt[i]);
    }

    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];

    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = tat[i-1] + bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }

    printf("\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");

    for(i = 0; i < n; i++)
        printf("\n\t\t P%d \t\t %d \t\t\t %d \t\t\t\t\t %d", i, bt[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time -- %f", wtavg / n);
    printf("\nAverage Turnaround Time -- %f", tatavg / n);
    
    return 0;
}

// SJF
#include<stdio.h>

int main() {
    int p[20], bt[20], wt[20], tat[20], i, k, n, temp;
    float wtavg, tatavg;

    printf("\nEnter the number of processes -- ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        p[i] = i;
        printf("Enter Burst Time for Process %d -- ", i);
        scanf("%d", &bt[i]);
    }

    for(i = 0; i < n; i++)
        for(k = i + 1; k < n; k++)
            if(bt[i] > bt[k]) {
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }

    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];

    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = tat[i-1] + bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }

    printf("\n\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");

    for(i = 0; i < n; i++)
        printf("\n\t P%d \t\t %d \t\t %d \t\t %d", p[i], bt[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time -- %f", wtavg / n);
    printf("\nAverage Turnaround Time -- %f", tatavg / n);
}

// ROUND ROBIN
#include<stdio.h>

int main() {
    int n;
    printf("Enter Total Number of Processes:");
    scanf("%d", &n);

    int wait_time = 0, ta_time = 0, arr_time[n], burst_time[n], temp_burst_time[n];
    int x = n;

    for(int i = 0; i < n; i++) {
        printf("Enter Details of Process %d \n", i + 1);
        printf("Arrival Time:  ");
        scanf("%d", &arr_time[i]);
        printf("Burst Time:   ");
        scanf("%d", &burst_time[i]);
        temp_burst_time[i] = burst_time[i];
    }

    int time_slot;
    printf("Enter Time Slot:");
    scanf("%d", &time_slot);

    int total = 0, counter = 0, i;
    printf("Process ID       Burst Time       Turnaround Time      Waiting Time\n");
    for(total = 0, i = 0; x != 0;) {
        if(temp_burst_time[i] <= time_slot && temp_burst_time[i] > 0) {
            total = total + temp_burst_time[i];
            temp_burst_time[i] = 0;
            counter = 1;
        } else if(temp_burst_time[i] > 0) {
            temp_burst_time[i] = temp_burst_time[i] - time_slot;
            total += time_slot;
        }
        if(temp_burst_time[i] == 0 && counter == 1) {
            x--;
            printf("\nProcess No %d  \t\t %d\t\t\t\t %d\t\t\t %d", i+1, burst_time[i],
                   total-arr_time[i], total-arr_time[i]-burst_time[i]);
            wait_time = wait_time + total-arr_time[i]-burst_time[i];
            ta_time += total -arr_time[i];
            counter = 0;
        }
        if(i == n-1) {
            i = 0;
        } else if(arr_time[i+1] <= total) {
            i++;
        } else {
            i = 0;
        }
    }

    float average_wait_time = wait_time * 1.0 / n;
    float average_turnaround_time = ta_time * 1.0 / n;
    printf("\nAverage Waiting Time:%f", average_wait_time);
    printf("\nAverage Turnaround Time:%f", average_turnaround_time);

    return 0;
}

// 

