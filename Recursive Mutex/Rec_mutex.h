#ifndef SYSTEMC_REC_MUTEX_H
#define SYSTEMC_REC_MUTEX_H

#include <pthread.h>
#include <stdbool.h>

typedef struct rec_mutex{
    //Self-locks number
    int n;
    //Thread id which owns the mutex
    pthread_t lockOwner;
    pthread_mutex_t state_mutex;

    //Number of waiting threads
    int n_waited;
} rec_mutex_t;

void rec_mutex_init(rec_mutex_t *rec_mutex);
void rec_mutex_lock(rec_mutex_t *rec_mutex);
void rec_mutex_unlock(rec_mutex_t *rec_mutex);
void rec_mutex_destroy(rec_mutex_t *rec_mutex);
#endif //SYSTEMC_REC_MUTEX_H
