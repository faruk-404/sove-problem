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
    string s;
    cin >> s;
    multiset<char> ml;
    int n = s.size();
    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (isupper(s[i])) s[i] = s[i] + 32;

        if (ml.find(s[i]) != ml.end()) {
            mx = max((int)ml.size(), mx);
            ml.clear();
        }
        ml.insert(s[i]);
        mx = max((int)ml.size(), mx);
        // dbg(ml);
    }
    // dbg(s);
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