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
int t=getgid();
printf("%d\n",t);
int p=getegid();
printf("%d\n",p);
         }
}

