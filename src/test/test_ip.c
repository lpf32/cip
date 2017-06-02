#include "arp.h"
#include "tuntap_if.h"
#include <pthread.h>

int running = 1;
int debug = 1;

#define THREAD_CORE 0

static pthread_t threads[4] = {0,0,0,0};

void create_thread(pthread_t id, void*(*func)(void *))
{
    if (pthread_create(&threads[id], NULL, func, NULL) != 0) {
        print_err("Could not create core thread\n");
    }
}

void run_threads()
{
    create_thread(THREAD_CORE, netdev_rx_loop);
}

void wait_for_threads()
{
    for (int i = 0 ; i < 3 ; i++){
        if (threads[i] != 0 && (pthread_join(threads[i], NULL) != 0) ) {
            print_err("Error when joining threads\n");
            exit(1);
        }
    }
}

void init_stack()
{
    tun_init();
    netdev_init();
    arp_init();
    route_init();
}

void free_stack()
{
    free_arp();
    free_netdev();
    free_routes();
    free_tun();
}

int main(int argc, char ** argv)
{
    init_stack();

    run_threads();
    wait_for_threads();

    free_stack();
}