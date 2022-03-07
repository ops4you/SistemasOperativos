#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

void ex2(){
    pid_t proc = fork();
    if(proc < 0){
        _exit(1);
    }
    if(proc == 0){
        pid_t childPID = getpid();
        pid_t childPPID = getppid();
        printf("id filho = %d\nid pai = %d\n", childPID, childPPID);
    } else {
        pid_t parentPID = getpid();
        pid_t parentPPID = getppid();
        pid_t parentChildPID = proc;
        printf("id pai = %d\nid avo = %d\nid filho = %d\n\n", parentPID, parentPPID, parentChildPID);
        wait(NULL);
    }
}

int main(){
    ex2();
    return 0;
}
