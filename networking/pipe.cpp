//管道 pipe
//该程序创建一个通道，使得子进程只写数据，父进程只读数据（从管道中）
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int fd[2], nbytes; //fd是管道句柄数组
	pid_t childpid;
	char string[] = "Hello, yulin";
	char readbuffer[80];
	pipe(fd); //创建一个管道， fd[0]是从管道读数据的句柄，fd[1]是向管道写数据的句柄
	if ((childpid = fork()) == -1)
	{
		perror("fork error");
		exit(1);
	}
	//由于子进程保留父进程的所有文件句柄，故需要先关闭父进程的写句柄和子进程的读句柄
	if (childpid == 0)
	{
		//子进程关闭管道的读句柄
		close(fd[0]);
		//通过写句柄向管道写入数据
		write(fd[1], string, strlen(string));
		_exit(0); 
	}
	else
	{
		//父进程关闭管道的写句柄
		close(fd[1]);
		//通过读句柄从管道读入数据
		read(fd[0], readbuffer, sizeof(readbuffer));
		printf("recieve: %s\n", readbuffer);
	}
	return 0;
}