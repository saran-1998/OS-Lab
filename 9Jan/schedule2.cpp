#include<iostream>
using namespace std;
typedef struct 
{
        int number;
        int burst_time;
        int arrival_time;
        int wait_time;
        int turn_time;
        int rem_time;
        double res_ratio;
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
int minrat(PROCESS *pr,int n,int cur)
{
	for(int i=1;i<n;i++)
	{
		if(pr[i].arrival_time<=cur&&!pr[i].exec)
		{
			pr[i].res_ratio = (((double)(cur - pr[i].arrival_time))+pr[i].burst_time)/pr[i].burst_time;
		}
	}
	int max = 0,ind=0;
	for(int i=1;i<n;i++)
	{
		if(pr[i].res_ratio!=-1&&!pr[i].exec)
		{
			if(pr[i].res_ratio>max)
			{
				max = pr[i].res_ratio;
				ind = i;
			}
		}
	}
	return ind;
}
int main()
{
        int n,i,j;
        float avg_wait=0,avg_turn=0;
        cout<<"Enter the number of processes:";
        cin>>n;
        PROCESS pr[n];
        for(i=0;i<n;i++)
        {
                cout<<"Enter the process number , arrival time, burst time\n";
                cin>>pr[i].number>>pr[i].arrival_time>>pr[i].burst_time;
                pr[i].exec = 0;
                pr[i].res_ratio = -1;
        }
        sort(pr,n);
        int curtime = pr[0].arrival_time;
        pr[0].wait_time = 0;
        pr[0].turn_time = pr[0].burst_time;
        pr[0].res_ratio = 1;
        cout<<"Process\tWait Time\tTurn Around Time\n";
        cout<<pr[0].number<<"\t"<<pr[0].wait_time<<"\t\t"<<pr[0].turn_time<<endl;
        int fin=1;
        curtime+=pr[0].burst_time;
        double avgta = pr[0].turn_time,avgwt = pr[0].wait_time;
        while(fin<n)
        {
        	int minind = minrat(pr,n,curtime);
        	fin++;
        	curtime+=pr[minind].burst_time;
        	pr[minind].exec = 1;
        	pr[minind].turn_time = curtime - pr[minind].arrival_time;
        	pr[minind].wait_time = pr[minind].turn_time - pr[minind].burst_time;
        	avgta += pr[minind].turn_time;
        	avgwt += pr[minind].wait_time;
        	cout<<pr[minind].number<<"\t"<<pr[minind].wait_time<<"\t\t"<<pr[minind].turn_time<<endl;
        }
        avgta/=n;
        avgwt/=n;
        cout<<"Avg Wait Time:"<<avgwt<<endl<<"Avg Turn Around Time:"<<avgta<<endl;
        return 0;
}
