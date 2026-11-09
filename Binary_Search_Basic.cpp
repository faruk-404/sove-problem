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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    int k;
    cin >> k;
    // auto ok = [&](ll mid) {
    //     if(a[mid]<k)
    //     return true;
    // };
    ll l = 0, r = n-1, mid, ans = 0;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (a[mid]==k) {
            cout << mid << nl;
            return;
        } else if(a[mid]<k) {
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    dbg(a);
    cout << -1 << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}