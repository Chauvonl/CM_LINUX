#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main () {
    pid_t pid;

    // Đặt biến môi trường
    setenv("MY_COMMAND","ls",1);
    pid = fork();

    if (pid < 0) {
        perror ("fork failed");
        exit(1);
    } else if (pid == 0) {
        // Tiến trình con
        char *cmd = getenv("MY_COMMAND");
        if (cmd == NULL) {
            printf ("Không tìm thấy biến môi trường MY_COMMAND.\n");
            exit(1);
        }
        printf ("Tiến trình con PID = %d sẽ thực thi lệnh: %s\n", getpid(), cmd);
        execlp (cmd, cmd, NULL); // Thay thế mã thực thi bằng chương trình mới

        perror("exec thất bại");
        exit(1);
    } else {
        printf("Tiến trình cha PID = %d, con PID = %d\n",getpid(), pid);
        wait(NULL);
        printf("Tiến trình con đã thúc.\n");
    }
    return 0;
}



