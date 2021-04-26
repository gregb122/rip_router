#include <arpa/inet.h>

#include "record.h"

int construct_record(int _conn_type, char *_via_router, char *_network_ip, int _mask, int _distance, int _reachable, record *rec_out){
    rec_out->conn_type = _conn_type;
    rec_out->via_router_addr = 
}
int set_distance(record *rec, int distance);
int display_record(record *rec);
int broadcast_record(record *rec); //TODO use broadcaster here