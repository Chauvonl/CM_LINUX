#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main () {
    pid_t pid = fork();

    if(pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        printf ("con (PID = %d) kết thúc ngay.\n", getpid());
        exit(0);
    } else {
        printf("Cha (PID = %d) không gọi wait(), sleep(30).\n", getpid());
        sleep(30);
        printf("Cha kết thúc.\n");
    }
    return 0;
}


