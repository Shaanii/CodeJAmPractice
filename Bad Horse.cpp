Conversation opened. 1 unread message.
  More 
Print all
badhorse
Inbox
x 

Anuj Kumar
Attachments11:52 PM (0 minutes ago)

to me 

Attachments area
	
Click here to Reply or Forward
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

bool dfs(int u,vector<vector<int> >&edge,vector<int>&color)
{
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
		if(color[v]==0)
		{
			color[v]=color[u]==1?2:1;
			if(dfs(v,edge,color))
				return 1;
		}
		else if(color[u]==color[v])
			return 1;
	}
	return 0;
}

int main()
{
	int t,m,test;
	
	cin>>test;
	
	for(t=1;t<=test;t++)
	{
		cin>>m;
		map<string,int>M;
		vector<vector<int> >edge(201);
		int curr=1;
		for(int i=1;i<=m;i++)
		{
			string a,b;
			cin>>a>>b;
			if(M.find(a)==M.end())
			{
				M[a]=curr;
				curr++;
			}
			if(M.find(b)==M.end())
			{
				M[b]=curr;
				curr++;
			}
			edge[M[a]].push_back(M[b]);
			edge[M[b]].push_back(M[a]);
		}
		vector<int>color(curr,0);
		bool ret=0;
		for(int i=1;i<curr;i++)
		{
			if(color[i]==0)
			{
				color[i]=1;
				ret=dfs(i,edge,color);
				if(ret)break;
			}
		}
		printf("Case #%d: ",t);
		if(ret)
			printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}	
