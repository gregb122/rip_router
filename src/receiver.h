//Grzegorz Bielecki 288388

#include <netinet/ip.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>


int create_socket();
int close_socket(int sockfd);
int receive(int sockfd, u_int8_t buffer[], char sender_ip_str[]);
int listen_for_packets(int _sockfd, int time, u_int8_t buffer[], char sender_ip_str[]);
