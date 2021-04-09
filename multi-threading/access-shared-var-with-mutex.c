#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

pthread_t threads[2];
int tid;
unsigned long long counter;
pthread_mutex_t lock;

/* 
output is good
----------------------------------------
Job 1 has started
Job 1 has finished with counter = 0x100000000
Job 2 has started
Job 2 has finished with counter = 0x200000000
*/

void * increase(void* arg) {
    pthread_mutex_lock(&lock);

    tid += 1;
    printf("Job %d has started\n", tid);
    for (unsigned long i = 0; i <= 0xFFFFFFFF; i++) {
        counter += 1;
    }
    printf("Job %d has finished with counter = %p\n", tid, counter);

    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(void) {
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("ERROR: fail to init mutex\n");
        return 1;
    }
    for (int i = 0; i < 2; i++) {
        int create_ret = pthread_create(&(threads[i]), NULL, &increase, NULL);
        if (create_ret != 0) {
            printf("\nERROR: Thread cannot be created: [%s]", strerror(create_ret));
            return create_ret;
        }
    }
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}