add_executable(test_tuntap test_tuntap.c)
target_link_libraries(test_tuntap ip)


add_executable(test_arp test_arp.c)
target_link_libraries(test_arp ip pthread)


add_executable(test_ip test_ip.c)
target_link_libraries(test_ip ip pthread)