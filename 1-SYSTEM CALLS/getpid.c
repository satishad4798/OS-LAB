#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
void main()
{
        if(fork()==0)
         {
int t=getppid();
printf("%d\n",t);
int p=getpid();
printf("%d\n",p);
	 }
}

