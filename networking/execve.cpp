#include <unistd.h>
#include <stdio.h>
main()
{
	char* argv[] = {"eviron", NULL},
		* envp[] = {"foo=bar", "bar=foo", NULL};
	execve("./environ", argv, envp);
	perror("exeve failed!");
}