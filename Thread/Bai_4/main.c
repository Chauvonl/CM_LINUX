#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int shared_data = 0;
pthread_rwlock_t rwlock;

void* reader(void* arg) {
    int id = *(int*)arg;
    while (1) {
        pthread_rwlock_rdlock(&rwlock);
        printf("Reader %d đọc dữ liệu: %d\n", id, shared_data);
        pthread_rwlock_unlock(&rwlock);
        usleep(200000);
    }
}

void* writer(void* arg) {
    int id = *(int*)arg;
    while (1) {
        pthread_rwlock_wrlock(&rwlock);
        shared_data++;
        printf("Writer %d ghi dữ liệu: %d\n", id, shared_data);
        pthread_rwlock_unlock(&rwlock);
        sleep(1);
    }
}

int main() {
    pthread_t r[5], w[2];
    pthread_rwlock_init(&rwlock, NULL);

    int rid[5] = {1,2,3,4,5};
    int wid[2] = {1,2};

    for (int i = 0; i < 5; i++)
        pthread_create(&r[i], NULL, reader, &rid[i]);

    for (int i = 0; i < 2; i++)
        pthread_create(&w[i], NULL, writer, &wid[i]);

    pthread_join(r[0], NULL); 
    return 0;
}
