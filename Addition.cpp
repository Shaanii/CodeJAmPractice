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
   freopen("C-small-practice.in","r",stdin);
   freopen("output.out", "w",stdout);
    int t;
    cin >> t;
    for(int k = 1 ; k <= t ;++k){
        int n;
        cin >> n ;
        map< pair<string, string>, int > mp,valid;
        for(int i = 0; i < n;  ++i){
            string str;
            cin >> str;
            int k = (int)str.find('+', 0);
            string x = str.substr(0,k);
            str = str.substr(k+1);
            k =(int)str.find('=',0);
            string y = str.substr(0,k);
            str = str.substr(k+1);
            int z = atoi(str.c_str());
            mp[make_pair(x,y)] = z;
            valid[make_pair(x,y)] = z;
        }
        map< pair<string, string>, int > :: iterator it;
        for(it = mp.begin() ; it != mp.end() ; ++it) {
            map< pair<string, string>, int > :: iterator temp;
            temp = it;
            temp++;
            while(temp != mp.end()){
               vector<string> v(4);
                v[0] = it->first.first;
                v[1] = it->first.second;
                v[2] = temp->first.first;
                v[3] = temp->first.second;
                int sum = 0;
                for(int xx = 0 ; xx < 4 ; ++xx)
                    for(int yy = xx+1 ; yy < 4 ; ++yy){
                         string a = v[xx];
                         string b = v[yy];
                         string c="",d="" ;
                         int index = -1;
                         for(int ii = 0 ; ii < 4 ; ++ii)
                            if(ii != xx && ii != yy)
                                index = ii;
                       if(index != -1)
                            c = v[index];
                        int zz = index;
                        index = -1;
                        for(int ii = 0 ; ii < 4 ; ++ii)
                            if( ii != xx && ii !=  yy && ii != zz)
                                index = ii;
                       if(index != -1)
                            d = v[index];
                        if(c == "" || d == "")
                            continue;
                          sum = it->second + temp->second;
                        if( valid.find(make_pair(a,b) ) != valid.end() ){
                                sum = sum - valid[make_pair(a,b)];
                                valid[make_pair(c,d)] = sum;
                        }
                        else if(valid.find(make_pair(b,a) ) != valid.end()  ){
                                sum = sum - valid[make_pair(b,a)];
                                valid[make_pair(c,d)] = sum;
                        }
                }
             ++temp;
            }
        }
        int q;
        cin >> q;
        cout<<"Case #" <<k <<":"<<endl;
        while(q--){
            string str;
            cin >> str;
            int k = (int)str.find('+', 0);
            string x = str.substr(0,k);
            str = str.substr(k+1);
            string y = str.substr(0,k);
           if(valid.find(make_pair(x,y)) != valid.end())
            cout<<x<<"+"<<y<<"="<<valid[make_pair(x,y)]<<endl;
           else if(valid.find(make_pair(y,x)) != valid.end())
             cout<<x<<"+"<<y<<"="<<valid[make_pair(y,x)]<<endl;
        }

    }
   return 0;
}
