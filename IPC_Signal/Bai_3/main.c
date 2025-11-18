#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

void child_handler(int sig) {
    printf("Received signal from parent\n");
}

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Process con
        signal(SIGUSR1, child_handler);

        while (1)
            pause();
    } 
    else {
        // Process cha
        for (int i = 0; i < 5; i++) {
            sleep(2);
            kill(pid, SIGUSR1);
        }
        printf("Cha đã gửi 5 tín hiệu. Thoát.\n");
    }
    return 0;
}
/*
- Vì được dùng để gửi tín hiệu đến tiến trình khác.
- Một tiến trình không thể tự gửi tín hiệu bằng cách signal() được.
- signal() chỉ đăng ký handler để nhận tín hiệu, không gửi tín hiệu.
*/


