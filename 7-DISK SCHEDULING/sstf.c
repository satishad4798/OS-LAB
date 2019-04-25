#include<stdio.h>
#include<stdlib.h>

struct process
{
	
	int r;
	int visited;
}process[40];


int main(void)
{

           int sum=0,i,j,no,present;

printf("enter  number of request: ");
scanf("%d",&no);

printf("\nenter request sequence:\n");

for(i=0;i<no;i++)
{
  scanf("%d",&process[i].r);

  process[i].visited=-1;
}

printf("enter present position\n");

scanf("%d",&present);




for(i=0;i<no;i++)
{


                      
                      int min=99999;
                     int current=-1;

                 for(j=0;j<no;j++)
                 {
                     if(process[j].visited==-1)
                     {
                       if(abs(present-process[j].r)<min)
                            {
                                    min=abs(process[j].r-present);
                                    current=j;
                            }
                     }
                 }
                   
                  sum=sum+min;
                   process[current].visited=1;
                  present=process[current].r;

                 printf("%d(%d)->",process[current].r ,min);






}

printf("\ntotal arm moment:%d\n",sum);





}