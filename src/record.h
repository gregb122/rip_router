#include <stdint.h>
#include <arpa/inet.h>

#define INF64 64;

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

int construct_record(int conn_type, char *via_router, char *network_ip, int mask, int distance, int reachable, record *rec_out);
int set_distance(record *rec, int distance);
int display_record(record *rec);
int broadcast_record(record *rec);