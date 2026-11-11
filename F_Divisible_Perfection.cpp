#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#define dbg_arr(...)
#define dbg_range(...)
#define dbg_grid(...)
#define dbg_time(...)
#endif


#define nl '\n'
#define nf cout<<'\n'
#define ll long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(),v.end()
const int N=3e5+5;


void solve(){
    int k;
    cin >> k;
    string s;
    cin >> s;
    k = s.size();
    if(k>=10){
        cn;
        return;
    }
    for (int i = 1; i <=k;i++){
        for (int j = i; j <= k;j++){       
            int n = stoll(s.substr(j - i, i));
            if(n%i!=0){
                cn;
                return;
            }
            // dbg(j - i, i, j, n);
        }
    }
    cy;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}