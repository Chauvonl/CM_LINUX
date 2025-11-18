



#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int seconds = 0;

void alarm_handler(int sig) {
    seconds++;
    printf("Timer: %d seconds\n", seconds);

    if (seconds >= 10) {
        printf("Đếm đủ 10 giây. Thoát.\n");
        _exit(0);
    }

    alarm(1);  // Lặp lại mỗi giây
}

int main() {
    signal(SIGALRM, alarm_handler);
    alarm(1);

    while (1)
        pause();

    return 0;
}
/*
- Nếu không gọi lại alarm(1) trong handler thì SIGALRM chỉ xảy ra 1 lần.
- Sau khi handler chạy xong không có alarm mới, timer dừng ở giây thứ 1, không đếm tiếp được.
*/