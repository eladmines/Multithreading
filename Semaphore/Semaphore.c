//
// Created by algo on 11/2/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>
#include <stdbool.h>

semaphore_t* create_new_semaphore(){
    semaphore_t* semaphore = (semaphore_t*)malloc(sizeof(semaphore_t));
    if(semaphore == NULL) {
        printf("Semaphore not allocated");
    }
    printf("Semaphore successfully allocated");
}

void semaphore_init(semaphore_t* semaphore,int counter){
    semaphore->counter = counter;
    pthread_mutex_t mutex;
    semaphore->mutex = mutex;
    int mutex_init_res = pthread_mutex_init(&semaphore->mutex,NULL);
    pthread_cond_t cond_var;
    semaphore->cond_var = cond_var;
    int cond_init_res = pthread_cond_init(&semaphore->cond_var,NULL);
    assert(mutex_init_res && cond_init_res);
}

void semaphore_wait(semaphore_t* semaphore){
    int mutex_res = pthread_mutex_lock(&semaphore->mutex);
    assert(mutex_res == 0);
    semaphore->counter--;
    if(semaphore->counter < 0){
        int cond_res = pthread_cond_wait(&semaphore->cond_var,&semaphore->mutex);
        assert(cond_res == 0);
    }
    pthread_mutex_unlock(&semaphore->mutex);
}

void semaphore_signal(semaphore_t* semaphore){
    int mutex_res = pthread_mutex_lock(&semaphore->mutex);
    assert(mutex_res == 0);
    semaphhore->counter++;
    if(semaphore->counter < 0){
        int cond_res = pthread_cond_signal(&semaphore->cond_var);
        assert(cond_res);
    }
    pthread_mutex_unlock(&semaphore->mutex);
}

void semaphore_destroy(&semaphore_t* semaphore){
    pthread_cond_destroy(&semaphore->cond_var);
    pthread_mutex_destroy(&sema->mutex);
}

