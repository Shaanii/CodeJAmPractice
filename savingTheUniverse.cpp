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
int main () {
freopen("A-large-practice.in","r",stdin);
freopen("output.out", "w",stdout);
 int t;
 cin >> t;
for(int i = 1 ; i <= t ; ++i) {
   int n;
    cin >> n;
    cin.ignore();
   set<string>  ss;
   for(int j = 0; j < n ; ++j) {
        string str;
         std::getline(std::cin, str);
   //     cout<< "j is  " <<j <<"  "<<str<<endl;
        ss.insert(str);
   }
   int k;
   cin >> k;
   cin.ignore();
  // cout<<" k is  "<<k<<endl;
   int ans = 0;
   set<string> temp = ss;
   while(k--) {
   string str;
  //cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
         std::getline(std::cin, str);
   //cout<<str<<endl;
    if(temp.find(str) == temp.end())
        continue;
    else if( temp.size() > 1)
        temp.erase(str);
    else {
        ++ans;
        temp.clear();
        temp = ss;
        temp.erase(str);
    }
    //cout<<"yoyo "<<endl;
   }
   cout<<"Case #"<<i<<": "<<ans<<endl;
   //cout<<"hey  "<<endl;
 }
return 0;
}


