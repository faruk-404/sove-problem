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
    int l, r;
    cin >> l >> r;
    if(l==r){
        cout << 0 << nl;
        return;
    }
    if(r<0 || l>0){
        cout << r - l << nl;
        return;
    }
    cout <<max( (abs(abs(r) - abs(l)) - 1),0) << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}