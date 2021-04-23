#include <stdint.h>
#include <arpa/inet.h>

typedef struct in_addr addr;

typedef struct{
    addr network_addr;
    int netmask;
} network;

typedef struct {
    int conn_type;// 1 via or 0 direct 
    addr via_router_addr;
    network network_ip_with_mask;
    int distance;
    int reachable;// 0 when unreachable
} record;
