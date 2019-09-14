#include<iostream>
using namespace std;
typedef struct 
{
	int size;
	int process;
	bool alloc;
	int empt;
}PART;
int main()
{
	int n;
	cout<<"Enter the number of memory partitions: ";
	cin>>n;
	cout<<"Enter the sizes of "<<n<<" memory partitions:"<<endl;
	PART a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i].size;
		a[i].alloc = false;
		a[i].empt = 0;
	}
	cout<<"Enter the number of proceses: ";
	int k;
	cin>>k;
	cout<<"Enter the sizes of "<<k<<" processes:"<<endl;
	for(int i=0;i<k;i++)
	{
		int temp;
		cin>>temp;
		int fl = 0;
		int max = 0,ind = -1;
		for(int j=0;j<n;j++)
		{
			if(temp<=a[j].size && a[j].alloc!=true)
			{
				if(a[j].size-temp>max)
				{
					max = a[j].size-temp;
					ind = j;
				}
			}
		}
		if(ind == -1)
		{
			cout<<"process "<<i+1<<" with memory "<<temp<<" cannot be allocated"<<endl;
		}
		else
		{
			a[ind].process = temp;
			a[ind].alloc = true;
			a[ind].empt = a[ind].size - temp;
		}
	}
	int sum=0;
	for(int i=0;i<n;i++)
	{
		if(a[i].alloc == true)
		{
			cout<<"Process "<<a[i].process<<" is allocated in partition "<<a[i].size<<endl;
			sum+=a[i].empt;
		}
	}
	cout<<"Total internal fragment is "<<sum<<endl;
	return 0;
}
			
	
