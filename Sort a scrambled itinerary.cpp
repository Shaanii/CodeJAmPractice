#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<queue>
#include<map>
#include<stack>
#include<vector>
#include<ctime>
#include<cstring>
#include<algorithm>
#include<set>
#include <iomanip>
#include<cmath>
#define ll long long
#define mod 1000000007
using namespace std;

int main()
{
	int t,n,test;
	
	scanf("%d",&test);
	
	for(t=1;t<=test;t++)
	{
		scanf("%d",&n);
		map<string, string>m;
		map<string, string>::iterator it;
		set<string>s;
		for(int i=1;i<=n;i++)
		{
			string a,b;
			cin>>a>>b;
			m[a]=b;
			s.insert(b);
		}
		
		string st;
		for(it=m.begin();it!=m.end();it++)
		{
			if(s.find(it->first)==s.end())
			{
				st=it->first;
				break;
			}
		}
		printf("Case #%d: ",t);
		while(true)
		{
			printf("%s-",st.c_str());
			it=m.find(st);
			printf("%s ",it->second.c_str());
			st=it->second;
			if(m.find(st)==m.end())
				break;
		}
		printf("\n");
	}
	return 0;
}
tickets.cpp
Open with
3 of 3 items
