#ifndef CIP_TUNTAP_IF_H
#define CIP_TUNTAP_IF_H

void tun_init();
int tun_read(char *buf, int len);
int tun_write(char *buf, int lne);
void free_tun();

#endif //CIP_TUNTAP_IF_H
