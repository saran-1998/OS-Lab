#include<sys/wait.h>
#include<unistd.h>
#include<iostream>
#include<cstdlib>
using namespace std;
int main(int argc, char* argv[])
{
	int pid = fork();
	if(pid<0)
	{
		cout<<"Error in Fork"<<endl;
		return 0;
	}
	else if(pid==0)
	{
		cout<<"Hmm"<<endl;
		int num = 0;
		for(int i=0;i<argv[1][i] != '\0';i++)
		{
			num = num*10+(argv[1][i] - '0');
		}
		int a=-1,b=1;
		for(int i=0;i<num;i++)
		{
			int sum = a+b;
			cout<<sum<<endl;
			a=b;
			b=sum;
		}    
	}
	else
	{
		
	}
	return 0;
}
