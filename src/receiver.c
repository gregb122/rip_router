#include <netinet/ip.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int receive(int sockfd)
{

	struct sockaddr_in 	sender;	
	socklen_t 			sender_len = sizeof(sender);
	u_int8_t 			buffer[IP_MAXPACKET+1];

	
	ssize_t datagram_len = recvfrom (sockfd, buffer, IP_MAXPACKET, 0, (struct sockaddr*)&sender, &sender_len);
	if (datagram_len < 0) {
		fprintf(stderr, "recvfrom error: %s\n", strerror(errno)); 
		return EXIT_FAILURE;
	}

	char sender_ip_str[20]; 
	inet_ntop(AF_INET, &(sender.sin_addr), sender_ip_str, sizeof(sender_ip_str));
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
}

