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

int main()
{
    freopen("C-small-practice-1.in","r",stdin);
    freopen("out.out", "w",stdout);
    int t;
    cin >> t;
    for(int tt = 1 ; tt <= t ; ++tt) {
       int n;
       cin >> n;
       vector<string> v(n);
       char c;
       c = getchar();
       for(int i =0 ; i < n ; ++i){
           while( (c=getchar()) != '\n')
             v[i].push_back(c);
       }
       int curr = 1;
       int prev = 0;
       int ans  = 0;
       while(curr < n){
        if(v[prev] > v[curr])
            ++ans;
       else
            prev = curr;
        ++curr;
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
