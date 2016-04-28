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
/* int gcd (int a, int b) {
    if(a == 0)
        return b;
    return gcd( b%a, a);
} */
int main () {
    freopen("B-large-practice.in","r",stdin);
    freopen("output.out", "w",stdout);

  //  cin >> n;
 //   cin.ignore();
   //      std::getline(std::cin, str);
    int tc,turn, ta, tb;
    cin >> tc;
    for(int t = 1 ; t <= tc ; ++t) {
        cin >> turn >> ta >> tb;
        vector<vector<int> > va(24, vector<int>(60, 0) ), vb(24, vector<int>(60, 0)), da(24, vector<int>(60, 0)), db(24, vector<int>(60, 0));
        for(int i = 0; i < ta; ++i) {
            string dept, arr;
            cin >> dept;
            cin >> arr;
            int hr, mins;
            hr =  (dept[0]-'0') * 10 + (dept[1] - '0');
            mins = (dept[3]-'0') * 10 + (dept[4] - '0');
            da[hr][mins]++;
            hr =  (arr[0]-'0') * 10 + (arr[1] - '0');
            mins = (arr[3]-'0') * 10 + (arr[4] - '0');
            mins = mins + turn;
            if(mins  >= 60){
               ++hr;
               mins = mins%60;
               hr = hr%24;
               if(hr == 0)
                continue;
            }
            vb[hr][mins]++;
        }
         for(int i = 0; i < tb ; ++i){
            string dept, arr;
            cin >> dept;
            cin >> arr;
            int hr, mins;
            hr =  (dept[0]-'0') * 10 + (dept[1] - '0');
            mins = (dept[3]-'0') * 10 + (dept[4] - '0');
            db[hr][mins]++;
            hr =  (arr[0]-'0') * 10 + (arr[1] - '0');
            mins = (arr[3]-'0') * 10 + (arr[4] - '0');
            mins = mins + turn;
            if(mins >= 60){
               ++hr;
               mins = mins%60;
               hr = hr%24;
               if(hr == 0)
                continue;
            }
            va[hr][mins]++;
        }
        int ResA = 0, ResB = 0;
        int curr = 0;
        for(int i = 0 ; i < 24 ; ++i)
            for(int j = 0 ; j < 60 ; ++j) {
                curr += va[i][j];
                if(da[i][j] > 0 )
                if(curr >= da[i][j]) {
                    curr -= da[i][j];
                }
                else {
                    ResA += (da[i][j] - curr);
                    curr = 0;
                }
            }
        curr = 0;
        for(int i = 0 ; i < 24 ; ++i)
            for(int j = 0 ; j < 60 ; ++j) {
                curr += vb[i][j];
                if(curr >= db[i][j]) {
                    curr -= db[i][j];
                }
                else {
                    ResB += (db[i][j] - curr);
                    curr = 0;
                }
            }
        cout<<"Case #"<<t<<": "<<ResA<<" "<<ResB<<endl;
    }
//printf("Case #%d: %d %d\n",t,trainA,trainB);
// cout<<"Case #"<<t<<": "<<ResA<<" "<<ResB<<endl;
    return 0;
}
