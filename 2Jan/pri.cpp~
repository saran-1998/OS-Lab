#include<iostream>
using namespace std;
typedef struct 
{
        int number;
        int burst_time;
        int arrival_time;
        int priority;
        int wait_time;
        int turn_time;
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
void sortpr(PROCESS* p,int n)
{
	int i,j;
	for(i=1;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i].priority > p[j].priority)
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
        int n,i,j,fin=0;
        float avg_wait=0,avg_turn=0;
        cout<<"Enter the number of processes";
        cin>>n;
        PROCESS pr[n];
        for(i=0;i<n;i++)
        {
                cout<<"Enter the process number , burst time, arrival time, priority\n";
                cin>>pr[i].number>>pr[i].burst_time>>pr[i].arrival_time>>pr[i].priority;
                pr[i].exec = 0;
        }
        sort(pr,n);
        int init = pr[0].arrival_time,curtime = init + pr[0].burst_time;       
        pr[0].wait_time = 0;
        pr[0].turn_time = pr[0].burst_time;
        pr[0].exec = 1;
        fin++;
        cout<<"Process: "<<pr[0].number<<"\tWaiting Time: "<<pr[0].wait_time<<"\tTurn around time: "<<pr[0].turn_time<<endl;
        avg_wait+=pr[0].wait_time;
        avg_turn+=pr[0].turn_time;
        sortpr(pr,n);
        while(fin!=n)
        {
        	int minarr = 9999;
        	int fl=0;
        	for(i=1;i<n;i++)
        	{
        		//cout<<curtime<<" "<<pr[i].arrival_time<<endl; 
        		if(curtime >= pr[i].arrival_time && pr[i].exec == 0)
        		{
        			fl = 1;
        			pr[i].wait_time = curtime - pr[i].arrival_time;
        			pr[i].turn_time = pr[i].burst_time + pr[i].wait_time;
        			curtime += pr[i].burst_time;
        			cout<<"Process: "<<pr[i].number<<"\tWaiting Time: "<<pr[i].wait_time<<"\tTurn around time: "<<pr[i].turn_time<<endl;
        			fin++;
        			pr[i].exec = 1;
        			avg_wait+=pr[i].wait_time;
        			avg_turn+=pr[i].turn_time;
        			break;
        		}
        	}
        	if(fl==0)
        	{
        		curtime = minarr;
        	}        	
        }
        avg_wait = avg_wait/n;
        avg_turn = avg_turn/n;
        cout<<"Average Wait Time ="<<avg_wait<<"\nAverage Turn around time ="<<avg_turn<<endl;
        return 0;
}
