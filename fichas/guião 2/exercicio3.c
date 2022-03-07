#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

void dezProcessos(){
    for (int i = 0; i < 10; ++i) {
        if (fork()==0) {
            printf("pai = %d  filho = %d  i = %d\n", getppid(), getpid(), i + 1);
            _exit(i + 1);
        }
        int exit_status;
        pid_t terminated_pid = wait(&exit_status);
        printf("id_processo_term %d, out_code_filho: %d\n\n", terminated_pid, WEXITSTATUS(exit_status));
    }
}

int main(){
    dezProcessos();
    return 0;
}