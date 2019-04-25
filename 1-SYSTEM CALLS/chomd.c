#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h> 
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#define _POSIX_SOURCE
void main()
{
	char *f="ada";
	int t=chmod(f,S_IRUSR);
	printf("%d",t);
}
