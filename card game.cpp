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
#include <iomanip>
#include<cmath>
#define ll long long
#define mod 1000000007
using namespace std;
map<string, int > mp;
void func(vector<int> &v, string str, int &ans, int &k){
    if(mp.find(str) != mp.end()){
        ans = min(ans, mp[str]);
        return;
    }
    int n = v.size();
    bool base = true;
    for(int i = 0 ; i <= n ; ++i){
        if(str[i] == '1'){
            int count = 0;
            int xx;
            int yy;
            for(int j = i + 1 ; j < n  && count < 2; ++j){
                    if(str[j] == '1' && count  == 0) {
                        xx = j;
                        count =1;
                    }
                    else if( str[j] == '1' && count  == 1){
                        yy = j;
                        count++;
                    }
            }
            if(count < 2)
                break;
            else if( v[xx] - v[i] == k  && v[yy] - v[xx] == k){
                base = false;
                string temp = str;
                temp[xx] = '0';
                temp[i] =  '0';
                temp[yy] = '0';
                func(v,temp,ans,k);
            }
        }
    }
    if(base){
        int ones = 0;
        for(int i = 0 ; i < str.length() ; ++i )
            if(str[i] == '1')
                ++ones;
        ans = min(ans,ones);
    }
    mp[str] =  ans;
    return;
}
int main()
{
    freopen("C-small-practice.in","r",stdin);
    freopen("output.out", "w",stdout);
    int t;
    cin >> t;
    std::cout << std::fixed;
    std::cout << std::setprecision(7);
    for(int tt = 1 ; tt <= t ;++tt){
        int n, k;
        cin>>n>>k;
        vector<int> v(n,0);
        string str;
        for(int i =0 ;i < n ; ++i){
            cin >> v[i];
            str = str+'1';
        }
        int ans = n;
        func(v,str,ans,k);
        cout<<"Case #" <<tt <<": "<<ans<<endl;
    }
   return 0;
}
