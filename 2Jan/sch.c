#include<stdio.h>
typedef struct 
{
        int number;
        int burst_time;
        int arrival_time;
        int priority;
        int wait_time;
        int turn_time;
} PROCESS;
void sort(PROCESS* p,int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i].arrival_time > p[j].arrival_time)
			{
				PROCESS temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
} 
int main()
{
        int n,i,j;
        printf("Enter the number of processes");
        scanf("%d",&n);
        PROCESS pr[n];
        for(i=0;i<n;i++)
        {
                printf("Enter the process number , burst time, arrival time, priority\n");
                scanf("%d%d%d%d",&pr[i].number,&pr[i].burst_time,&pr[i].arrival_time,&pr[i].priority);
        }
        sort(pr,n);
        int init = pr[0].arrival_time,curtime = init + pr[0].burst_time;       
        pr[0].wait_time = 0;
        pr[0].turn_time = pr[0].burst_time;
        for(i=1;i<n;i++)
        {
        	if(curtime > pr[i].arrival_time)
        	{
        		pr[i].wait_time = curtime - pr[i].arrival_time;
        	}
        	else
        	{
        		pr[i].wait_time = 0;
        		curtime += (pr[i].arrival_time - curtime);
        	}
        	pr[i].turn_time = pr[i].burst_time + pr[i].wait_time;
        	curtime += pr[i].burst_time;
        }
        float avg_wait=0,avg_turn=0;
        for(i=0;i<n;i++)
        {
        	printf("Process: %d\tWaiting Time: %d\tTurn around time: %d\n",pr[i].number,pr[i].wait_time,pr[i].turn_time);
        	avg_wait+=pr[i].wait_time;
        	avg_turn+=pr[i].turn_time;
        }
        avg_wait = avg_wait/n;
        avg_turn = avg_turn/n;
        printf("Average Wait Time = %f\nAverage Turn around time = %f\n",avg_wait,avg_turn);
        return 0;
}
