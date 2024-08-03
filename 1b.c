#include <stdio.h>
#include <stdlib.h>

typedef struct process {
    int Id, AT, BT, CT, TAT, WT, isCompl, remainingBT;
} pro;

pro p[15];

void main() {
    int n, total_WT = 0, total_TAT = 0, idleTime = 0;
    float avg_WT = 0, avg_TAT = 0;
    printf("\nEnter the number of processes:\n");
    scanf("%d", &n);

    printf("\nEnter the arrival time, burst time of the process:\n");
    printf("AT BT\n");

    for (int i = 0; i < n; i++) {
        p[i].Id = (i + 1);
        scanf("%d%d", &p[i].AT, &p[i].BT);
        p[i].remainingBT = p[i].BT;
        p[i].isCompl = 0;
    }

    int minIndex, minBT, completed = 0, curTime = 0;
    printf("\nGantt Chart:\n\n");

    while (completed != n) {
        minIndex = -1;
        minBT = 9999;

        // Find the process with the shortest remaining burst time that has arrived
        for (int i = 0; i < n; i++) {
            if (p[i].AT <= curTime && p[i].isCompl == 0) {
                if (p[i].remainingBT < minBT || (p[i].remainingBT == minBT && p[i].AT < p[minIndex].AT)) {
                    minBT = p[i].remainingBT;
                    minIndex = i;
                }
            }
        }

        if (minIndex == -1) {
            curTime++; // If no process is available, increment the current time
            idleTime++;
        } else {
            if (idleTime > 0) {
                printf("| Idle till %d", curTime);
                idleTime = 0;
            }

            // Execute the selected process for one time unit
            p[minIndex].remainingBT--;
            curTime++;
            printf("| P%d (%d) %d", p[minIndex].Id, p[minIndex].BT, curTime);

            // Check if the process has completed
            if (p[minIndex].remainingBT == 0) {
                p[minIndex].CT = curTime;
                p[minIndex].TAT = p[minIndex].CT - p[minIndex].AT;
                p[minIndex].WT = p[minIndex].TAT - p[minIndex].BT;
                total_TAT += p[minIndex].TAT;
                total_WT += p[minIndex].WT;
                p[minIndex].isCompl = 1;
                completed++;
            }
        }
    }
    printf("|\n");

    avg_TAT = (float)total_TAT / n;
    avg_WT = (float)total_WT / n;

    // Printing the table of processes with details
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].Id, p[i].AT, p[i].BT, p[i].CT, p[i].TAT, p[i].WT);
    }

    printf("\nAverage TAT = %.2f\nAverage WT = %.2f\n", avg_TAT, avg_WT);
}
