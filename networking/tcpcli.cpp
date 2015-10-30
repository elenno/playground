#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (-1 == sockfd)
	{
		perror("apply sock failed!");
		exit(1);
	}
	//printf("1\n");
	struct sockaddr_in svr_addr;
	svr_addr.sin_family = AF_INET;
	svr_addr.sin_port = htons(10086);
	svr_addr.sin_addr.s_addr = inet_addr("10.21.210.103");
	bzero(&(svr_addr.sin_zero), 8);
    //printf("2\n");
	if (-1 == connect(sockfd, (struct sockaddr*)&svr_addr, sizeof(struct sockaddr)))
	{
		perror("connect failed!");
		exit(1);
	}
	//printf("3\n");
	printf("connect to %s:%d ok\n", inet_ntoa(svr_addr.sin_addr), ntohs(svr_addr.sin_port));
	char send_buff[1024];
	char recv_buff[1024];
	memset(send_buff, 0, sizeof(send_buff));
	memset(recv_buff, 0, sizeof(recv_buff));
	printf("input msg:");
	while(scanf("%s", send_buff) != EOF)
	{
		int len = strlen(send_buff);
        int already_len = 0;
		int send_len;
		while(len > 0 && -1 != (send_len = send(sockfd, send_buff + already_len, len, 0)))
		{
			len -= send_len;
			already_len += send_len;
		}
		if (-1 == send_len)
		{
			perror("send failed!");
			exit(1);
		}
		printf("send: %s\n", send_buff);
		int read_len;
		if (-1 == (read_len = recv(sockfd, recv_buff, sizeof(recv_buff), 0)))
		{
			perror("recv failed!");
			exit(1);
		}
		printf("recv: %s\n", recv_buff);
		memset(send_buff, 0, sizeof(send_buff));
		memset(recv_buff, 0, sizeof(recv_buff));
		printf("input msg:");
	}
	return 0;
}