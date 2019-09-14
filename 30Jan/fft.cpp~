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
	cout<<"Enter the sizes of "<<n<<" memory partitions:";
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
	cout<<"Enter the sizes of "<<k<<" processes:";
	for(int i=0;i<k;i++)
	{
		int temp;
		cin>>temp;
		int fl = 0;
		for(int j=0;j<n;j++)
		{
			if(temp<=a[j].size && a[j].alloc!=true)
			{
				fl=1;
				a[j].process = temp;
				a[j].alloc = true;
				a[j].empt = a[j].size - temp;
				break;
			}
		}
		if(fl==0)
		{
			cout<<"process "<<i+1<<" with memory "<<temp<<" cannot be allocated"<<endl;
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
			
	
