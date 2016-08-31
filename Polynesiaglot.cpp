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
    freopen("C-large-practice.in","r",stdin);
    freopen("out.in", "w",stdout);
    int T;
    scanf("%d", &T);
    for (int run = 1; run <= T; ++run) {
        long long C, V , L;
        cin >> C >> V >> L;
        long long arr[L][2];
        arr[0][0] = C;
        arr[0][1] = V;
        for(int i = 1; i < L ; ++i){
            arr[i][0] = (C*arr[i-1][1])%mod;  // ending with C
            arr[i][1] = ((V*arr[i-1][0])%mod +  V*arr[i-1][1] )%mod;  // ending with V
        }
        cout<<"Case #"<<run<<": " <<arr[L-1][1]<<endl;
    }
    return 0;
}

