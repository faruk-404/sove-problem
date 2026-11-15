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
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    map<int,int> mp;
    for (auto i : a) mp[i]++;
    int ans = 0;
    for (auto [x, y] : mp) ans += min(y, 2);
    cout << ans << nl;
    vector<int> aa,bb;
    for(auto &[x,y]:mp){
        aa.push_back(x);
        y--;
    }
    for (auto [x, y] : mp){
        for (int i = 0; i < y;i++){
            bb.push_back(x);
        }
    }
    reverse(all(bb));
    for(auto i:aa)cout<<i<<' ';
    for (auto i : bb) cout << i << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}