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
	int t,test,n,a,b;
	scanf("%d",&test);
	
	for(t=1;t<=test;t++)
	{
		scanf("%d",&n);
		vector<int>v(5002,0);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			v[a]++;
			v[b+1]--;
		}
		for(int i=1;i<=5000;i++)
			v[i]=v[i]+v[i-1];
		
		scanf("%d",&a);
		printf("Case #%d: ",t);
		
		while(a--)
		{
			scanf("%d",&b);
			printf("%d ",v[b]);
		}
		printf("\n");
	}
	return 0;
}
