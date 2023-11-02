//
// Created by algo on 11/2/23.
//

#ifndef MULTITHREADING_SEMAPHORE_H
#define MULTITHREADING_SEMAPHORE_H

#include <stdio.h>
#include <pthread.h>

typedef struct semaphore semaphore_t;

struct semaphore{
    int counter;
    pthread_mutex_t mutex;
    pthread_cond_t cond_var;
};

//Create new semaphore
semaphore_t* create_new_semaphore();

void semaphore_init(semaphore_t* semaphore,int counter);

void semaphore_wait(semaphore_t* semaphore);

void semaphore_signal(semaphore_t* semaphore);

void semaphore_destroy(semaphore_t* semaphore);


#endif //MULTITHREADING_SEMAPHORE_H
