
//this code in for SEQUENTIAL

#include<stdio.h>
#include<stdlib.h>

struct file
{
	int start,size;
  int blocksReq;
}file[20];


int main(void)
{

         int i,j,temp,noOfFiles,disksize,blocksize;
         printf("enter disk size\n");
	   printf("enter block size\n");
         scanf("%d %d",&disksize,&blocksize);
            int array[500];
int k;
          int block[100];
            int choice;

          int totalblocks=disksize/blocksize; 
           
           for(i=0;i<500;i++)
           	array[i]=-1;
          
            int id;
            i=0;
          while(1)
          {
              printf("\n1.add file 2.delete" );
                scanf("%d",&choice);

                
                if(choice==1)
                {
                
               printf(" enter file id \nenter file size \n file start address\n");

                 scanf("%d %d %d",&id,&file[i].size,&file[i].start);
                          
                          if(file[i].size%blocksize==0)
                             file[i].blocksReq=file[i].size/blocksize;
                           else
                            file[i].blocksReq=file[i].size/blocksize+1;

                  temp=file[i].start;
                 int temp2=file[i].start;


              
              for(j=0;j<file[i].blocksReq;j++,temp++)
              {    
                if(array[temp]!=-1)
                  {
                   printf("already used\n");
                   i--;
                    break; 
                   } 
                 
              }
                    if(j==file[i].blocksReq)
                    {
                      temp=file[i].start;
                             temp2=file[i].start;

                    for(j=0;j<file[i].blocksReq;j++)
                    { 

                        array[temp]=id;
                        temp++;
                        
                          
                    }


                      for( k=0;k<totalblocks;k++)
                      {
                        if(array[k]==-1)
                          printf("*->\t");
                          else
                        printf("%d->\t",array[k]);
                      
                     
                      
                      }
                    } 


                 i++;
                }

                  else
                  {int ss;
                    printf("enter file number\n");
                    scanf("%d",&ss);

                    for(i=0;i<totalblocks;i++)
                    {
                      if(array[i]==ss)
                      {
                        array[i]=-1;
                      }
                    }




                  }





                
          }





 }//end
     

