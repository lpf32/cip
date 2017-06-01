#ifndef CIP_IP_H
#define CIP_IP_H

static inline uint32_t ip_parse(char *addr)
{
    uint32_t dst = 0;
    if (inet_pton(AF_INET, addr, &dst) != 1)
    {
        perror("ERROR: Parsing inet address failed");
        exit(1);
    }

    return ntohl(dst);
}

int ip_rcv(struct sk_buff *skb);
int ip_output(struct sock *sk, struct sk_buff *skb);

#endif //CIP_IP_H
