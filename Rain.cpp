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

int main(){
   // freopen("B-large-practice.in","r",stdin);
    //freopen("out.in", "w",stdout);
    int T;
    scanf("%d", &T);
    for (int run = 1; run <= T; ++run) {
       int R, C;
       cin >> R >> C;
       vector<vector<int> > v(R, vector<int>(C,0));
       vector<vector<int> > arr(R, vector<int>(C,INT_MAX));
       queue<pair<int, int> > wall;
       for(int i = 0 ; i < R ; ++i)
        for(int j = 0 ; j < C ; ++j){
            cin >> v[i][j];
            if( i == 0 || i == R-1 || j == 0 || j == C-1){
              wall.push(make_pair(i,j));
              arr[i][j] = -1;
            }
        }
        int dx[]={0,0,-1,1};
        int dy[]={-1,1,0,0};
        while(!wall.empty()){
            pair<int, int> temp;
            temp =  wall.front();
            wall.pop();
            queue<pair<int,int> > Rcubes;
            int val = v[temp.first][temp.second];
            Rcubes.push(make_pair(temp.first, temp.second));
            vector<vector<bool> > visited(R, vector<bool>(C, false) );
            visited[temp.first][temp.second] = true;
            while(!Rcubes.empty()){
                int x = Rcubes.front().first;
                int y = Rcubes.front().second;
                Rcubes.pop();
                for(int ii = 0 ; ii < 4 ; ++ii){
                        int a = x + dx[ii];
                        int b = y + dy[ii];
                        if( a <= 0  || a >= R-1 ||  b <= 0  || b >= C-1 ||  visited[a][b] )
                            continue;
                        else if( v[a][b] >  val ){
                            if(arr[a][b] != -1){
                                arr[a][b] = -1;
                                wall.push(make_pair(a,b));
                            }
                        }
                        else{
                            arr[a][b] = min(val, arr[a][b]);
                            Rcubes.push(make_pair(a,b));
                        }
                        visited[a][b] = true;
                    }
             }
        }
       int sum = 0;
       for(int i = 0 ; i < R ; ++i){
        for(int j = 0 ; j < C ; ++j){
            if(arr[i][j] != -1)
                sum += max(0, arr[i][j] -  v[i][j]);
        }
    }
       cout<<"Case #"<<run<<": " <<sum<<endl;
    }
    return 0;
}
