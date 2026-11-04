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
    vector<ll> od, ev;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        sum += x;
        if (i % 2 == 0) od.push_back(x);
        else ev.push_back(x);
    }
    sort(od.begin(), od.end());
    sort(ev.begin(), ev.end());
    for (int j = 0; j < (int)min(od.size(), ev.size()); j++) {
        ll s = od[j] + ev[j];
        if (s < 0) sum -= 2 * s;
        else break;
    }
    cout << sum << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}