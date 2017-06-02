#ifndef CIP_WAIT_H
#define CIP_WAIT_H

#include "utils.h"

struct wait_lock
{
    pthread_attr_t lock;
    pthread_cond_t ready;
    uint8_t sleeping;
};

#endif //CIP_WAIT_H
