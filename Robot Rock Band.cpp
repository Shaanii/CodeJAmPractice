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

int main(){
    freopen("B-large-practice.in","r",stdin);
    freopen("out.in", "w",stdout);
    int T;
    scanf("%d", &T);
    for (int run = 1; run <= T; ++run) {
            int n,k;
            cin >> n>> k;
            vector<int> x(n),y(n);
            for(int i = 0 ;i < n ; ++i)
                cin >> x[i];
            for(int i = 0 ;i < n ; ++i)
                cin >> y[i];
            map<int,int> mp;
            for(int i = 0; i <n ;++i)
                for(int j = 0 ;j < n ;++j)
                    mp[x[i]^y[j]]++;
             for(int i = 0 ;i < n ; ++i)
                cin >> x[i];
            for(int i = 0 ;i < n ; ++i)
                cin >> y[i];
            long long ans = 0LL;
            for(int i = 0; i <n ;++i)
                for(int j = 0 ;j < n ;++j)
                    ans = ans + mp[x[i]^y[j]^k];
            cout<<"Case #"<<run<<": " <<ans<<endl;
        }
    return 0;
}
