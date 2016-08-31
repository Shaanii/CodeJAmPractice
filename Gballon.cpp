using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include<limits.h>
#include <stack>
#include <list>
#include <map>
#include <set>
#define mod 1000000007
vector<int> v;
vector<pair<int,int> > pos;
map <pair<int,int>, float > mp;

void func (int i, int eng){
    if( i < 0)
        return;
    if(mp.find(make_pair(i,eng)  ) != mp.end() )
        return;
    int height = pos[i].second;
    int dist = pos[i].first;
    float val = INT_MAX;
    for(int j = 0; j <  v.size() ; ++j){
        if(dist * v[j]  > 0 )
            continue;
        float time  = abs(dist)*1.0 / abs(v[j]);
        int spent =  abs(height - j);
        if(spent >  eng)
            continue;
        func(i-1, eng - spent );
        if( mp[make_pair(i-1, eng-spent) ]   != INT_MAX)
            val = min(val,  max(time, mp[make_pair(i-1, eng-spent) ]  ) );
    }
    //cout<<i<<"  "<<eng<<"   "<< val<<endl;
    mp[make_pair(i,eng) ]  =  val;
    return;
}
int main(){
    freopen("B-large-practice.in","r",stdin);
    freopen("out.in", "w",stdout);
    int T;
    scanf("%d", &T);
    for (int run = 1; run <= T; ++run) {
         mp.clear();
        v.clear();
        pos.clear();
        int n,m,q;
        cin >> n >> m>> q;
        v.resize(m);
        for(int i =0; i < m ; ++i)
            cin >> v[i];
        pos.resize(n);
        for(int i = 0; i < n; ++i ){
            int x, y;
            cin >> x >> y;
            pos[i].first = x;
            pos[i].second = y;
        }
        sort(pos.begin(), pos.end());
        func(n-1,q);
        float ans  = mp[make_pair(n-1,q) ];
        if( ans >= INT_MAX)
            cout<<"Case #"<<run<<": " <<"IMPOSSIBLE"<<endl;
        else{
            int t1 = ans;
            float t2 =  ans - t1;
            if( t2 != 0.0)
                ++t1;
            cout<<"Case #"<<run<<": " <<t1<<endl;
        }

    }
    return 0;
}
