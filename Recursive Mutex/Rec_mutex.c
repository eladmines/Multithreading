#include <stdio.h>
#include "Rec_mutex.h"

void rec_mutex_init(rec_mutex_t *rec_mutex){
    rec_mutex->n=0;
    rec_mutex->lockOwner=0;
    pthread_mutex_init(&rec_mutex->state_mutex, NULL);
    rec_mutex->n_waited=0;
}




