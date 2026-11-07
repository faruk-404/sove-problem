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
    int n, k;
    cin >> n>>k;    vector<int> a(n);
    for (auto& i : a) cin >> i;
    sort(all(a));
    int cnt = 0;
    int sum = 0;
    for (int i = 0; i < n-1;i++){
        sum += a[i];
        if (sum <= (a[i + 1] * i)) cnt++;
    }
    if (cnt >= k){ cy;
    for(auto i:a)cout<<i<<' ';
    cout << '\n';
    }
    else cn;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}