#include<stdio.h>
#include<stdlib.h>

struct process
{
	
	int r;
	int visited;
}process[40];


int main(void)
{

           int sum=0,i,j,no,present,previous;

int current;

printf("enter  number of request: ");
scanf("%d",&no);

printf("\nenter request sequence:\n");

for(i=0;i<no;i++)
{
  scanf("%d",&process[i].r);

  process[i].visited=-1;
}

int first,last;
printf("enter boundarys for disk\n");
scanf("%d",&first);
scanf("%d",&last);

printf("enter present position\n");

scanf("%d",&present);

printf("enter previous position \n");
scanf("%d",&previous);


for(i=0;i<no;i++)
{
  for(j=i;j<no;j++)
  {
         if(process[i].r>process[j].r)
         {
          int temp=process[i].r;
            process[i].r=process[j].r;
            process[j].r=temp;

         }
  }
}

printf("check:\n");
for(i=0;i<no;i++)
{
  printf("%d ",process[i].r);
}


if((present-previous)>0)        // move forward
   {
           

           for(i=0;i<no;i++)
           {
            if(present<=process[i].r)
             { 
              current=process[i].r;
                break;

                }
           }

           printf("\nsequence is:\n");


            for(i=0;i<no;i++)
            {
              if(process[i].r>=current)
              {
                printf("%d ",process[i].r);
                    process[i].visited=1;
              }
            }

            for(i=no-1;i>-1;i--)
            {
                     if(process[i].visited==-1){
                printf("%d ",process[i].r);
                    process[i].visited=1; 
                  }
            }



           

           sum=last-present+last-process[0].r;
             printf("total arm  moment:%d\n",sum );


         



   }
  else                                //back
  {

 for(i=0;i<no;i++)
           {
            if(present>=process[i].r)
             { 

                 current=process[i].r;
              }
               else
               {
                  break;
               } 
           }

           printf("\nsequence is:\n");


            

            for(i=no-1;i>-1;i--)
            {
                    if(process[i].r<=current)
                    {
                     printf("%d ",process[i].r);
                      process[i].visited=1;
                     }
            }   


          for(i=0;i<no;i++)
            {
              if(process[i].r>current)
              {
                printf("%d ",process[i].r);
                    process[i].visited=1;
              }
            }


           

           sum=present-first+process[no-1].r;
             printf("total arm  moment:%d\n",sum );



  } 














}