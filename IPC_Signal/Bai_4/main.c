
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/select.h>
#include <stdlib.h>

void sigint_handler(int sig) {
    printf("\nSIGINT received.\n");
}

void sigterm_handler(int sig) {
    printf("\nSIGTERM received. Exiting...\n");
    exit(0);
}

int main() {
    char buffer[256];

    signal(SIGINT, sigint_handler);
    signal(SIGTERM, sigterm_handler);

    while (1) {
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);

        struct timeval tv = {1, 0};  // 1 giây timeout

        int ret = select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);

        if (ret > 0 && FD_ISSET(STDIN_FILENO, &fds)) {
            fgets(buffer, sizeof(buffer), stdin);
            printf("Bạn nhập: %s", buffer);
        }
        // Nếu ret == 0: timeout 1 giây → lặp lại vòng while
    }
    return 0;
}


