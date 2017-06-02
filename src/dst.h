#ifndef CIP_DST_H
#define CIP_DST_H

#include "skbuff.h"

struct sk_buff;

int dst_neigh_output(struct sk_buff *skb);

#endif //CIP_DST_H
