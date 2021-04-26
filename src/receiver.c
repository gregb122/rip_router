//Grzegorz Bielecki 288388

#include "receiver.h"

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

int receive(int sockfd, u_int8_t buffer[], char sender_ip_str[])
{

	struct sockaddr_in 	sender;	
	socklen_t 			sender_len = sizeof(sender);

	
	ssize_t datagram_len = recvfrom (sockfd, buffer, IP_MAXPACKET, 0, (struct sockaddr*)&sender, &sender_len);
	if (datagram_len < 0) {
		fprintf(stderr, "recvfrom error: %s\n", strerror(errno)); 
		return EXIT_FAILURE;
	}

	inet_ntop(AF_INET, &(sender.sin_addr), sender_ip_str, 16);
	printf ("Received UDP packet from IP address: %s, port: %d\n", sender_ip_str, ntohs(sender.sin_port));

	buffer[datagram_len] = 0;
	printf ("%ld-byte message: +%s+\n", datagram_len, buffer);
	
	char* reply = "Thank you!";
	ssize_t reply_len = strlen(reply);
	if (sendto(sockfd, reply, reply_len, 0, (struct sockaddr*)&sender, sender_len) != reply_len) {
		fprintf(stderr, "sendto error: %s\n", strerror(errno)); 
		return EXIT_FAILURE;		
	}

	fflush(stdout);

	return EXIT_SUCCESS;
}

int listen_for_packets(int _sockfd, int time){
		fd_set descriptors;
		FD_ZERO (&descriptors);
		FD_SET (_sockfd, &descriptors);
		u_int8_t buffer[IP_MAXPACKET+1];
		char sender_ip_str[20];

		struct timeval tv = {
			tv.tv_sec = time,
			tv.tv_usec = 0
		};
		
		int ready = select (_sockfd+1, &descriptors, NULL, NULL, &tv);
		if(ready < 0){
			fprintf(stderr, "select error: %s\n", strerror(errno));
			exit(EXIT_FAILURE);
		}
		if(ready == 0){
			return 0;
}

		return receive(_sockfd, buffer, sender_ip_str);
}

