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
    int h, w, n, q;
    cin >> h >> w >> n >> q;
    map<int, int> mpr, mpc;
    for (int i = 0; i< n;i++){
        int u, v;
        cin >> u >> v;
        mpr[u]++;
        mpc[v]++;
    }
    int yy = 0;
    for(auto &[x,y]:mpr){
        yy += y;
        y = yy;
    }
    yy = 0;
    for (auto& [x, y] : mpc) {
        yy += y;
        y = yy;
    }
    mpc[0] = 0;
    mpr[0] = 0;
    for (int i = 0; i < q;i++){
        int k, u, v;
        cin >> k >> u >> v;
        if(k==1){
        
            int x = (--(mpr.lower_bound(v + 1)))->second;
            int y = (--(mpr.lower_bound(u)))->second;
            // dbg(x, y);
            cout << x - y << nl;
        }
        else{
            int x = (--(mpc.lower_bound(v + 1)))->second;
            int y = (--(mpc.lower_bound(u)))->second;
            // dbg(x, y);
            cout << x - y << nl;
        }
    }
    // dbg(mpr);
    // dbg(mpc);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}