#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int counter = 0;

void handler(int sig) {
    counter++;
    printf("\nSIGINT received (%d)\n", counter);

    if (counter >= 3) {
        printf("Đã nhận 3 lần SIGINT. Thoát chương trình.\n");
        _exit(0);   // Dùng _exit để thoát ngay trong handler
    }
}

int main() {
    signal(SIGINT, handler);

    printf("Chương trình đang chạy. Nhấn Ctrl+C...\n");
    
    while (1) {
        pause();  // Đợi tín hiệu
    }
    return 0;
}

/*
- Nếu bỏ qua tín hiệu SIGINT thì khi nhấn ctrl+c chưởng trình không dừng. Chương trình tiếp tục 
chạy mãi đến khi tự thoát hoặc bị giết bằng lệnh kill, ctrl+z, SIGTERM
*/


