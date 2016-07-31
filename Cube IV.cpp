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
#define ll unsigned long long
#define mod 1000000007
using namespace std;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool isValid(int x,int y,int n)
{
	if(x>=0&&x<n &&y>=0&&y<n)
		return 1;
	return 0;
}

int bfs(int x,int y,vector<vector<int> >&arr)
{
	queue<pair<int,int> >q;
	q.push(make_pair(x,y));
	int ans=0;
	while(!q.empty())
	{
		pair<int,int> ret=q.front();
		q.pop();
		x=ret.first;
		y=ret.second;
		arr[x][y]*=-1;
		ans++;
		for(int i=0;i<4;i++)
		{
			if(isValid(x+dx[i],y+dy[i],arr[0].size()) && arr[x+dx[i]][y+dy[i]]>0
			&& arr[x+dx[i]][y+dy[i]]+arr[x][y]==1)
				q.push(make_pair(x+dx[i],y+dy[i]));
		}
	}
	return ans;
}

int main()
{
	int t,test,s;
	
	scanf("%d",&test);
	
	for(t=1;t<=test;t++)
	{
		scanf("%d",&s);
		vector<vector<int> >arr(s,vector<int>(s));
		vector<pair<int,int> >ind(s*s);
	
		for(int i=0;i<s;i++)
		{
			for(int j=0;j<s;j++)
			{
				scanf("%d",&arr[i][j]);
				ind[arr[i][j]-1]=make_pair(i,j);
			}
		}
		
		int ans=0;
		int num=0;
		for(int i=0;i<s*s;i++)
		{
			if(arr[ind[i].first][ind[i].second]>0)
			{
				int ret=bfs(ind[i].first,ind[i].second,arr);
				if(ans<ret)
				{
					ans=ret;
					num=i+1;
				}
			}
		}
		printf("Case #%d: %d %d\n",t,num,ans);
	}
	return 0;
}
