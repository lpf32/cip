#ifndef CIP_INET_H
#define CIP_INET_H

#include "utils.h"
#include "socket.h"
#include "skbuff.h"

int inet_create(struct socket *sock, int protocol);
int inet_socket(struct socket *sock, int protocol);
int inet_connect(struct socket *sock, struct sockaddr *addr, int addr_len, int flags);
int inet_write(struct socket *sock, const void *buf, int len);
int inet_read(struct socket *sock, void *buf, int len);
int inet_close(struct socket *sock);
int inet_free(struct socket *sock);
int inet_abort(struct socket *sock);

struct sock *inet_lookup(struct sk_buff *skb, uint16_t sport, uint16_t dport);

#endif //CIP_INET_H
