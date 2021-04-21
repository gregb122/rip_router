//Grzegorz Bielecki 288388

#include <netinet/ip_icmp.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "icmp_send.h"
#include "icmp_receive.h"


int router(){
    return EXIT_FAILURE;
}

int main(int argc, char** argv){
    if (argc != 2){
        fprintf(stderr, "Get %d arguments, only one is requied\n", argc);
        exit(EXIT_FAILURE);
    }

    return router();
}