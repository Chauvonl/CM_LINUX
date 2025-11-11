#include<stdio.h>
#include<sys/stat.h>
#include<time.h>
#include<stdlib.h>
#include<sys/types.h>

int main(int argc, char *argv[]) {
    //Kiểm tra tham số
    if (argc != 2){
        printf("Usage: %s <file_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *path = argv[1];
    struct stat st;
    
    //Gọi lstat() để lấy thông tin file
    if (lstat(path, &st) == -1) {
        perror("lstat");
        return EXIT_FAILURE;
    }

    //In đường dẫn 
    printf("File Path: %s\n", path);
    //Xác định loại file
    printf("File Type: ");
    if  (S_ISREG(st.st_mode)) {
        printf("Regular File\n");
    } else if (S_ISDIR(st.st_mode)) {
        printf("Directory\n");
    } else if(S_ISLNK(st.st_mode)) {
        printf("Symbolic Link\n");
    } else {
        printf("Other\n");
    }
    //In kích thước
    printf("Size: %lld bytes\n", (long long)st.st_size);
    //In thời gian sữa đổi
    char timebuf[100];
    struct tm *tm = localtime(&st.st_mtime);
    if (tm == NULL) {
        perror("localtime");
        return EXIT_FAILURE;
    }
    
    strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M:%S", tm);
    printf("Last Modified: %s\n", timebuf);

    return 0;
}

