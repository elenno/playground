//�ܵ� pipe
//�ó��򴴽�һ��ͨ����ʹ���ӽ���ֻд���ݣ�������ֻ�����ݣ��ӹܵ��У�
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int fd[2], nbytes; //fd�ǹܵ��������
	pid_t childpid;
	char string[] = "Hello, yulin";
	char readbuffer[80];
	pipe(fd); //����һ���ܵ��� fd[0]�Ǵӹܵ������ݵľ����fd[1]����ܵ�д���ݵľ��
	if ((childpid = fork()) == -1)
	{
		perror("fork error");
		exit(1);
	}
	//�����ӽ��̱��������̵������ļ����������Ҫ�ȹرո����̵�д������ӽ��̵Ķ����
	if (childpid == 0)
	{
		//�ӽ��̹رչܵ��Ķ����
		close(fd[0]);
		//ͨ��д�����ܵ�д������
		write(fd[1], string, strlen(string));
		_exit(0); 
	}
	else
	{
		//�����̹رչܵ���д���
		close(fd[1]);
		//ͨ��������ӹܵ���������
		read(fd[0], readbuffer, sizeof(readbuffer));
		printf("recieve: %s\n", readbuffer);
	}
	return 0;
}