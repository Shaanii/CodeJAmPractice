#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<queue>
#include<map>
#include<stack>
#include<vector>
#include<ctime>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long
#define mod 1000000007
using namespace std;

int main()
{
   freopen("D-large-practice.in","r",stdin);
   freopen("output.out", "w",stdout);
    int t;
    cin >> t;
    for(int k = 1 ; k <= t ;++k){
        int n,m;
        cin >> n >> m ;
        vector<int> tiles(n);
        for(int i = 0 ; i < n ; ++i)
            cin >> tiles[i];
        sort(tiles.begin(), tiles.end());
        reverse(tiles.begin(), tiles.end());
        queue<pair<int, int> > q;
        int count = 0;
        bool flag;
        while(1){
            flag = true;
            for(int i = 0 ; i < n ;++i)
                if(tiles[i] >= 0)
                    flag = false;
            if(flag)
                break;
            q.push(make_pair(m,m));
            ++count;
            while(!q.empty()){
                 pair<int, int> p = q.front();
                 q.pop();
                 int len = max(p.first, p.second);
                 int wid = min(p.first, p.second);
                 int side = min(len,wid);
                 for(int i = 0 ; i < n ;++i){
                    if( tiles[i] >= 0  &&  ( (1 << tiles[i]) <= side ) ){
                        side = min((1 << tiles[i]), side);
                        tiles[i] = -1;
                        if( wid-side > 0)
                            q.push(make_pair(side,wid-side));
                        if(len-side > 0)
                            q.push(make_pair(side,len-side));
                        if(len - side > 0 && wid-side > 0)
                            q.push(make_pair(len -side,wid-side));
                        break;
                    }
                }
            }
        }
        cout<<"Case #" <<k <<": "<<count<<endl;
    }
   return 0;
}

