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
int n;
int main()
{
    freopen("B-large-practice-2.in","r",stdin);
    freopen("out.out", "w",stdout);
    int t;
    cin >> t;
    for(int tt = 1 ; tt <= t ;++tt) {
        long long k,v;
        cin >> k >> v;
        long long ans = 0LL;
        for( long long i = 0 ; i <= k ; ++i ){
                long long temp = 0LL;
                long long low, high;
                low = max(0LL, i - v);
                high = min(k, i+v);
                for(int j = low ; j <= high ; ++j)
                    temp += min(high,j+v) - max(low,j-v) + 1;
                ans += temp;
                if(i == v  && i+1  <=  k-v){
                  ans += ans;
                  ans += (temp)*(k-v-i-1);
                  break;
                }
        }
        cout<<"Case #"<<tt<<": "<<ans<<endl;
    }
	return 0;
}

/* freopen("A-small-practice.in","r",stdin);
    //freopen("out.out", "w",stdout);
    int t;
    cin >> t;
    for(int tt = 1 ; tt <= t ;++tt) {
        int n;
        cin >> n;
        for(int i = 0; i< n ; ++i){
            int j, w;
            cin >> j >> w;
            for(int k = 1 ; k < j ; ++k){



            }
        }
        cout<<"Case #"<<tt<<": " <<count<<endl;
    }
 */
    //int arr[] = { 1, 2, -2, 4, -4};
    //vector<int> A(arr, arr + sizeof(arr)/sizeof(int));
    //cout<< minWindow("ADOBECODEBANC", "ABC");



    // cout<<simplifyPath("/bku/./zjy/mia/cfr/../jss/sdg/wks/.././././../lyf/jzt/bxk/qfd/gpz/ypt/./nzh/xcn/../../../exk/../xoi/././snn/../../dbb/ayw/jhv/././evi/")<<endl;
   // std::cout << std::fixed;
    //std::cout << std::setprecision(7);
