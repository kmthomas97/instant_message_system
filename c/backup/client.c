// USER 1
#include <arpa/inet.h> // inet_addr()
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h> // bzero()
#include <sys/socket.h>
#include <unistd.h> // read(), write(), close()
#define MAX 80
#define PORT 8080
#define SA struct sockaddr
void func(int sockfd)
{
	char buff[MAX];
	int n;
	for (;;) {
		bzero(buff, sizeof(buff));

		printf("[Client]=> ");

		bzero(buff, MAX);

		n = 0;
		// while the buffer doesn't contain a return
		while ((buff[n++] = getchar()) != '#') {
			// printf("{buffer:n}:%s:%d", buff, n);
			if(buff[1] == 'e' && buff[2] == 'x' && buff[3] == 'i' && buff[4] == 't') {
				// printf("IN HERE CLIENT!");
				printf("[Client Exit]\n");
				close(sockfd);
				exit(0);
			}
		}

		// write to the socket
		write(sockfd, buff, sizeof(buff));
		bzero(buff, sizeof(buff));
		read(sockfd, buff, sizeof(buff));
		printf("[Server]=> %s", buff);
		if ((strncmp(buff, "exit", 4)) == 0) {
			printf("[Client Exit]\n");
			break;
		}
	}
}

int main()
{
	int sockfd, connfd;
	struct sockaddr_in servaddr, cli;

	// socket create and verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf("[Socket Creation Failed]\n");
		exit(0);
	}
	else
		printf("[Socket Successfully Created]\n");
	bzero(&servaddr, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	// PUBLIC IP address for use outside of network
	// servaddr.sin_addr.s_addr = inet_addr("75.245.171.86");
        // KATIE's IPHONE
	// servaddr.sin_addr.s_addr = inet_addr("174.235.50.128");
        // DAKOTA's IP
	// servaddr.sin_addr.s_addr = inet_addr("99.71.149.145");
	// PRIVATE IP address for use on same network 
	// servaddr.sin_addr.s_addr = inet_addr("192.168.1.8");
	// servaddr.sin_addr.s_addr = inet_addr("192.168.254.217");
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(PORT);

	// connect the client socket to server socket
	if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr))
		!= 0) {
		printf("[Connection With The Server Failed]\n");
		exit(0);
	}
	else
		printf("[Connected To The Server]\n");

	// function for chat
	func(sockfd);

	// close the socket
	close(sockfd);
}
