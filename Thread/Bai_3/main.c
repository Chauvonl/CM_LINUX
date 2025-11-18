#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int data = 0;
int data_ready = 0;

pthread_mutex_t lock;
pthread_cond_t cond;

void* producer (void* arg) {
    for(int i = 0; i < 10; i++){
        sleep(1);
        int value = rand() % 100;

        pthread_mutex_lock(&lock);
        data = value;
        data_ready = 1;

        printf("Producer tạo dữ liệu: %d\n", value);

        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void* consumer(void* arg) {
    for(;;){
        pthread_mutex_lock(&lock);

        while (data_ready == 0)
        {
            pthread_cond_wait(&cond, &lock);
        }
        printf("Consumer đọc dữ liệu: %d\n", data);

        data_ready = 0;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t prod, cons;

    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    
    return 0;
}

