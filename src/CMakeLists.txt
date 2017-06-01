set(lib_SRCS
        arp.c
        netdev.c
        skbuff.c
        utils.c
        tuntap_if.c
        ethernet.h
        )

add_library(ip ${lib_SRCS})

add_subdirectory(test)