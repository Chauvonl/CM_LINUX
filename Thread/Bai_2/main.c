#include<stdio.h>
#include<pthread.h>

long long counter = 0;
pthread_mutex_t lock;

void * thread_func(void *arg) {
    for (int i = 0; i < 1000000; i++){
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2, t3;
    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, thread_func, NULL);
    pthread_create(&t2, NULL, thread_func, NULL);
    pthread_create(&t3, NULL, thread_func, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    printf("Giá trị cuối cùng của counter = %lld\n", counter);

    pthread_mutex_destroy(&lock);
    return 0;

}
/*
- Vì CPU đọc biến counter theo 3 bước:
    + Bước 1: đọc counter từ bộ nhớ
    + Bước 2: tăng counter lên 1 đơn vị
    + Bước 3: Ghi lại vào bộ nhớ
- Trưởng nếu không có mutex thì 3 luồng sẻ chạy xen kẽ gần như cùng lúc, điều đó làm cho thao tác tăng biến counter bị đè lên nhau
dẫn đến kết quả sai. Do đó ta cần phải dùng mutex đảm bảo thao tác không bị ghi đè.
- Nếu bỏ mutex thì kết quả không còn chính xác, không ổn định khỏ kiểm soạt.
*/

