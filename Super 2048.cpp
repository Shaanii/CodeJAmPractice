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

void moveright( vector<int> &v) {
    int n = v.size();
    vector<bool> merge(n, false);
    for(int i = n-2; i >= 0; --i){
        if(v[i] == 0)
         continue;
        int j= i+1;
        int temp = i;
        while( j < n && v[j] == 0)
            ++j;
        if( j < n && merge[j] == false  && (v[i] == v[j])  ){
                v[j]=v[i]+v[i];
                v[i] = 0;
                merge[j] = true;
        }
        else{
            v[j-1] = v[i];
            if( j-1  != i)
            v[i] = 0;
        }
    }
}
void moveleft( vector<int> &v) {
    int n = v.size();
    vector<bool> merge(n, false);
    for(int i = 1 ; i < n; ++i){
        if(v[i] == 0)
         continue;
        int j= i-1;
        int temp = i;
        while( j >= 0 && v[j] == 0)
            --j;
        if( j>=0 && merge[j] == false  && (v[i] == v[j])  ){
                v[j]=v[i]+v[i];
                v[i] = 0;
                merge[j] = true;
        }
        else{
            v[j+1] = v[i];
              if( j+1  != i)
            v[i] = 0;
        }
    }
}
int main()
{
   freopen("B-large-practice.in","r",stdin);
   freopen("output.out", "w",stdout);
    int t;
    cin >> t;
    for(int k = 1 ; k <= t ;++k){
        int n;
        cin >> n;
        string str;
        cin >> str;
        vector<vector<int> > v(n,vector<int>(n,0));
        for(int i = 0 ; i< n ;++i)
            for(int  j = 0 ; j < n; ++j)
                cin >> v[i][j];
        if(str == "up"){
            for(int  j =0 ; j < n; ++j){
                  vector<int> temp ;
                for(int  i =0 ; i < n; ++i)
                    temp.push_back(v[i][j]);
                 moveleft(temp);
                for(int  i =0 ; i < n; ++i)
                    v[i][j] = temp[i];
            }
        }
        else if(str == "down"){
            for(int  j =0 ; j < n; ++j){
                  vector<int> temp ;
                for(int  i =0 ; i < n; ++i)
                    temp.push_back(v[i][j]);
                 moveright(temp);
                for(int  i =0 ; i < n; ++i)
                    v[i][j] = temp[i];
            }
        }
        else if(str == "left"){
                 for(int  i =0 ; i < n; ++i){
                  vector<int> temp ;
                for(int  j =0 ; j < n; ++j)
                    temp.push_back(v[i][j]);
                 moveleft(temp);
                for(int  j =0 ; j < n; ++j)
                    v[i][j] = temp[j];
            }
        }
        else {
            for(int  i =0 ; i < n; ++i){
                  vector<int> temp ;
                for(int  j =0 ; j < n; ++j)
                    temp.push_back(v[i][j]);
                 moveright(temp);
                for(int  j =0 ; j < n; ++j)
                    v[i][j] = temp[j];
            }
        }
        cout<<"Case #" <<k <<":"<<endl;
          for(int i = 0 ; i< n ;++i){
            for(int  j =0 ; j < n; ++j)
                cout << v[i][j]<<" ";
            cout<<endl;
            }
    }

   return 0;
}
