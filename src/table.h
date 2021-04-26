#include "record.h"

typedef struct {
    record   *record_tab;
    int      count;
    int      max_s;
} routers_table;

int create_table(int size, routers_table *table_out);
int delete_table(routers_table *table);
int add_record(routers_table *table, record *r);
int rm_record(routers_table *table, int idx);
int find_network_record(routers_table *table, addr network_ip);
int set_unreachable(routers_table *table, int idx);
int displey_table(routers_table *table);
