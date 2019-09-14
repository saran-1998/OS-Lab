#include<iostream>
using namespace std;
typedef struct 
{
	int size;
	int process;
	bool alloc;
	int empt;
}PART;

int wft(PART a[],int p[],int n,int k,int un[],int index)
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
			un[index++] = p[i];
		}
		else
		{
			a[ind].process = p[i];
			a[ind].alloc = true;
			a[ind].empt = a[ind].size - p[i];
		}
	}
	return index;
}

int bft(PART a[],int p[],int n,int k,int un[],int index)
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
			un[index++] = p[i];
		}
		else
		{
			a[ind].process = p[i];
			a[ind].alloc = true;
			a[ind].empt = a[ind].size - p[i];
		}
	}
	return index;
}

int fft(PART a[],int p[],int n,int k,int un[],int index)
{
	for(int i=0;i<k;i++)
	{
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
			un[index++] = p[i];
		}
	}
	return index;
}

void display(PART a[],int n,int un[],int index)
{
	if(index>0)
	{
		cout<<"Compaction occurs"<<endl;
		int sum=0,temp;
		for(int i=0;i<n;i++)
		{
			if(a[i].alloc == true)
			{
				sum+=a[i].empt;
			}
			else
			{
				sum+=a[i].size;
			}
		}
		temp = sum;
		int adst=0,aden;
		for(int i=0;i<n;i++)
		{
			if(a[i].alloc == true)
			{
				aden = a[i].process-1 + adst;
				cout<<"Memory Range:"<<adst<<" --- "<<aden<<" process: "<<a[i].process<<endl;
				adst = aden+1;
			}
		}
		int i;
	
		for(i=0;i<index;i++)
		{
			if(sum>=un[i])
			{
				aden = un[i]-1 + adst;
				cout<<"Memory Range:"<<adst<<" --- "<<aden<<" process: "<<un[i]<<endl;
				adst = aden+1;
				sum = sum - un[i];
			}
			else
			{
				cout<<"Process: "<<un[i]<<" cannot be allocated"<<endl;
			}
		}
		cout<<"Memory left after compaction is: "<<sum<<endl;
	}
	else
	{
		int sum =0,adst=0,aden,adsum=0;
		for(int i=0;i<n;i++)
		{
			adst = 0;
			//cout<<adsum<<endl;
			if(i>0)
				adst = adsum;
			if(a[i].alloc == true)
			{
				aden = a[i].process-1 + adst;
				cout<<"Memory Range:"<<adst<<" --- "<<aden<<" process: "<<a[i].process<<endl;
				if(aden+1!=adsum+a[i].size-1)
					cout<<"Unused Memory:"<<aden+1<<" --- "<<adsum+a[i].size-1<<endl;
			}
			else
			{
				cout<<"Unused Memory:"<<adst<<" --- "<<adsum+a[i].size-1<<endl;
			}
			adsum+=a[i].size;
		}
	}
			
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
	int un[k];
	int index = 0;
	switch(ch)
	{
		case 1:{int in = fft(a,p,n,k,un,index);display(a,n,un,in);} break;
		case 2:{int in = bft(a,p,n,k,un,index);display(a,n,un,in);} break;
		case 3:{int in = wft(a,p,n,k,un,index);display(a,n,un,in);} break;
		default:cout<<"Invalid Case"<<endl;break;
	}	
	return 0;
}		
	
