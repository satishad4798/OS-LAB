#include<stdio.h>
#include<stdlib.h>

struct file
{
	int start,size;
  int blocksReq;
}file[20];
       

int main(void)
{               int empty=0;
                      int filling=0;
         int i,j,temp,noOfFiles,disksize,blocksize;
         printf("enter disk size\n");
	   printf("enter block size\n");
         scanf("%d %d",&disksize,&blocksize);
            int array[500];

          int block[100];
            int choice,k,m;

          int totalblocks=disksize/blocksize; 
           
           for(i=0;i<500;i++)
           	array[i]=-1;
          
            int id;
            i=1;
          while(1)
          {
              printf("\n1.add file 2.delete" );
                scanf("%d",&choice);

                
                if(choice==1)
                {
                
               printf("enter file size and file id \n\n");

               //  scanf("%d ",&file[i].size);
             scanf("%d %d",&file[i].size,&id);
                          
                   if(file[i].size%blocksize==0)
                       file[i].blocksReq=file[i].size/blocksize;
                   else
                  file[i].blocksReq=file[i].size/blocksize+1;

                 
                    empty=0;
               
               for(m=0;m<totalblocks;m++)
               {
               	if(array[m]==-1)
               		empty++;

               }
              
              if(file[i].blocksReq>empty)   
                 {
                 	printf("cannot allocate\n");
                 }

               else                 //if empty available
                    {

                    

                    for(j=0;j<file[i].blocksReq;j++)
                    { 
                        
                         for(k=0;k<totalblocks;k++)
                         {
                         	if(array[k]==-1)
                         	{
                         		array[k]=id;
                         		break;
                         	}
                         	if(k==totalblocks)
                         		k=0;
                         }
                        
                        
                          
                    }


                      for( k=0;k<totalblocks;k++)
                      {
                        if(array[k]==-1)
                          printf("*->\t");
                          else
                        printf("%d->\t",array[k]);
                      
                     
                      
                      }

                    } //if free space


                 i++;
                }

                  else
                  {int ss;
                    printf("enter file number\n");
                    scanf("%d",&ss);

                    for(m=0;m<totalblocks;m++)
                    {
                      if(array[m]==ss)
                      {
                        array[m]=-1;
                      }
                    }
                     for( k=0;k<totalblocks;k++)
                      {
                        if(array[k]==-1)
                          printf("*->\t");
                          else
                        printf("%d->\t",array[k]);
                      
                     
                      
                      }



                  }





                
          }





 }//end
     

