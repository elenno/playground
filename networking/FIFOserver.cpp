//FIFOs �����ܵ�
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<linux/stat.h>

#define FIFO_FILE "sampleFIFO"

int main()
{
	FILE *fp;
	char readbuf[80];

	//create FIFO if it does not exist
	umask(0);

	//���ļ�ϵͳ�д��������ܵ�
	mknod(FIFO_FILE, S_IFIFO|0666, 0);

	while(1)
	{
		//�������ܵ�
		fp = fopen(FIFO_FILE, "r");

		//�������ܵ��ж�ȡ����
		fgets(readbuf, 80, fp); //�����ܵ�֧�ֽ����Զ�����
		printf("received: %s\n", readbuf);

		//�ر������ܵ�
		fclose(fp);
	}
	return 0;
}