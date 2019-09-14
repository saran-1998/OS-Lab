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
	        char file[] = "./fib";
	        char* args[] = {file,argv[1],NULL};
	        execvp(args[0],args);	        
		
	}
	else
	{
		int num = 0;
		for(int i=0;i<argv[1][i] != '\0';i++)
		{
			num = num*10+(argv[1][i] - '0');
		}
		if(num<=0)
		{
			cout<<"Invalid arguments"<<endl;
			kill(0,SIGKILL);
		}
		else
		{
			wait(NULL);
			cout<<"Execution complete"<<endl;
		}
	}
	return 0;
}
