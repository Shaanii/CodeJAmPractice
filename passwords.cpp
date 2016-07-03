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
long long power(long long x, long long y , long long m){
    if(y==0LL)
        return 1L;
    if( y==1LL)
        return x%mod;
   ll xx =  power(x, y/2LL ,m);
    if(y%2LL)
        return (((xx*xx)%mod)*x)%mod;
    else
         return (xx*xx)%mod;
}
int main()
{
   freopen("A-large-practice.in","r",stdin);
   freopen("output.out", "w",stdout);
    int t;
    cin >> t;
    vector<long long> fact(101,1L),infact(101,1L);
    for(long long i = 2LL; i <= 100LL ; ++i){
        fact[i] = (i*fact[i-1])%mod;
        infact[i] = power(fact[i], mod-2LL, mod);
    }
    for(int k = 1 ; k <= t ;++k){
        long long n, m;
        cin>> m >> n;
        long long ans = 0LL;
        for(long long i = 0; i < m ; ++i){
           long long val = 1LL;
            val = (val*fact[m])%mod;
            val = (val*infact[i])%mod;
            val = (val*infact[m-i])%mod;
            val = (val*power(m-i,n, mod))%mod;
            if(i%2LL)
                ans -= val;
            else
                ans += val;
            if(ans<0)
                ans = ans+mod;
            ans = ans%mod;
        }
        cout<<"Case #" <<k <<": "<<ans<<endl;
    }
   return 0;
}


