#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BACK_LOG_MAX 10

int main()
{
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1)
        {
                perror("apply tcp socket failed!\n");
            exit(1);
        }
        struct sockaddr_in myaddr;
        myaddr.sin_family = AF_INET;
        myaddr.sin_port = htons(10086);
        myaddr.sin_addr.s_addr = htonl(INADDR_ANY); //inet_addr("10.20.201.144");
        bzero(&(myaddr.sin_zero), 8);
        int bind_ret = bind(sockfd, (struct sockaddr *)&myaddr, sizeof(struct sockaddr));
        if (bind_ret == -1)
        {
                perror("bind error");
                exit(1);
        }
        int clifds[BACK_LOG_MAX];
        memset(clifds, 0, sizeof(clifds));
        int cli_count = 0;
        struct sockaddr_in cliaddrs[BACK_LOG_MAX];
        while(cli_count < BACK_LOG_MAX && 0 == listen(sockfd, BACK_LOG_MAX))
        {
            socklen_t sin_size = sizeof(struct sockaddr_in);
            if (-1 != (clifds[cli_count] = accept(sockfd, (struct sockaddr*)&cliaddrs[cli_count], &sin_size)))
            {   
                printf("accept client_id:%d from %s:%d\n", cli_count, inet_ntoa(cliaddrs[cli_count].sin_addr), ntohs(cliaddrs[cli_count].sin_port));
				int pid = fork();
				if (0 == pid)
				{
					//вс╫ЬЁл
					char recv_buff[1024];
					char send_buff[1024];
					memset(recv_buff, 0, sizeof(recv_buff));
					memset(send_buff, 0, sizeof(send_buff));
					int len;
					while(-1 != (len = recv(clifds[cli_count], recv_buff, sizeof(recv_buff), 0)))
					{
						printf("recv msg: %s  len:%d\n", recv_buff, len);
						memcpy(send_buff, recv_buff, sizeof(recv_buff));
						int send_len = strlen(send_buff);
						int actual_len;
						int already_len = 0;
						while(send_len > 0 && -1 != (actual_len = send(clifds[cli_count], send_buff + already_len, send_len, 0)))
						{
							send_len -= actual_len;
							already_len += actual_len;
						}
						if (-1 == actual_len)
						{
							perror("send failed!");
							exit(1);
						}
						printf("send msg: %s\n", send_buff);
						memset(recv_buff, 0, sizeof(recv_buff));
					    memset(send_buff, 0, sizeof(send_buff));
					}
					perror("recv error!");
					exit(1);
				}
				else if (pid < 0)
				{
					perror("fork failed!");
				}
				cli_count++;
            }
			else
			{
				perror("accept failed!");
				exit(1);
			}
        }
        if (cli_count < BACK_LOG_MAX)
		{
			perror("listen failed!");
			exit(1);
		}
        printf("svr close!\n");
        return 0;
}