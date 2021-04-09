#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

pthread_t threads[2];
int tid;
unsigned long long counter;

/* 
output is bad, it looks like:
----------------------------------------
Job 1 has started
Job 2 has started
Job 2 has finished with counter = 0xe6b98f6b
Job 2 has finished with counter = 0xf70373fd
*/

void * increase(void* arg) {
    tid += 1;
    printf("Job %d has started\n", tid);
    for (unsigned long i = 0; i <= 0xFFFFFFFF; i++) {
        counter += 1;
    }
    printf("Job %d has finished with counter = %p\n", tid, counter);
    return NULL;
}

int main(void) {
    for (int i = 0; i < 2; i++) {
        int create_ret = pthread_create(&(threads[i]), NULL, &increase, NULL);
        if (create_ret != 0) {
            printf("\nERROR: Thread cannot be created: [%s]", strerror(create_ret));
            return create_ret;
        }
    }
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    return 0;
}