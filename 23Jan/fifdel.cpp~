#include<iostream>
#include<queue>
#include<map>
using namespace std;
int main()
{
	int n;
	cout<<"Enter the primary memory frame size:";
	cin>>n;
	queue<string>q;
	map<string,int> m;
	cout<<"Enter the string";
	string s;
	cin>>s;
	int pf=0,pr=0;
	for(int i=0;i<s.length();i++)
	{
		string k = "";
		while(s[i]!=','&&s[i]!='.')
		{
			k+= s[i];
			i++;
		}
		if(q.size()<n)
		{
			q.push(k);
			m[k]++;
			pf++;
		}
		else
		{
			if(m[k] == 0)
			{
				m[q.front()]--;
				q.pop();
				m[k]++;
				q.push(k);
				pf++;
				pr++;
			}
		}
	}
	cout<<"Page Faults: "<<pf<<endl<<"Page Replacements: "<<pr<<endl;
}	
