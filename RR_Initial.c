#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
} Process;



// Function to calculate waiting times and execution order for all processes
void calculateWaitingTimeAndExecutionOrder(Process proc[], int n, int quantum) {
    int time = 0; //current time 
    int remaining = n; //number of remaining processes 
    int execution_order[100]; //to store execution order
    int order_index = 0; 
    int last_executed = -1; //track the last executed process 
    

    //loop until all processes are complete 
    while (remaining > 0) {
        int done = 1; //flag to check if any process executed in this cycle 
        for (int i = 0; i < n; i++) {

            //store process execution order 
            if (proc[i]. remaining_time > 0) {
                done = 0; 
                execution_order[order_index++] = proc[i].process_id; 
            
                //store process execution order if it's different from the last process executed
                if (last_executed != proc[i].process_id) {
                    execution_order[order_index++] = proc[i].process_id; 
                    last_executed = proc[i].process_id; 

                } 
                //execute the process for at most quantum time units
                if(proc[i].remaining_time > quantum){
                    time += quantum; 
                    proc[i].remaining_time -= quantum; 
                } else {
                    //if remaining time is less than quantum execute fully
                    time += proc[i].remaining_time;
                    proc[i].waiting_time = time - proc[i].arrival_time - proc[i].burst_time;
                    proc[i].remaining_time = 0;
                    remaining--; //process is complete
                }
            }
        }

        // If all processes are done
        if (done == 1) break;
    }

    // Print the execution order
    printf("Execution Order: ");
    for (int i = 0; i <order_index; i++) {
        printf("P%d ", execution_order[i]);
    }
    printf("\n");
    
}

// Function to calculate turnaround times for all processes
void calculateTurnaroundTime(Process proc[], int n) {
   for (int i = 0; i < n; i++) {
        proc[i].turnaround_time = proc[i].waiting_time + proc[i].burst_time; 
   }
}

//round robin scheduling function
void roundRobin(Process proc[], int n, int quantum) {
    //initialize each process
    for (int i = 0; i < n; i++) {
        proc[i].remaining_time = proc[i].burst_time; //initialize remaining time
        proc[i].waiting_time = 0; //initialize waiting time 
    }
    calculateWaitingTimeAndExecutionOrder(proc, n, quantum);
    calculateTurnaroundTime(proc, n);
}

void printProcesses(Process proc[], int n) {
    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               proc[i].process_id, proc[i].arrival_time, proc[i].burst_time,
               proc[i].waiting_time, proc[i].turnaround_time);
    }
}

int main() {
    Process proc[] = {{1, 0, 24}, {2, 0, 3}, {3, 0, 3}};
    int n = sizeof(proc) / sizeof(proc[0]); // Number of processes
    int quantum = 4; // Time quantum for Round Robin scheduling
 

    roundRobin(proc, n, quantum);
    printProcesses(proc, n);

    return 0;
}
