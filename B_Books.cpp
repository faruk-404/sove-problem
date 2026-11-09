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
#define nf cout << '\n'
#define ll long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(), v.end()
const int N = 3e5 + 5;

void solve() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    int ans = 0, l = 0,  sum = 0;
    for (int r = 0; r < n;r++){
        sum += a[r];
        while(sum>t){
            sum -= a[l];
            l++;
        }
        ans = max(ans, r - l + 1);
    }
        cout << ans << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--) solve();
    return 0;
}