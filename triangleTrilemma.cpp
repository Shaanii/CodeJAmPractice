// Ideone_Language_Id:1
/* Don't remove the first line! */
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <set>
#include <utility>
#include <stack>
#include <cmath>
#include <cassert>
#include<queue>
//Input-output macros
#define s(n) scan(&n)
//#define p(n) printf("%d\n",n)
#define pl(n) printf("%lld\n",n)
#define sf(n) scanf("%f",&n)
#define pf(n) printf("%f\n",n)
#define sc(n) scanf("%c",&n);
#define pc(n) printf("%c\n",n)
#define ss(n) scanf("%s",n)
#define ps(n) printf("%s\n",n)
#define mem(x,val) memset((x),(val),sizeof(x));
// Useful constants
#define INF (int)1e9
#define EPS 1e-9
// Useful hardware instructions
#define bitcount __builtin_popcount
#define lz __builtin_clz
#define tz __builtin_ctz
#define gcd __gcd
// Useful container manipulation / traversal macros
#define forall(i,a,b) for(int i=a;i<b;i++)
#define forrev(i,a,b) for(int i=a;i>b;i--)
#define foreach(v,c) for(typeof((c).begin()) v=(c).begin();v!=(c).end();++v)
#define all(a) a.begin(),a.end()
//#define in(a,b) ((b).find(a)!=(b).end())
#define pb push_back
#define fill(a,v) memset(a,v,sizeof a)
#define sz(a) ((int)(a.size()))
//#define mp make_pair
// Some common useful functions
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define checkbit(n,b) ((n>>b)&1)
#define DREP(a) sort(all(a));a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind) (lower_bound(all(arr),ind)-arr.begin())
#include <stdlib.h>
# include <stdio.h>
# include <time.h>
#include <iostream>
#include<limits.h>
#include <sstream>
#include<vector>
#include <algorithm>
#define eps 1e-8
#define bs 1000000007
#define bsize 512
using namespace std;
int func( int a, int b,int c, int d) {
    return ( (a-c)*(a-c) + (b-d)*(b-d) );
}
int main () {
freopen("A-large-practice.in","r",stdin);
freopen("output.out","w",stdout);
  int t;
  cin >> t;
  for(int xx = 1 ; xx <= t ; ++xx) {
   int x1,y1,x2,y2,x3,y3;
   cin >>x1>>y1>>x2>>y2>>x3>>y3;
   if(   ( (x1 - x3)*(y2 - y1)   -  (x1 - x2)*(y3 - y1) )   == 0   )
    {
        cout<<"Case #"<<xx<<": not a triangle"<<endl;
        continue;
    }
   int a = func(x1,y1,x2,y2);
   int b = func(x2,y2,x3,y3);
   int c = func(x1,y1,x3,y3);
   vector<int> v;
   v.push_back(a);
   v.push_back(b);
   v.push_back(c);
   sort(v.begin(), v.end());
   int x, y;
   if( v[0] + v[1] == v[2])
        x = 3;
   else if( v[0] + v[1] > v[2])
        x = 1;
   else
        x = 2;
    if(  (a != b)  &&  (b != c )  &&  (c !=a) )
        y = 2;
    else
        y =1;
    cout<<"case #"<<xx<<": ";
    if( x == 1  && y == 1)
        cout<<"isosceles acute triangle"<<endl;
    else if( x == 1  && y == 2)
        cout<<"scalene acute triangle"<<endl;
    else if( x == 2  && y == 1)
        cout<<"isosceles obtuse triangle"<<endl;
    else if( x == 2  && y == 2)
        cout<<"scalene obtuse triangle"<<endl;
    else if( x == 3  && y == 1)
        cout<<"isosceles right triangle"<<endl;
    else if( x == 3  && y == 2)
        cout<<"scalene right triangle"<<endl;
}
return 0;
}


