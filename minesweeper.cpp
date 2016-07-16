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
vector<string> v;
vector<vector<bool> > zero;
vector<vector<bool> > visit;
int n;
void bfs(int x, int y){
    queue<pair<int, int> >  q;
    q.push(make_pair(x,y));
    while(!q.empty()){
        pair<int, int> temp;
        temp = q.front();
        q.pop();
        int i = temp.first;
        int j =  temp.second;
        if(i-1 >= 0  && !visit[i-1][j] && v[i-1][j] != '*'){
            if(zero[i-1][j])
                q.push(make_pair(i-1,j));
            visit[i-1][j] = true;
        }
        if(i-1 >= 0  && j-1 >= 0  && !visit[i-1][j-1] && v[i-1][j-1] != '*'){
            if(zero[i-1][j-1])
                q.push(make_pair(i-1,j-1));
            visit[i-1][j-1] = true;
        }
          if(i-1 >= 0  && j+1 < n  && !visit[i-1][j+1] && v[i-1][j+1] != '*'){
            if(zero[i-1][j+1])
                q.push(make_pair(i-1,j+1));
            visit[i-1][j+1] = true;
        }
         if( j-1 >= 0  && !visit[i][j-1] && v[i][j-1] != '*'){
             if(zero[i][j-1] )
             q.push(make_pair(i,j-1));
            visit[i][j-1] = true;
        }
        if(  j+1  < n  && !visit[i][j+1] && v[i][j+1] != '*'){
             if(zero[i][j+1])
             q.push(make_pair(i,j+1));
            visit[i][j+1] = true;
        }
        if(i+1 < n  && j-1 >= 0  && !visit[i+1][j-1] && v[i+1][j-1] != '*'){
             if(zero[i+1][j-1])
             q.push(make_pair(i+1,j-1));
            visit[i+1][j-1] = true;
        }
        if(i +1  < n   && !visit[i+1][j] && v[i+1][j] != '*'){
              if(zero[i+1][j])
                q.push(make_pair(i+1,j));
            visit[i+1][j] = true;
        }
        if(i+1 < n && j+1 < n  && !visit[i+1][j+1] && v[i+1][j+1] != '*'){
              if(zero[i+1][j+1])
                q.push(make_pair(i+1,j+1));
            visit[i+1][j+1] = true;
        }
    }
    return ;
}
int main()
{
   freopen("A-small-practice.in","r",stdin);
    freopen("out.out", "w",stdout);
    int t;
    cin >> t;
    for(int tt = 1 ; tt <= t ;++tt) {
        cin >> n;
        v.resize(n);
        zero.resize(n);
        visit.resize(n);
        for(int i = 0; i < n ; ++i){
            cin >> v[i];
            zero[i].resize(n);
            visit[i].resize(n);
        }

    for(int i = 0; i<n ;++i)
            for(int j = 0; j < n ;++j) {
                visit[i][j] = false;
                zero[i][j] = false;

            }
        for(int i = 0; i<n ;++i)
            for(int j = 0; j < n ;++j){
                if(v[i][j] == '.'){
                        if(i-1 >= 0  && v[i-1][j] != '.')
                               continue;
                        if(i-1 >= 0  && j-1 >= 0  && v[i-1][j-1] != '.')
                               continue;
                        if(i-1 >= 0  && j+1 < n && v[i-1][j+1] != '.')
                              continue;
                        if( j-1 >= 0  && v[i][j-1] != '.')
                               continue;
                        if(j+1 < n && v[i][j+1] != '.')
                               continue;
                        if(i+1 < n  && j-1 >= 0  && v[i+1][j-1] != '.')
                                continue;
                        if(i+1 <n   && j+1 <  n && v[i+1][j+1] != '.')
                               continue;
                        if(i+1 < n  && v[i+1][j] != '.')
                          continue;
                        zero[i][j] = true;
                     }
        }
    int count = 0;
    for(int i = 0; i<n ;++i)
            for(int j = 0; j < n ;++j) {
                if( zero[i][j]  && !visit[i][j] ){
                     visit[i][j] = true;
                        bfs(i,j);
                        ++count;
                }
            }
     for(int i = 0; i< n ;++i)
            for(int j = 0; j < n ;++j)
                if( v[i][j] != '*'  && !visit[i][j])
                        ++count;
        cout<<"Case #"<<tt<<": " <<count<<endl;
}
    return 0;
}
