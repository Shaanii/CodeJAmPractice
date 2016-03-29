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
vector<  vector <int>   >  vrank;
vector<int>  vi;
vector<string> vs;
vector<string> vscopy;
vector<string> non_intersect( vector<string> b) {
    vector<string> str;
       /* for(int i = 0 ; i < b.size(); ++i) {
        cout<<b[i]<<" ";
    }
    cout<<"  yyy "<<endl; */
    sort(b.begin(), b.end());
    int i, j;
    for( i = 0 ,  j = 0; i < b.size() ; ) {
        if(vscopy[j] < b[i] ) {
            str.push_back(vscopy[j]);
            ++j;
        }
        else if(vscopy[j] > b[i])
            ++i;
        else  {
            ++i;
            ++j;
        }
    }
    for ( ; j < vscopy.size() ; ++j)
        str.push_back(vscopy[j]);
    return str;
}
void func( int maxrank, vector<vector<string>  >&res, vector<string> row ) {
        if( maxrank == 0) {
            res.push_back( non_intersect(row));
            return;
        }
        int price = INT_MAX;
        int kk = INT_MAX;
        if(row.size() > 0) {
            string bstr = row.back();
           // cout<< bstr<<endl;
            for(kk = 0; kk < vs.size() ; ++kk) {
                    if(vs[kk] == bstr)
                        break;
            }
            price = vi[kk];
        }
        for(int i = 0 ; i < vrank[maxrank].size() ; ++i) {
                 if( (vi[ vrank[maxrank][i]  ] < price)  &&   (vrank[maxrank][i]   < kk)   ) {
                     row.push_back(  vs[ vrank[maxrank][i] ]) ;
                     func( maxrank - 1, res, row );
                     row.pop_back();
                 }
            }
    }
int main () {
 freopen("B-large-practice.in","r",stdin);
 freopen("output.out", "w",stdout);
  int t;
  cin >> t;
  for(int xx = 1 ; xx <= t ; ++xx) {
    vs.clear();
    vi.clear();
        while(1) {
            string str;
            cin >> str;
            if(  (str[0] < 'a'  ||  str[0] > 'z' )   && str[0] != '_' ) {
                  vi.push_back(stoi(str) );
                break;
            }
            vs.push_back(str);
        }
        for(int i = 1 ; i < vs.size(); ++i) {
            int ii;
            cin >> ii;
            vi.push_back(ii);
        }
        int n = vi.size();
        vector<int> val(n);
        int maxval = 0;
        for(int i = 0 ; i < n ; ++i) {
            val[i] = 1;
            for(int j = i ; j >= 0 ; --j) {
                if( vi[j]   < vi[i] ) {
                    if(val[i]  < val[j] + 1) {
                        val[i] = val[j] + 1;
                    }
                }
            }
             maxval = max(maxval, val[i]);
        }
         /* for(int i = 0; i < val.size() ; ++i) {
            cout<< vi[i] <<"   "<<vs[i] << "  " << val[i] << endl;
        } */
    vrank.clear();
    vrank.resize(maxval + 1);
     for(int i = 0 ; i < n ; ++i)
        vrank[val[i]].push_back(i);
    vector<vector<string> >  res;
    vector<string> row;
    vscopy.clear();
    vscopy = vs;
    sort(vscopy.begin(), vscopy.end());
    func(maxval, res, row );
    sort(res.begin(), res.end());
  /* for(int i = 0 ; i < res.size() ; ++i) {
        for(int j = 0; j < res[i].size() ;++j )
            cout<< res[i][j] <<" ";
        cout<<endl;
    }  */
    cout<<"Case #"<<xx<<": ";
        for(int i = 0 ; i < res[0].size() ; ++i)
            cout<<res[0][i]<<" ";
    cout<<endl;
    }
return 0;
}


