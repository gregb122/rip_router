#include "table.h"

int create_table(routers_table *table);
int delete_table(routers_table *table);
int add_record(routers_table *table, record *e);
int rm_record(routers_table *table, int idx);
int find_network_record(routers_table *table, addr network_ip);
int set_unreachable(routers_table *table, int idx);
int display_table(routers_table *table);
