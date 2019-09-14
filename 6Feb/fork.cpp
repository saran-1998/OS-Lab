#include<unistd.h>
#include<iostream>
using namespace std;
int main()
{
	for(int i=0;i<2;i++)
	{
		pid_t pid = fork();
		cout<<pid<<endl;
		if(pid == 0)
			cout<<"Hell Yeah"<<endl;
		else 
			cout<<"Hell no"<<endl;
	}
}
