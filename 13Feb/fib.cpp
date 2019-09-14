#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
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
	return 0;
}
