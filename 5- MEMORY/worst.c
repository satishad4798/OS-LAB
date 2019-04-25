#include<stdio.h>



int main() 
{ 
	int blockSize[20];
	int processSize[20];
       int m,n,allocation[20],fragment[20];
      int i,j;

	printf("enter the number of partion\n");
   scanf("%d",&m);
   printf("enter the number of process\n");
   scanf("%d",&n);


    printf("enter the partion size\n");
   for(i=0;i<m;i++)
       {
        scanf("%d",&blockSize[i]);

        }

printf("enter the process size\n");
for(i=0;i<n;i++)
{
	scanf("%d",&processSize[i]);

	allocation[i]=-1;
}
	

	
	for (i=0; i<n; i++) 
	{ 
	
		int worstindex = -1; 
		for ( j=0; j<m; j++) 
		{ 
			if (blockSize[j] >= processSize[i]) 
			{ 
				if (worstindex == -1) 
					worstindex = j; 

				else if (blockSize[worstindex] < blockSize[j]) 
					worstindex = j; 
			} 
		} 

		 
		if (worstindex != -1) 
		{ 
			allocation[i] = worstindex; 
			blockSize[worstindex] -= processSize[i]; 
            fragment[i]=blockSize[worstindex];
		} 
	} 

     

           printf("processno\t process size\t block no\t  interalfragment\n");
	
	for (i = 0; i < n; i++) 
	{ 
		
		printf("%d \t\t%d \t\t",i+1,processSize[i] );
		if (allocation[i] != -1) 
		       printf("%d \t\t%d\n",allocation[i]+1,fragment[i]);	             
		else
			 printf("not allocated\n");
	} 

	return 0;
} 








