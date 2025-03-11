#include <stdio.h>

int main() {
    int num_processes, burst_time[30], arrival_time[30], waiting_time[30], turnaround_time[30];
    int completion_time[30], response_time[30];
    float avg_waiting_time = 0, avg_turnaround_time = 0, avg_response_time = 0;
    float throughput;
    int i, j, total_burst_time = 0;
    int timeline = 0; // Current timeline position
    
    printf("Please enter the total number of processes (maximum 30): ");
    scanf("%d", &num_processes);
    
    // Get burst time and arrival time for each process
    for (i = 0; i < num_processes; i++) {
        printf("\nEnter details for Process P[%d]:", i + 1);
        
        printf("\n  Arrival Time: ");
        scanf("%d", &arrival_time[i]);
        
        printf("  Burst Time: ");
        scanf("%d", &burst_time[i]);
        
        total_burst_time += burst_time[i];
    }
    
    // Sort processes based on arrival time (using simple bubble sort)
    for (i = 0; i < num_processes - 1; i++) {
        for (j = 0; j < num_processes - i - 1; j++) {
            if (arrival_time[j] > arrival_time[j + 1]) {
                // Swap arrival times
                int temp = arrival_time[j];
                arrival_time[j] = arrival_time[j + 1];
                arrival_time[j + 1] = temp;
                
                // Swap burst times
                temp = burst_time[j];
                burst_time[j] = burst_time[j + 1];
                burst_time[j + 1] = temp;
            }
        }
    }
    
    // Calculate completion time, turnaround time, waiting time, response time
    timeline = 0;
    
    for (i = 0; i < num_processes; i++) {
        // If current process arrives after the completion of previous process
        if (timeline < arrival_time[i]) {
            timeline = arrival_time[i];
        }
        
        // Response time is when process first gets CPU - arrival time
        response_time[i] = timeline - arrival_time[i];
        
        // Calculate completion time for current process
        timeline += burst_time[i];
        completion_time[i] = timeline;
        
        // Turnaround time = completion time - arrival time
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        
        // Waiting time = turnaround time - burst time
        waiting_time[i] = turnaround_time[i] - burst_time[i];
        
        // Sum for calculating averages
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
        avg_response_time += response_time[i];
    }
    
    // Calculate averages
    avg_waiting_time /= num_processes;
    avg_turnaround_time /= num_processes;
    avg_response_time /= num_processes;
    
    // Calculate throughput (processes completed per unit time)
    int max_completion_time = completion_time[num_processes - 1];
    throughput = (float)num_processes / max_completion_time;
    
    // Display results
    printf("\n\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\tResponse");
    printf("\n\t Time\tTime\tTime\t\tTime\t\tTime\tTime");
    printf("\n--------------------------------------------------------------------------------");
    
    for (i = 0; i < num_processes; i++) {
        printf("\nP[%d]\t%d\t%d\t%d\t\t%d\t\t%d\t%d", 
               i + 1, arrival_time[i], burst_time[i], completion_time[i], 
               turnaround_time[i], waiting_time[i], response_time[i]);
    }
    
    printf("\n\nAverage Waiting Time: %.2f", avg_waiting_time);
    printf("\nAverage Turnaround Time: %.2f", avg_turnaround_time);
    printf("\nAverage Response Time: %.2f", avg_response_time);
    printf("\nThroughput: %.4f processes/unit time", throughput);
    
    return 0;
}
