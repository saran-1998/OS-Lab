#include<iostream.h>
using namespace std;
int main()
{
	int m,n;
	cout<<"Enter the number of processes:";
	cin>>n;
	cout<<"Enter the number of resources:";
	cin>>m;
	bool finish[n] = {false},available[m],work[m];
	cout<<"Enter the available vector values:"<<endl;
	for(int i=0;i<m;i++)
	{
		cin>>available[i];
		work[i] = available[i];
	}
	int max[n][m],alloc[n][m],need[n][m];
	cout<<"Enter the max matrix"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{	
			cin>>max[i][j];
		}
	}
	cout<<"Enter the allocated matrix"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{	
			cin>>alloc[i][j];
			need[i][j] = max[i][j] - alloc[i][j];
		}
	}
	bool find;
	int pos,finno=0,dead = false;
	while(true)
	{
		if(finno==n)
			break;
		for(int i=0;i<n;i++)
		{
			if(!finish[i])
			{
				find = true;
				for(int j=0;j<m;j++)
				{	
					if(need[i][j] >work[j])
					{
						find = false;
						pos = i;
						break;
					}
				}
				if(find)
				{
					for(int j=0;j<m;j++)
					{
						work[j] += alloc[pos][j];
					}
					finno++;
					finish[i] = true;
				}
				else
				{
					dead = true;
					break;
				}				
			}			
		}
		if(dead == true)
		{
			cout<<"The system is not in safe state"<<endl;
		}
		else if(finno == n)
		{
			cout<<"The system is in safe state"<<endl;
	}
