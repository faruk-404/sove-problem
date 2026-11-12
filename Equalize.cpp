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
    a.push_back(0);
    sort(all(a));
    a.erase(unique(a.begin(), a.end()), a.end());
    dbg(a);
    vector<int> def;
    for (int i = 1; i < a.size(); i++)
        def.push_back(a[i] - a[i - 1]);

    for (int i = 1; i < def.size(); i++)
        def[i] += def[i - 1];
    dbg(def);
    int mx = 1;
    for (int i = 0; i < def.size(); i++) {
        if ((def[i] - n) <= 0) mx = max(mx, i + 1);
        else {
            auto it = lower_bound(def.begin(), def.end(), ((def[i] - n) + 1));
            int x = it - def.begin();
            mx = max(mx, i - x + 1);
        }
    }
    cout << mx << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}