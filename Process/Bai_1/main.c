#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main() {
    pid_t pid;
    int status;

    pid = fork(); // tạo tiến trình con

    if(pid < 0) {
        perror ("fork failed");
        exit(1);
    }else if (pid == 0){
        // tiến trình con
        printf("Tiến trình con: PID = %d, PPID = %d\n", getpid(), getppid());
        exit(10);
    } else {
        //tiến trình cha
        printf("Tiến trình cha: PID = %d, con có PID = %d\n", getpid(), pid);
        wait(&status); // chờ tiến trình con kết thúc
        if (WIFEXITED (status)) {
            printf("Tiến trình con đã kết thúc bình thường.\n");
            printf("Mã thoát của con là: %d\n", WEXITSTATUS (status));
        } else {
            printf ("Tiến trình con đã kết thúc bất thường.\n");
        }
    }





    return 0;
}



