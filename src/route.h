#ifndef CIP_ROUTE_H
#define CIP_ROUTE_H

#include "list.h"

struct rtentry
{
    struct list_head list;
    uint32_t dst;
    uint32_t gateway;
    uint32_t netmask;
    uint8_t flags;
    uint32_t metric;
    struct netdev *dev;
};

#endif //CIP_ROUTE_H
