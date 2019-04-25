#include<stdio.h>

struct process
{
      char process_name;
      int at, bt, ct, wt, tat, priority;
      int status;
}process_queue[10];

int limit;

void Arrival_Time_Sorting()
{
      struct process temp;
      int i, j;
      for(i = 0; i < limit - 1; i++)
      {
            for(j = i + 1; j < limit; j++)
            {
                  if(process_queue[i].at > process_queue[j].at)
                  {
                        temp = process_queue[i];
                        process_queue[i] = process_queue[j];
                        process_queue[j] = temp;
                  }
            }
      }
}

void main()
{
      int i, time = 0, bt = 0, largest;
      char c;
      float wt = 0, tat = 0, avwt, avtat;
      printf("\nEnter Total Number of Processes:\t");
      scanf("%d", &limit);
      for(i = 0, c = 'A'; i < limit; i++, c++)
      {
            process_queue[i].process_name = c;
            printf("\nEnter Details For Process[%C]:\n", process_queue[i].process_name);
            printf("Enter Arrival Time:\t");
            scanf("%d", &process_queue[i].at );
            printf("Enter Burst Time:\t");
            scanf("%d", &process_queue[i].bt);
            printf("Enter Priority:\t");
            scanf("%d", &process_queue[i].priority);
            process_queue[i].status = 0;
            bt = bt + process_queue[i].bt;
      }
      Arrival_Time_Sorting();
      process_queue[9].priority = -9999;
      printf("\nProcess Name\tArrival Time\tBurst Time\tPriority\tWaiting Time\tcompletion time\t");
      for(time = process_queue[0].at; time < bt;)
      {
            largest = 9;
            for(i = 0; i < limit; i++)
            {
                  if(process_queue[i].at <= time && process_queue[i].status != 1 && process_queue[i].priority > process_queue[largest].priority)
                  {
                        largest = i;
                  }
            }
            time = time + process_queue[largest].bt;
            process_queue[largest].ct = time;
            process_queue[largest].wt = process_queue[largest].ct - process_queue[largest].at - process_queue[largest].bt;
            process_queue[largest].tat = process_queue[largest].ct - process_queue[largest].at;
            process_queue[largest].status = 1;
            wt = wt + process_queue[largest].wt;
            tat = tat + process_queue[largest].tat;
            printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", process_queue[largest].process_name, process_queue[largest].at,process_queue[largest].bt,process_queue[largest].priority, process_queue[largest].wt,process_queue[largest].tat,process_queue[largest].ct);
      }
      avwt = wt / limit;
      avtat = tat / limit;
      printf("\n\nAverage waiting time:\t%f\n", avwt);
      printf("Average Turnaround Time:\t%f\n", avtat);
}