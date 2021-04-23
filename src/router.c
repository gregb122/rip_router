//Grzegorz Bielecki 288388

#include <netinet/ip_icmp.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int create_socket(){
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd < 0) {
		fprintf(stderr, "socket error: %s\n", strerror(errno)); 
		return EXIT_FAILURE;
	}

	struct sockaddr_in server_address;
	bzero (&server_address, sizeof(server_address));
	server_address.sin_family      = AF_INET;
	server_address.sin_port        = htons(54321);
	server_address.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind (sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
		fprintf(stderr, "bind error: %s\n", strerror(errno)); 
		return EXIT_FAILURE;
	}
    return sockfd;
}

int close_socket(int sockfd){
    return close(sockfd);
}

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
