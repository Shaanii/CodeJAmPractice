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
string str , rstr ;
char face = 'S';
map<pair<int, int> , int> mp;
int x, y;
 void fillMap(string str) {
    for( int i = 0; i < str.length() ; ++i ) {
    //cout<< "char  "<<str[i]<<endl;
        if( str[i] == 'W') {
                if( face == 'S') {
                       mp[make_pair(x,y)]= mp[make_pair(x,y)] | (1<<1);
                       if( i != str.length() - 1)
                        mp[make_pair(x+1,y)]= mp[make_pair(x+1,y)] | (1);
                         //cout<<"face  "<<face  << "   "  << x <<" "<<y <<" "<<mp[make_pair(x,y)]<<endl;
                        ++x;
                }
                 if( face == 'N'){
                        mp[make_pair(x,y)] = mp[make_pair(x,y)] | (1);
                        if( i != str.length() - 1)
                            mp[make_pair(x-1,y)] = mp[make_pair(x-1,y)] | (1<<1);
                        // cout<<"face  "<<face  << "   "  << x <<" "<<y <<" "<<mp[make_pair(x,y)]<<endl;
                        --x;
                 }
                if( face == 'E') {
                       mp[make_pair(x,y)] = mp[make_pair(x,y)] | (1<<3);
                         if( i != str.length() - 1)
                            mp[make_pair(x,y+1)] = mp[make_pair(x,y+1)] | (1<<2);
                       //cout<<"face  "<<face  << "   "  << x <<" "<<y <<" "<<mp[make_pair(x,y)]<<endl;
                        ++y;
                }
                if(face =='W') {
                        mp[make_pair(x,y)] = mp[make_pair(x,y)] | (1<<2);
                        if( i != str.length() - 1)
                            mp[make_pair(x,y-1)] = mp[make_pair(x,y-1)] | (1<<3);
                       //  cout<<"face  "<<face  << "   "  << x <<" "<<y <<" "<<mp[make_pair(x,y)]<<endl;
                        --y;
                }
            }
        else if( str[i] == 'R') {
                  if( face == 'S')
                    face = 'W';
                 else if( face == 'N')
                    face = 'E';
                 else if( face == 'E')
                    face = 'S';
                else if(face =='W')
                    face = 'N';
                //cout<<" change dir "<<face <<endl;
        }
        else if( str[i] == 'L') {
                  if( face == 'S')
                    face = 'E';
                 else if( face == 'N')
                    face = 'W';
                 else if( face == 'E')
                    face = 'N';
                else if(face =='W')
                    face = 'S';
                 //    cout<<" change dir "<<face <<endl;
        }
}
}

int main () {
freopen("B-small-practice.in","r",stdin);
freopen("output.out","w",stdout);
  int t;
  cin >> t;
  for(int xx = 1 ; xx <= t ; ++xx) {
    x= 0;
    y = 0;
    mp.clear();
    cin>> str;
    cin >> rstr;
    str = str.substr(1);
    rstr = rstr.substr(1);
    face = 'S';
    //cout<< x<<" " <<y <<endl;
    fillMap(str);
    if( face == 'N') {
        ++x;
        face = 'S';
    }
      if( face == 'S') {
        face = 'N';
            --x;
        }
      if( face == 'E') {
        face = 'W';
        --y;
    }
      if( face == 'W') {
        face = 'E';
        ++y;
        }
        //cout<< " reverse starts  " << x <<" "<<y <<endl;
        // cout<<" change dir "<<face <<endl;
        //cout<< "called"  <<endl;
    fillMap(rstr);
    cout<< "Case #"<< xx <<": "<<endl;
    int  prev = mp.begin()->first.first;
    for( auto it = mp.begin(); it != mp.end() ;++it) {
       int  x =  it->first.first;
       int y  =  it->first.second;
       if( x != prev) {
        prev = x;
        cout<<endl;
       }
       int val = it->second ;
       if( val <10)
        cout<<val;
        else {
            char aa;
            aa =  'a' + (val-10);
            cout<<aa ;
        }
    }
cout<<endl;
}

return 0;
}


