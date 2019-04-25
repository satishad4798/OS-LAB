

 //          working
#include<stdio.h>
#include<stdlib.h>

struct process
{
	int at,bt,ct,wt,tat,p;
}process[10];

struct process temp;
void main()
{
int number,i,j,min;

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
     if(process[i].at==process[j].at)// if same burst time
     {
              if(process[i].bt>process[j].bt) 
              {
              	temp=process[i];
     	        process[i]=process[j];
               	process[j]=temp;
              }

     }
   }
}


// code above same as fcfs

process[0].ct=process[0].at+process[0].bt; //fitst process in  line
process[0].tat=process[0].bt;
 	printf("process in order %d\n",process[0].p );
int time=process[0].ct;
if(time>0)
{
	printf("process ide ffor 0 to %d\n",time-1);
}

for(i=1;i<number;i++)
{
       if(process[i].at>time)
       {
       	process[i].ct=process[i].at+process[i].bt;
       	printf("cpu was idle for %d to %d\n",time,process[i].ct-1);
       	time=process[i].ct;
       	process[i].wt=0;
       	process[i].tat=process[i].bt;
       	printf("process in order%d\n",process[i].p );

       }
        else
        {
		         min=process[i].bt;
		                 //
		         for(j=i;j<number;j++)           //SWAPPING two process
		         {
		     	 if(process[j].at<=time&&process[j].bt<min)
		     	 {
		     	 	min=process[j].bt;
		     		temp=process[i];
		         	process[i]=process[j];
		     	    process[j]=temp;
		     	   // printf("swapping %d %d \n",i+1,j+1);

		       	  }
		         }
		         printf("process in order %d\n",process[i].p );
		         process[i].ct=time+process[i].bt;
		         time=process[i].ct;
		         process[i].tat=time-process[i].at;
		         process[i].wt=time-process[i].at-process[i].bt;
          }

}



//final answers printing

printf("process\t\tat\tbt\twt\ttat\tct\n");
for(i=0;i<number;i++)
{
	printf("%d\t\t%d\t%d\t%d\t%d\t%d\t\n",process[i].p,process[i].at,process[i].bt,process[i].wt,process[i].tat,process[i].ct);
}

}
