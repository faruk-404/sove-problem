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
    string s;
    cin >> s;
    string t = s;
    reverse(all(t));
    if (t == s) {
        cout << 0 << nl;
        return;
    }
    sort(all(t));
    int ans = t[n - 1] - t[0];
    int cnt = 0;
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        cnt += abs(s[j] - s[i]);
    }

    int mx = 0;
    for (char c : s) mx = max(mx, c - 'a');

    t = s;
    int ans2 = 0;
    int ans11 = min(ans, cnt);
    for (int cc = mx; cc >= 1; cc--) {
        bool o = false;
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            if (t[i] != t[j] && (t[i] - 'a' == cc || t[j] - 'a' == cc)) {
                o = true;
                break;
            }
        }
        if (!o) continue;
        for (int i = 0; i < n; i++)
            if (t[i] - 'a' == cc) t[i]--;
        ans2++;
        string tt = t;
        reverse(all(tt));
        if (tt == t) {
            ans11 = min(ans11, ans2);
            break;
        }
    }
    cout << ans11 << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}