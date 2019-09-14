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
	for(int i=0;i<s.length();i++)
	{
		if(m.size()<n && m[s[i]] == 0)
		{
			m[s[i]]++;
			pf++;
		}
		else
		{
			if(m[s[i]]==0)
			{
				map<char,int>::iterator it = m.begin();
				int max = 0,pos;
				char maxval,ele;
				for(;it!=m.end();it++)
				{
					if(it->second>0)
					{
						ele = it->first;
						for(int j=i+1;j<s.length();j++)
						{
							if(s[j] == ele)
							{
								pos = j;
								break;
							}
							if(j==s.length()-1)
							{
								pos = s.length();
							}
						}
						if(pos == s.length())
						{
							maxval = ele;
							break;
						}
						else if(pos>max)
						{
							max = pos;
							maxval = s[pos];
						}
					}
				}
				m.erase(maxval);
				m[s[i]]++;
				pf++;
				pr++;
			}
		}
	}
	cout<<"Page Faults: "<<pf<<endl<<"Page Replacements: "<<pr<<endl;
	return 0;
}
