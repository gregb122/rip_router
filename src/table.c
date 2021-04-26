#include "table.h"
int is_address_in(record *record, addr addess){
    return (record->network_ip_with_mask.network_addr.s_addr 
            == (addess.s_addr & record->network_ip_with_mask.netmask));
}
/* args 1 size of table list, 2 out for table */
int construct_table(int _size, routers_table *table){
    table->record_tab = malloc(_size * sizeof(record));
    table->count = 0;
    table->max_s = _size;
    return 0;
}
int delete_table(routers_table *table){
    free(table->record_tab);
}
int add_record(routers_table *table, record *r){
    if (table->count > table->max_s){
        table->record_tab = realloc(table->record_tab, table->max_s * 2);
        table->max_s = table->max_s * 2;
    }
    table->record_tab[table->count] = *r;
    table->count++;
    return 0;
}

int rm_record(routers_table *table, int idx){
    if ((idx <= table->count) && idx >= 0){
        table->record_tab[idx] = table->record_tab[--table->count];
        return 0;
    }
    else 1;//when idx out of range
}
int find_network_record(routers_table *table, addr _network_ip){
    for(int i; i < table->count; i++){
        if(is_address_in(&table->record_tab[i], _network_ip)){
            return i;
        }
    }
    return -1; // ip not found
}

int set_unreachable(routers_table *table, int idx){
    table->record_tab[idx].reachable = 0;
}

int display_table(routers_table *table){
    return 0; //TODO make display of record function and use here
}

