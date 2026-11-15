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

ll bigmod(ll a,ll b,ll mod){
    ll result=1;
    a%=mod;
    while(b>0){
        if(b&1) result=(result*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return result;
}
void solve(){
    ll a, b, c;
    cin >> a >> b >> c;
    ll mod = 1e9 + 7;
    ll ans = bigmod(a%mod, bigmod(b,c,mod-1)%mod,mod)%mod;
    cout << ans << nl;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}