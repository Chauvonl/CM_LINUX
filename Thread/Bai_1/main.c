#include<stdio.h>
#include<pthread.h>

void* thread_func(void* arg) {
    pthread_t id = pthread_self();
    printf("Thread với ID %lu đang chạy!\n", id);
    return NULL; //Luồng kết thúc tại đây
}

int main() {
    pthread_t t1, t2;

    //Tạo 2 luồng
    pthread_create(&t1, NULL, thread_func, NULL);
    pthread_create(&t2, NULL, thread_func, NULL);

    //chờ cả 2 luồng kết thúc
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Luồng chính kết thúc!\n");
    return 0;
}
/*
- Một luồng kết thúc khi:
    + Hàm mà luồng đang chạy return
    + Luồng gọi pthread_exit()
    + Luồng bị hủy bằng pthrea_cancel()
    + Toàn bộ tiến trình kết thúc (tất cả luồng chết theo)
*/

/*
- Giải thích hàm pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void*), void *arg):
    + thread: trả về ID của luồng mới (t1 or t2)
    + attr: thuộc tính của luồng (NULL = mặc định)
    + start_routine: hàm mà luồng sẽ chạy
    + arg: tham số truyền vào cho hàm

- Giải thích hàm pthread_join(pthread_t thread, void **retval):
    + thread: ID luồng cần đợi
    + retval: nhận giá trị về từ luồng (NULL nếu không cần)
*/

