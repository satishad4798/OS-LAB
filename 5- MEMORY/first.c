#include<stdio.h>
#include<stdlib.h>




int main()
{
	int partion[20],process[20],fragment[20];
         int allocation[20];
  int i,j,m,n;

printf("enter the number of partion\n");
scanf("%d",&m);
printf("enter the number of process\n");
scanf("%d",&n);


printf("enter the partion size\n");
for(i=0;i<m;i++)
{
scanf("%d",&partion[i]);

}

printf("enter the process size\n");
for(i=0;i<n;i++)
{
	scanf("%d",&process[i]);

	allocation[i]=-1;
}


//first fit


for(i=0;i<n;i++)
   {
     for(j=0;j<m;j++)
      {
      	if(process[i]<=partion[j])
      	     {
           	allocation[i]=j;
               partion[j]=partion[j]-process[i];
               
               fragment[i]=partion[j];

            
      		break;
      	}
      }      


   }


        printf("processid\t  process size\t allocation\t internal fragment\n");
   for(i=0;i<n;i++)
        {

        printf("%d \t%d\t",i+1,process[i]);
            if(allocation[i]!=-1)
            	printf("%d\t %d\n",allocation[i],fragment[i] );
            else
            	printf("not allocated \n");
            

        }












}
