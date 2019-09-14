#include<iostream>
using namespace std;
typedef struct 
{
        int number;
        int burst_time;
        int arrival_time;
        int wait_time;
        int turn_time;
        int cons_time;
        int res_time;
        int exec;
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
int minTime(PROCESS* pr,int n,int cur)
{
	int minval = 9999;
	int minind;
	for(int i=0;i<n;i++)
	{
		if(pr[i].arrival_time <= cur && pr[i].exec == 0)
		{
			if(pr[i].cons_time < minval)
			{
				minval = pr[i].cons_time;
				minind = i;
			}
		}
	}
	return minind;
}
int main()
{
        int n,i,j,fin=0;
        float avg_wait=0,avg_turn=0;
        cout<<"Enter the number of processes";
        cin>>n;
        PROCESS pr[n];
        for(i=0;i<n;i++)
        {
                cout<<"Enter the process number , arrival time, burst time\n";
                cin>>pr[i].number>>pr[i].arrival_time>>pr[i].burst_time;
                pr[i].cons_time = 0;
                pr[i].exec = 0;
        } 
        sort(pr,n);
        int curtime = pr[0].arrival_time;
        while(fin!=n)
        {
        	int minind = minTime(pr,n,curtime);
        	if(pr[minind].cons_time == 0)
		{
			pr[minind].res_time = curtime - pr[minind].arrival_time;
		}
        	pr[minind].cons_time++;
        	curtime++;
        	if(pr[minind].cons_time == pr[minind].burst_time)
        	{
        		pr[minind].exec = 1;
        		fin++;
        		pr[minind].wait_time = curtime - pr[minind].arrival_time - pr[minind].burst_time;
        		pr[minind].turn_time = curtime - pr[minind].arrival_time;
        		cout<<"Process: "<<pr[minind].number<<"\tWaiting Time: "<<pr[minind].wait_time<<"\tTurn around time: "<<pr[minind].turn_time<<"\tResponse Time:"<<pr[minind].res_time<<endl;
        		avg_wait+=pr[minind].wait_time;
        		avg_turn+=pr[minind].turn_time;
        	}
        }	        	
        avg_wait = avg_wait/n;
        avg_turn = avg_turn/n;
        cout<<"Average Wait Time ="<<avg_wait<<"\nAverage Turn around time ="<<avg_turn<<endl;
        return 0;
}
