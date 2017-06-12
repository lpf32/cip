set(lib_SRCS
        arp.c
        netdev.c
        skbuff.c
        utils.c
        tuntap_if.c
        dst.c
        icmpv4.c
        ip_input.c
        ip_output.c
        route.c
        timer.c
        tcp.c
        sock.c
        socket.c
        tcp_input.c
        tcp_output.c
        inet.c
        tcp_data.c
        )

add_library(ip ${lib_SRCS})

add_subdirectory(test)