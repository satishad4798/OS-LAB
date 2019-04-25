#include<stdio.h>
#include<stdlib.h>

struct process
{
	int at,bt,ct,wt,tat,p;
}process[10];

struct process temp;
void main()
{
int number,i,j;

	printf("enter the number process\n");
   scanf("%d",&number);

printf("enter arrival and burst time\n");
for(i=0;i<number;i++)
{
 printf("p[%d]:",i+1);
 scanf("%d%d",&process[i].at,&process[i].bt);
 process[i].p=i+1;

}
for(i=0;i<number-1;i++)
{
  for(j=i;j<number;j++)
   {
   	if(process[i].at>process[j].at)
     {
     	temp=process[i];
     	process[i]=process[j];
     	process[j]=temp;
     }
   }
}

process[0].ct=process[0].bt+process[0].at;
int time=process[0].ct;
process[0].tat=process[0].bt;
if(time>0)
{
	printf("process aws idle for 0 to %d",process[0].at);
}
for(i=1;i<number;i++)
{

if(process[i].at>time)
{
	process[i].ct=process[i].bt+process[i].at;
   printf("process idle for%d to %d \n",time,process[i].ct-1);
	
	time=process[i].ct;
	process[i].tat=time-process[i].at;
	process[i].wt=time-process[i].at-process[i].bt;
	
}
else
{
    process[i].ct=time+process[i].bt;
	time=process[i].ct;
	process[i].tat=time-process[i].at;
	process[i].wt=time-process[i].at-process[i].bt;
	   

}


}

printf("process\t\tat\tbt\twt\ttat\tct\n");
for(i=0;i<number;i++)
{
	printf("%d\t\t%d\t%d\t%d\t%d\t%d\t\n",process[i].p,process[i].at,process[i].bt,process[i].wt,process[i].tat,process[i].ct);
}

}
