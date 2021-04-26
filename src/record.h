#include <stdint.h>
#include <arpa/inet.h>
#include "helpers.h"

typedef struct in_addr addr;

typedef struct{
    addr network_addr;
    int mask_len;
} network;

typedef struct {
    int conn_type;// 1 via or 0 direct 
    addr via_router_addr;
    network network_ip_with_mask;
    int distance;
    int reachable;// 0 when unreachable
} record;

int construct_record_from_str(char *str, record rec);
int construct_record(int _conn_type, addr _via_router, addr _network_ip, int _mask_len, int _distance, int _reachable, record *rec_out);
int set_distance(record *rec, int distance);
int display_record(record *rec);
int broadcast_record(record *rec);