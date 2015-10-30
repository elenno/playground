#include <stdio.h>
#include <unistd.h>

main()
{
	int newpg = setpgrp();
	printf("new group id:%d\n", newpg);
	while(1)
	{
	}
}