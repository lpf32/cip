#include "icmpv4.h"
#include "ethernet.h"
#include "ip.h"

void icmpv4_incoming(struct sk_buff *skb)
{
    struct iphdr *iphdr = ip_hdr(skb);
    struct icmp_v4 *icmp = (struct icmp_v4 *) iphdr->data;

    //FIXME: Check sum
    uint16_t sum = checksum(icmp, (iphdr->len -iphdr->ihl*4), 0);
    if (sum != 0)
        goto drop_pkt;


    switch (icmp->type) {
        case ICMP_V4_ECHO:
            icmpv4_reply(skb);
            return;
        default:
            print_err("ICMPv4 did not match suppored types\n");
            goto drop_pkt;
    }

drop_pkt:
    free_skb(skb);
    return;
}

void icmpv4_reply(struct sk_buff *skb)
{
    struct iphdr *iphdr = ip_hdr(skb);
    struct icmp_v4 *icmp;
    struct sock sk;
    memset(&sk, 0, sizeof(struct sock));

    uint16_t icmp_len = iphdr->len - (iphdr->ihl * 4);

    skb_reserve(skb, ETH_HDR_LEN + IP_HDR_LEN + icmp_len);
    skb_push(skb, icmp_len);

    icmp = (struct icmp_v4 *)skb->data;

    icmp->type = ICMP_V4_REPLY;
    icmp->csum = 0;
    icmp->csum = checksum(icmp, icmp_len, 0);

    skb->protocol = ICMPV4;
    sk.daddr = iphdr->saddr;

    ip_output(&sk, skb);
    free_skb(skb);
}
