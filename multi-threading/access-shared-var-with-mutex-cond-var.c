#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

const int THREAD_COUNTS = 4;
pthread_t threads[THREAD_COUNTS];
int tid;
unsigned long long counter;
pthread_mutex_t lock;
pthread_cond_t power_to_count;

/*----------------------------------------------------------------
 gcc access-shared-var-with-mutex-cond-var.c -lpthread 
 
Job 1 has started
Job 1 is counting in middle with counter = 0xa0000000
Job 2 has started
Job 2 is counting in middle with counter = 0x140000000
Job 2 has finished with counter = 0x1a0000000
Job 3 has started
Job 3 is counting in middle with counter = 0x240000000
Job 4 has started
Job 4 is counting in middle with counter = 0x2e0000000
Job 4 has finished with counter = 0x340000000
Job 1 has finished with counter = 0x3a0000000
Job 3 has finished with counter = 0x400000000
*/
void * increase(void* arg) {
    pthread_mutex_lock(&lock);

    int myid = (tid += 1);
    printf("Job %d has started\n", tid);

    for (unsigned long i = 0; i <= 0x9FFFFFFF; i++) {
        counter += 1;
    }
    printf("Job %d is counting in middle with counter = %p\n", myid, counter);
    if (myid % 2 == 1) {
        pthread_cond_wait(&power_to_count, &lock);
    } else {
        pthread_cond_signal(&power_to_count);
    }
    for (unsigned long i = 0xA0000000; i <= 0xFFFFFFFF; i++) {
        counter += 1;
    }
    printf("Job %d has finished with counter = %p\n", myid, counter);

    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(void) {
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("ERROR: fail to init mutex\n");
        return 1;
    }
    if (pthread_cond_init(&power_to_count, NULL) != 0) {
        printf("ERROR: fail to init mutex\n");
        return 2;
    }
    for (int i = 0; i < THREAD_COUNTS; i++) {
        int create_ret = pthread_create(&(threads[i]), NULL, &increase, NULL);
        if (create_ret != 0) {
            printf("\nERROR: Thread cannot be created: [%s]", strerror(create_ret));
            return create_ret;
        }
    }
    for (int i = 0; i < THREAD_COUNTS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_cond_destroy(&power_to_count);
    pthread_mutex_destroy(&lock);

    return 0;
}