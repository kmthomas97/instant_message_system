// USER 2
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h> // read(), write(), close()
#define MAX 80
#define PORT 8080
#define SA struct sockaddr

// Function designed for chat between client and server.
void func(int connfd)
{
	char buff[MAX];
	int n;
	// infinite loop for chat
	for (;;) {
		bzero(buff, MAX);

		// read the message from client and copy it in buffer
		read(connfd, buff, sizeof(buff));
		// print buffer which contains the client contents
		printf("[Client]=> %s[Server]=> ", buff);

		bzero(buff, MAX);

		n = 0;
		
		// copy server message in the buffer
		while ((buff[n++] = getchar()) != '#') {
			// printf("{buffer:n}:%s:%d", buff, n);
			if(buff[1] == 'e' && buff[2] == 'x' && buff[3] == 'i' && buff[4] == 't') {
				// printf("IN HERE SERVER!");
				printf("[Server Exit]\n");
				close(connfd);
				exit(0);
			}
		}

		// and send that buffer to client
		write(connfd, buff, sizeof(buff));

		// if msg contains "Exit" then server exit and chat ended.
		if (strncmp("exit", buff, 4) == 0) {
			printf("[Server Exit]\n");
			break;
		}
	}
}

// Driver function
int main()
{
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli;

	// socket create and verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf("[Socket Creation Failed]\n");
		exit(0);
	}
	else
		printf("[Socket Created]\n");
	bzero(&servaddr, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);

	// Binding newly created socket to given IP and verification
	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
		printf("[Socket Bind Failed]\n");
		exit(0);
	}
	else
		printf("[Socket Successfully Binded]\n");

	// Now server is ready to listen and verification
	if ((listen(sockfd, 5)) != 0) {
		printf("[Listen Failed]\n");
		exit(0);
	}
	else
		printf("[Server Listening]\n");
	len = sizeof(cli);

	// Accept the data packet from client and verification
	connfd = accept(sockfd, (SA*)&cli, &len);
	if (connfd < 0) {
		printf("[Server Accept Failed]\n");
		exit(0);
	}
	else
		printf("[Server Accepts The Client]\n");

	// Function for chatting between client and server
	func(connfd);

	// After chatting close the socket
	close(sockfd);
}
