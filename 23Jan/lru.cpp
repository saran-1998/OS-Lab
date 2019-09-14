#include<iostream>
#include<map>
using namespace std;
int main()
{
	int n;
	cout<<"Enter the primary memory frame size:";
	cin>>n;
	map<char,int> m,posm;
	cout<<"Enter the reference string:";
	string s;
	cin>>s;
	int pf=0,pr=0;
	for(int i=0;i<s.size();i++)
	{
		if(m.size()<n && m[s[i]] == 0)
		{
			m[s[i]]++;
			posm[s[i]] = i+1;
			pf++;
		}
		else
		{
			if(m[s[i]]==0)
			{
				map<char,int>::iterator it = posm.begin();
				int mins = 9999,minval;
				for(;it!=posm.end();it++)
				{
					if(it->second < mins)
					{
						mins = it->second;
						minval = it->first;
					}
				}
				posm.erase(minval);
				m[minval]--;
				m[s[i]]++;
				posm[s[i]] = i+1;
				pf++;
				pr++;
			}  
			else
			{
				posm[s[i]] = i+1;;
			}
		}
	}
	cout<<"Page Faults: "<<pf<<endl<<"Page Replacements: "<<pr<<endl;
	return 0;
}
