#include<stdio.h>
struct process{
	int pid,at,visited,bt,ct,tat,wt;
};

void main()
{
	int i =0, n,j;
	int time=0;

	printf("Enter number of processes: \n");
	scanf("%d", &n);

	struct process p[10];
	while(i<n){
		p[i].visited = 0;
		p[i].pid = i;
		printf(" the arrival time of %d process: \n", i );
		scanf("%d", &p[i].at);
		printf("Enter burst time of %d process \n:", i);
		scanf("%d",&p[i].bt);
		i++;
	}
	struct process temp;
	for(i=0;i<n;i++)
	{	for ( j = 0; j<n-1;j++)
		{
			if(p[j].at > p[j+1].at)
			{
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}
	int temp_bt[10];
	i = 0;
	while(i<n){
		temp_bt[i] = p[i].bt;
		i++;
	}
	

	int count = 0;
	int flag = 1;
	i=0;
	while(flag)
	{	
		int j;
		int small_index=-1;
		struct process small;
		small.bt=32000;
		for(j=0;j<n;j++){
			if(p[j].at <= time && p[j].visited == 0)
			{	
				if(p[j].bt <= small.bt){
					small_index = j;
					small = p[j];
				}
			}
			
		}
		if(small_index==-1)
		{
			for(i=0;i<n;i++)
			{
				if(p[i].at>time && p[i].visited==0)
				{
					small_index=i;
					break;
				}
			}
		}
		i = small_index;

		if(p[i].at > time)
		{
			printf("The process was idle from %d to %d\n",time,p[i].at );
			time  = p[i].at;
			
		}
		else
		{	p[i].bt--;
			time = time + 1;
				
			if (p[i].bt == 0)
			{
				
				p[i].visited =1;	
				p[i].ct = time;
				p[i].tat = p[i].ct - p[i].at;
				p[i].wt = p[i].tat - temp_bt[i];
			}
				
		}

		int k,count=0;
		for (k = 0; k < n; ++k)
			if ( p[k].visited == 1)	
				count++;
		if (count == n)
			flag = 0;

	}
	printf("pid 	A.T 	B.T 	C.T 	T.A.T 	W.T\n");
	int avg_tat=0,avg_ct=0,avg_wt=0;
	for ( i = 0; i < n; ++i)
	{
			printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, temp_bt[i],p[i].ct,p[i].tat,p[i].wt);
			avg_tat+=p[i].tat;
			avg_ct+=p[i].ct;
			avg_wt+=p[i].wt;
	}

	printf("\nThe average C.T: %f\n",(float)(avg_ct/(float)n));
	printf("The average T.A.T: %f\n",(float)(avg_tat/(float)n));
	printf("The average W.T: %f\n",(float)(avg_wt/(float)n));
}
