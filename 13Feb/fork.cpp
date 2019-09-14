#include<bits/stdc++.h>
#include<unistd.h>
#include<iostream>
using namespace std;
int main()
{
	int value = 5;
	int pid = fork();
	if(pid==0)
	{
		value += 15;
		return 0;
	}
	else if(pid>0)
	{
		wait();
		cout<<value<<endl;
		return 0;
	}
	return 0;
}


//find out how many processes are created //

/*fork
fork fork*/

//print all the pid values
/*pid = fork();
if(pid<0)
	cout<<"fork has failed"<<endl;
	return;
else if(pid=0)
	pid1 = getpid();
	cout<<pid<<endl;
	cout<<pid1;
else
	pid1 = getpid();
        cout<<pid<<pid1;
*/
	/*int pid = fork();
	if(pid == 0)
	{
		int prc = getpid();
		int par = getppid();
		int group = 
		cout<<"Process id:"<<prc<<endl;
		cout<<"Parent Process id:"<<prc<<endl;
	}
	else if(pid>0)
	{
		int prc = getpid();
		cout<<"This is parent. Process id:"<<prc<<endl;
	}*/

