#include<iostream>
#include<queue>
#include<map>
using namespace std;
int main()
{
	int n;
	cout<<"Enter the primary memory frame size:";
	cin>>n;
	queue<char>q;
	map<char,int> m;
	cout<<"Enter the reference string:";
	string s;
	cin>>s;
	int pf=0,pr=0;
	for(int i=0;i<s.length();i++)
	{
		if(q.size()<n && m[s[i]] == 0)
		{
			q.push(s[i]);
			m[s[i]]++;
			pf++;
		}
		else
		{
			if(m[s[i]] == 0)
			{
				m[q.front()]--;
				q.pop();
				m[s[i]]++;
				q.push(s[i]);
				pf++;
				pr++;
			}
		}
	}
	cout<<"Page Faults: "<<pf<<endl<<"Page Replacements: "<<pr<<endl;
}	
