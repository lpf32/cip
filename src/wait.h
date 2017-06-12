#ifndef CIP_WAIT_H
#define CIP_WAIT_H

#include "utils.h"

struct wait_lock
{
    pthread_mutex_t lock;
    pthread_cond_t ready;
    uint8_t sleeping;
};

static inline int wait_init(struct wait_lock *w)
{
    pthread_cond_init(&w->ready, NULL);
    pthread_mutex_init(&w->lock, NULL);

    w->sleeping = 0;
    return 0;
}

static inline int wait_wakeup(struct wait_lock *w)
{
    pthread_mutex_lock(&w->lock);
    pthread_cond_signal(&w->ready);

    w->sleeping = 0;

    pthread_mutex_unlock(&w->lock);
    return 0;
}

static inline int wait_sleep(struct wait_lock *w)
{
    pthread_mutex_lock(&w->lock);

    w->sleeping = 1;
    pthread_cond_wait(&w->ready, &w->lock);

    pthread_mutex_unlock(&w->lock);

    return 0;
}

static inline int wait_free(struct wait_lock *w)
{
    wait_wakeup(w);

    pthread_mutex_destroy(&w->lock);

    pthread_cond_destroy(&w->ready);
}



#endif //CIP_WAIT_H
