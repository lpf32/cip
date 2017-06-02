
#ifndef CIP_UTILS_H
#define CIP_UTILS_H

#include <stdlib.h>
#include <tiff.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdarg.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <pthread.h>
#include <netdb.h>
#include <sys/socket.h>
#include <time.h>
#include <sys/un.h>
#include <poll.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <linux/if.h>
#include <linux/if_tun.h>

#define CMDBUFLEN 100

#define print_debug(str, ...)       \
    printf(str" - %s:%u\n", ##__VA_ARGS__, __FILE__, __LINE__);

#define CLEAR(x) memset(&(x), 0, sizeof(x))

int run_cmd(char *cmd, ...);
void print_err(char *str, ...);
uint32_t sum_every_16bits(void *addr, int count);
uint16_t checksum(void *addr, int count, int start_sum);
int get_address(char *host, char *port, struct sockaddr* addr);
uint32_t parse_ipv4_string(char *addr);

#endif //CIP_UTILS_H
