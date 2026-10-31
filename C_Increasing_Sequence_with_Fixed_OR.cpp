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
    ll n;
    cin >> n;
    set<ll> st;
    st.insert(n);
    for (int i = 0; i <= __lg(n);i++){
        if (((n >> i) & 1)) st.insert((n & ~(1LL << i)));
    }
    if (st.find(0) != st.end()) st.erase(0);
    cout << st.size() << nl;
    for (auto& i : st) cout << i << ' ';
    cout << '\n';
    // dbg(st);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}