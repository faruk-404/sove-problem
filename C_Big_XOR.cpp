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
    int n;
    cin >> n;
    int xo = 0;
    for (int i = 1; i <= n;i++){
        xo ^= (i * 2);
        for (int j = __lg(i); j>=0;j--){
            cout<<(((i >> j) & 1) ? 1 : 0);
        }
        nf;
    }
    
    int x;
    cin >> x;
    for (int j = __lg(x); j >= 0; j--) {
        cout << (((x>> j) & 1) ? 1 : 0);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}