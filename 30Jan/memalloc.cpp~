#include<iostream>
using namespace std;
typedef struct 
{
	int size;
	int process;
	bool alloc;
	int empt;
}PART;

void wft(PART a[],int p[],int n,int k)
{
	for(int i=0;i<k;i++)
	{
		int fl = 0;
		int max = 0,ind = -1;
		for(int j=0;j<n;j++)
		{
			if(p[i]<=a[j].size && a[j].alloc!=true)
			{
				if(a[j].size-p[i]>max)
				{
					max = a[j].size-p[i];
					ind = j;
				}
			}
		}
		if(ind == -1)
		{
			cout<<"process "<<i+1<<" with memory "<<p[i]<<" cannot be allocated"<<endl;
		}
		else
		{
			a[ind].process = p[i];
			a[ind].alloc = true;
			a[ind].empt = a[ind].size - p[i];
		}
	}
}

void bft(PART a[],int p[],int n,int k)
{
	for(int i=0;i<k;i++)
	{
		int fl = 0;
		int min = 99999,ind = -1;
		for(int j=0;j<n;j++)
		{
			if(p[i]<=a[j].size && a[j].alloc!=true)
			{
				if(a[j].size-p[i]<min)
				{
					min = a[j].size-p[i];
					ind = j;
				}
			}
		}
		if(ind == -1)
		{
			cout<<"process "<<i+1<<" with memory "<<p[i]<<" cannot be allocated"<<endl;
		}
		else
		{
			a[ind].process = p[i];
			a[ind].alloc = true;
			a[ind].empt = a[ind].size - p[i];
		}
	}
}

void fft(PART a[],int p[],int n,int k)
{
	for(int i=0;i<k;i++)
	{
		cout<<p[i]<<endl;
		int fl = 0;
		for(int j=0;j<n;j++)
		{
			if(p[i]<=a[j].size && a[j].alloc!=true)
			{
				fl=1;
				a[j].process = p[i];
				a[j].alloc = true;
				a[j].empt = a[j].size - p[i];
				break;
			}
		}
		if(fl==0)
		{
			cout<<"process "<<i+1<<" with memory "<<p[i]<<" cannot be allocated"<<endl;
		}
	}
}

void display(PART a[],int n)
{
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
}

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
	int p[k];
	for(int i=0;i<k;i++)
	{
		cin>>p[i];
	}
	cout<<"1.First Fit\n2.Best Fit\n3.Worst Fit\nEnter the choice:";
	int ch;
	cin>>ch;
	switch(ch)
	{
		case 1:fft(a,p,n,k);display(a,n);break;
		case 2:bft(a,p,n,k);display(a,n);break;
		case 3:wft(a,p,n,k);display(a,n);break;
		default:cout<<"Invalid Case"<<endl;break;
	}	
	return 0;
}
			
	
