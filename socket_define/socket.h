#ifndef SOCKET_H
#define SOCKET_H
typedef unsigned int in_addr_t;
typedef unsigned char uint8_t;
typedef unsigned char sa_family_t;
typedef unsigned short in_port_t;
typedef unsigned int uint32_t;
// ipv4 socket define
struct in_addr {
    in_addr_t s_addr; /* 32bit-ipv4 address, network byte ordered. */
};

struct sockaddr_in{
    uint8_t sin_len; /* sizeof(sockaddr_in) */
    sa_family_t sa_family;      /* 8-bit */
    in_port_t sin_port;        /* 16bit-port */
    struct in_addr sin_addr; /* 32-ip-address */
    char sin_zero[8]; /* unused */
};

// ipv6 socket define
struct in6_addr{
    uint8_t s6_addr[16];  /*128-bit-ipv6 address, network byte order*/
};

struct sockaddr_in6 {
    uint8_t sin6_len; /* sizeof(sockaddr_in6) */
    sa_family_t sa6_family;
    in_port_t sin6_port;        /* 16bit-port */
    uint32_t sin6_flowinfo; /*flow information , not define*/
    struct in6_addr sockaddr_in6;
    uint32_t sin6_scope_id;
};

#endif