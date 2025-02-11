#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //for fork(), exclpt()
#include <sys/wait.h> 

#define NUM_CHILDREN 10 

//function that each child processes executes to run different system commands 
void execute_child_task(int child_num) {
    if (child_num == 0) {
        //using the "sh -c" to execute the echo command 
        execlp("sh", "sh", "-c", "echo Hello Your_name", NULL);
    } else if (child_num == 1) {
        //list files in the current directory with details 
        execlp("ls", "ls", "-l", NULL);
    } else if (child_num == 2) {
        //print current date and time 
        execlp("date", "date", NULL);
    } else if (child_num == 3) {
        //dispaly current user name 
        execlp("whoami", "whoami", NULL);
    } else if (child_num == 4) {
        //print current woeking directory 
        execlp("pwd", "pwd", NULL); 
    } else if (child_num == 5) {
        //show calendar for current month 
        execlp ("ncal",  "ncal", NULL);
    } else if (child_num == 6) {
        //display system infor 
        execlp("uname", "uname", "-a", NULL );
    } else if (child_num == 7) {
        //show currently running processes 
        execlp("ps", "ps", NULL);
    } else if (child_num == 8) {
        //show disk usage in human readable format 
        execlp("df", "df",  "-h", NULL);
    } else {
        //show memory usage in megabytes 
        execlp("free", "free", "-m", NULL);
    }
    perror("exec failed");
    exit(EXIT_FAILURE);
}

int main() {
    pid_t pids[NUM_CHILDREN]; //array to store child process ids 
    int status; //variable to store child process exit status 

    //loop to create child processes 
    for (int i = 0; i < NUM_CHILDREN; i++) {
        pids[i] = fork(); //create a new child process 
        if (pids[i] < 0) {
            //if fork fails print error 
            perror("fork failed");
            exit(EXIT_FAILURE);
        } else if (pids[i] == 0) {
            //child process executes this block 
            printf("Child %d (PID: %d) executing task...\n", i, getpid());
            execute_child_task(i);
            
        }
    }

    //parent process waits for all children to finish 
    while (wait(&status) > 0) {
        if (WIFEXITED(status)) {
            //if the child exited normally, print its exit status 
            printf("Child exited with status %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            //if the child was terminated by a signal, print the signal number 
            printf("Chld terminated by signal: %d\n", WTERMSIG(status));
        }
    }
    return 0; //exit successfully 
}